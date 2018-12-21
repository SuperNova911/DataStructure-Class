#include "Hash.h"
#include <string.h>

int strHashFunc(const char *key)
{
	char *str = (char *)key;
	unsigned int hashVal = 0;

	for (hashVal = 0; *str; str++)
	{
		hashVal = *str + (hashVal << 5) - hashVal;
	}

	return hashVal;
}

void Hash::Create(int tableSize)
{
	size = tableSize;
	table = new HashNptr[size];
	for (int index = 0; index < size; index++)
	{
		table[index] = new HashNode;
		table[index]->Data.Key.clear();
		table[index]->Data.count = 0;
		table[index]->next = NULL;
	}
}

int Hash::Insert(const char * key)
{
	int hashValue = (strHashFunc(key) % size + size) % size;

	HashNptr targetNode = table[hashValue];
	while (true)
	{
		if (targetNode->Data.Key.empty())
		{
			targetNode->Data.Key = key;
			targetNode->Data.count = 1;
			return 0;
		}
		else if (targetNode->Data.Key == key)
		{
			return -1;
		}
		else if (targetNode->next == NULL)
		{
			targetNode->next = new HashNode;
			targetNode = targetNode->next;

			targetNode->Data.Key = key;
			targetNode->Data.count = 1;
			targetNode->next = NULL;
			return 0;
		}
		else
		{
			targetNode = targetNode->next;
		}
	}
}

HashNptr Hash::Search(const char * key)
{
	int hashValue = (strHashFunc(key) % size + size) % size;

	HashNptr targetNode = table[hashValue];
	while (targetNode != NULL)
	{
		if (targetNode->Data.Key == key)
			return targetNode;
		else
			targetNode = targetNode->next;
	}

	return NULL;
}

void Hash::Update(const char * key)
{
	int hashValue = (strHashFunc(key) % size + size) % size;

	if (table[hashValue]->Data.Key.empty())
	{
		table[hashValue]->Data.Key = key;
		table[hashValue]->Data.count = 1;
	}
	else
	{
		HashNptr targetNode = table[hashValue];
		while (true)
		{
			if (targetNode->Data.Key == key)
			{
				targetNode->Data.count++;
				return;
			}
			else if (targetNode->Data.Key.empty())
			{
				targetNode->Data.Key = key;
				targetNode->Data.count = 1;
			}
			else if (targetNode->next == NULL)
			{
				targetNode->next = new HashNode;
				targetNode = targetNode->next;

				targetNode->Data.Key = key;
				targetNode->Data.count = 1;
				targetNode->next = NULL;
				return;
			}
			else
			{
				targetNode = targetNode->next;
			}
		}
	}
}

void Hash::Delete(const char * key)
{
	int hashValue = (strHashFunc(key) % size + size) % size;

	HashNptr targetNode = table[hashValue];
	while (targetNode != NULL)
	{
		if (targetNode->Data.Key == key)
		{
			HashNptr nextNode = targetNode->next;
			if (nextNode != NULL)
			{
				targetNode->Data.Key = nextNode->Data.Key;
				targetNode->Data.count = nextNode->Data.count;
				targetNode->next = nextNode->next;

				delete nextNode;
			}
			else
			{
				targetNode->Data.Key.clear();
				targetNode->Data.count = 0;
			}
			return;
		}
		else
		{
			targetNode = targetNode->next;
		}
	}

	return;
}

void Hash::Save(const char * fileName)
{
	remove(fileName);

	FILE *file;
	file = fopen(fileName, "w");
	if (file == NULL)
	{
		printf("Cannot open file, file name: '%s'\n", fileName);
		return;
	}

	HashNptr targetNode;
	char buffer[512];
	for (int index = 0; index < size; index++)
	{
		targetNode = table[index];
		while (targetNode != NULL)
		{
			sprintf(buffer, "%d %d %s\n", index, targetNode->Data.count, targetNode->Data.Key.c_str());
			fputs(buffer, file);

			targetNode = targetNode->next;
		}
	}
	fclose(file);
}

void Hash::Open(const char * fileName)
{
	FILE *file;
	file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("Cannot open file, file name: '%s'\n", fileName);
		return;
	}

	int index = -1;
	int newIndex;
	HashNptr targetNode = table[0];
	char buffer[512];
	char *token;
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';

		if ((token = strtok(buffer, " ")) == NULL)
		{
			cout << "잘못된 입력파일 포맷" << endl;
			fclose(file);
			return;
		}
		newIndex = atoi(token);

		if (index == newIndex)
		{
			targetNode->next = new HashNode;
			targetNode = targetNode->next;
		}
		else if (newIndex > size)
		{
			printf("해시 테이블이 너무 작습니다, 최소: '%d'이상\n", newIndex);
			fclose(file);
			return;
		}
		else
		{
			index = newIndex;
			targetNode = table[index];
		}

		if ((token = strtok(NULL, " ")) == NULL)
		{
			cout << "잘못된 입력파일 포맷" << endl;
			fclose(file);
			return;
		}
		targetNode->Data.count = atoi(token);

		if ((token = strtok(NULL, " ")) == NULL)
		{
			targetNode->Data.Key.clear();
		}
		else
		{
			targetNode->Data.Key = token;
		}

		targetNode->next = NULL;
	}
	fclose(file);
}

void Hash::Rehash(int newTableSize)
{
	HashNptr *newTable = new HashNptr[newTableSize];
	for (int index = 0; index < newTableSize; index++)
	{
		newTable[index] = new HashNode;
		newTable[index]->Data.Key.clear();
		newTable[index]->Data.count = 0;
		newTable[index]->next = NULL;
	}

	int hashValue;
	HashNptr targetNode, newTableNode, nextNode;
	for (int index = 0; index < size; index++)
	{
		targetNode = table[index];
		while (targetNode != NULL)
		{
			hashValue = (strHashFunc(targetNode->Data.Key.c_str()) % newTableSize + newTableSize) % newTableSize;

			newTableNode = newTable[hashValue];
			while (true)
			{
				if (newTableNode->Data.Key.empty())
				{
					newTableNode->Data.Key = targetNode->Data.Key;
					newTableNode->Data.count = targetNode->Data.count;

					nextNode = targetNode->next;
					if (nextNode != NULL)
					{
						targetNode->Data.Key = nextNode->Data.Key;
						targetNode->Data.count = nextNode->Data.count;
						targetNode->next = nextNode->next;

						delete nextNode;
					}
					else
					{
						delete targetNode;
						targetNode = NULL;
					}
					break;
				}
				else if (newTableNode->next == NULL)
				{
					newTableNode->next = new HashNode;
					newTableNode = newTableNode->next;

					newTableNode->Data.Key = targetNode->Data.Key;
					newTableNode->Data.count = targetNode->Data.count;
					newTableNode->next = NULL;

					nextNode = targetNode->next;
					if (nextNode != NULL)
					{
						targetNode->Data.Key = nextNode->Data.Key;
						targetNode->Data.count = nextNode->Data.count;
						targetNode->next = nextNode->next;

						delete nextNode;
					}
					else
					{
						delete targetNode;
						targetNode = NULL;
					}
					break;
				}
				else
				{
					newTableNode = newTableNode->next;
				}
			}
		}
	}

	delete table;
	table = newTable;
	size = newTableSize;
}