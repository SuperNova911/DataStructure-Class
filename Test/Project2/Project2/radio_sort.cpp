#include <iostream>
#include <string.h>
#include <string>

using namespace std;

void countingsort(string list[], int size, int k)
{
	string *table = new string[size];

	int *c = new int[257];
	for (int index = 0; index < 257; index++)
	{
		c[index] = 0;
	}

	int position;
	for (int index = 0; index < size; index++)
	{
		if (k < list[index].size())
		{
			position = list[index][k] + 1;
		}
		else
		{
			position = 0;
		}

		c[position]++;
	}

	for (int index = 1; index < 257; index++)
	{
		c[index] += c[index - 1];
	}

	for (int index = size - 1; index >= 0; index--)
	{
		if (k < list[index].size())
		{
			position = list[index][k] + 1;
		}
		else
		{
			position = 0;
		}

		table[c[position] - 1] = list[index];
		c[position]--;
	}

	for (int index = 0; index < size; index++)
	{
		list[index] = table[index];
	}

	delete[] table;
	delete[] c;
}

void countingsort2(string list[], int size, int k)
{
	string *table = new string[size];
	int *c = new int['z' - 'a' + 2];
	memset(c, 0, sizeof(int) * ('z' - 'a' + 2));

	int position;
	for (int index = 0; index < size; index++)
	{
		if (list[index].size() < k + 1)
		{
			position = 0;
		}
		else
		{
			position = list[index][k] - 'a' + 1;
		}

		c[position]++;
	}

	for (int index = 1; index < 'z' - 'a' + 2; index++)
	{
		c[index] += c[index - 1];
	}

	for (int index = size - 1; index >= 0; index--)
	{
		if (list[index].size() < k + 1)
		{
			position = 0;
		}
		else
		{
			position = list[index][k] - 'a' +1;
		}

		table[c[position] - 1] = list[index];
		c[position]--;
	}

	for (int index = 0; index < size; index++)
	{
		list[index] = table[index];
	}

	delete[] table;
	delete[] c;
}

void radixSort(string list[], int size)
{
	int max = list[0].size();
	for (int index = 0; index < size; index++)
	{
		if (list[index].size() > max)
		{
			max = list[index].size();
		}
	}

	for (int k = max; k > 0; k--)
	{
		countingsort(list, size, k - 1);
	}
}

void radixSort2(string list[], int size)
{
	int max = list[0].size();
	for (int index = 0; index < size; index++)
	{
		if (list[index].size() > max)
		{
			max = list[index].size();
		}
	}

	for (int k = 0; k < max; k++)
	{
		countingsort2(list, size, k);
	}
}

int main()
{
	const char *INPUT = "tokens.txt";
	const char *OUTPUT = "tokens.sorted";

	FILE *file;
	file = fopen(INPUT, "r");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", INPUT);
		return 0;
	}

	int lineNumber = 0;
	char buffer[64];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		lineNumber++;
	}
	fclose(file);

	file = fopen(INPUT, "r");
	string *tokenList = new string[lineNumber];
	for (int index = 0; fgets(buffer, sizeof(buffer), file) != NULL; index++)
	{
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';

		tokenList[index] = buffer;
	}
	fclose(file);

	radixSort2(tokenList, lineNumber);

	remove(OUTPUT);
	file = fopen(OUTPUT, "w");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", OUTPUT);
		return 0;
	}

	for (int index = 0; index < lineNumber; index++)
	{
		sprintf(buffer, "%s\n", tokenList[index].c_str());
		fputs(buffer, file);
	}
	fclose(file);

	return 0;
}