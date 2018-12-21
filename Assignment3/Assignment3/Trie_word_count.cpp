#include "Trie.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	const char *poem = "The-Road-Not-Taken.tokens.txt";
	const char *novel = "Dickens_Oliver_1839.tokens.txt";
	const char *poemOutput = "The-Road-Not-Taken.trie";
	const char *novelOutput = "Dickens_Oliver_1839.trie";

	FILE *file;
	file = fopen(poem, "r");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", poem);
		return 0;
	}

	int trieNodeCount = 126 - 32 + 1;
	Trie poemTrie;
	poemTrie.Create(trieNodeCount);

	cout << "Build Trie... " << poem << endl;
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
			poemTrie.Update(word);
			word = strtok(NULL, " ");
		}
	}
	fclose(file);

	cout << "Saving " << poemOutput << endl;
	poemTrie.Save(poemOutput);

	file = fopen(novel, "r");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", novel);
		return 0;
	}

	Trie novelTrie;
	novelTrie.Create(trieNodeCount);

	cout << "Build Trie... " << novel << endl;
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		if (buffer[strlen(buffer) - 1] == '\r')
			buffer[strlen(buffer) - 1] = '\0';

		word = strtok(buffer, " ");

		while (word != NULL)
		{
			novelTrie.Update(word);
			word = strtok(NULL, " ");
		}
	}
	fclose(file);

	cout << "Saving " << novelOutput << endl;
	novelTrie.Save(novelOutput);

	return 0;
}