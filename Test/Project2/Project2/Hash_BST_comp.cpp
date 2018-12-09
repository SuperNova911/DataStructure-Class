#include "Hash.h"
#include "BST.h"
#include <iostream>
#include <string.h>
#include <stack>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

double getdtime()
{
	struct timeval tv = { 0 };
	double dtime = 0;
	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);
	return dtime;
}

int main()
{
	int N = 10000000;
	const char *novel = "Dickens_Oliver_1839.tokens.txt";

	FILE *file;
	file = fopen(novel, "r");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", novel);
		return 0;
	}

	int hashTableSize = 100000;
	Hash novelHash;
	novelHash.Create(hashTableSize);
	TreeNptr novelTree = NULL;

	cout << "Build Hash, BST..." << endl;
	char *word;
	char buffer[512];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		if (buffer[strlen(buffer) - 1] == '\r')
			buffer[strlen(buffer) - 1] = '\0';

		word = strtok(buffer, " ");

		while (word != NULL)
		{
			novelHash.Update(word);
			Update(novelTree, word);
			word = strtok(NULL, " ");
		}
	}
	fclose(file);

	cout << "Generate random value..." << endl << endl;
	int keyCount = 0;
	Nptr currentHash;
	for (int index = 0; index < hashTableSize; index++)
	{
		currentHash = novelHash.table[index];
		while (currentHash != NULL && currentHash->Data.Key.empty() == false)
		{
			keyCount++;
			currentHash = currentHash->next;
		}
	}

	string *keyList = new string[keyCount];

	int keyIndex = 0;
	for (int index = 0; index < hashTableSize; index++)
	{
		currentHash = novelHash.table[index];
		while (currentHash != NULL && currentHash->Data.Key.empty() == false)
		{
			keyList[keyIndex++] = currentHash->Data.Key;
			currentHash = currentHash->next;
		}
	}

	int randomValue;
	srand((size_t)time(NULL));
	string *randomKey = new string[N];
	for (int index = 0; index < N; index++)
	{
		randomValue = rand() % keyCount;
		randomKey[index] = keyList[randomValue];
	}

	double oldtime, elapsed_time;

	printf("Hash search... (HashTableSize: %d)\n", hashTableSize);
	for (N = 100000; N <= 10000000; N *= 10)
	{
		oldtime = getdtime();
		for (int index = 0; index < N; index++)
		{
			novelHash.Search(randomKey[index].c_str());
		}
		elapsed_time = getdtime() - oldtime;
		printf("N=%d, Hash search, elapsed_time: %lf sec\n", N, elapsed_time);
	}

	printf("BST search...\n");
	for (N = 100000; N <= 10000000; N *= 10)
	{
		oldtime = getdtime();
		for (int index = 0; index < N; index++)
		{
			Search(novelTree, randomKey[index].c_str());
		}
		elapsed_time = getdtime() - oldtime;
		printf("N=%d, BST search, elapsed_time: %lf sec\n", N, elapsed_time);
	}

	delete[] keyList;
	delete[] randomKey;
	return 0;
}