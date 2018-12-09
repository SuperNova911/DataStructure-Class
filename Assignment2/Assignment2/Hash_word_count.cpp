#include "Hash.h"
#include <string>
#include <string.h>

using namespace std;

int main()
{
	const char *poem = "The-Road-Not-Taken.tokens.txt";
	const char *novel = "Dickens_Oliver_1839.tokens.txt";
	const char *poemOutput = "The-Road-Not-Taken.hash";
	const char *novelOutput = "Dickens_Oliver_1839.hash";

	FILE *file;
	file = fopen(poem, "r");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", poem);
		return 0;
	}

	int hashTableSize = 50;
	Hash poemHash;
	poemHash.Create(hashTableSize);

	cout << "Hashing " << poem << endl;
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
			poemHash.Update(word);
			word = strtok(NULL, " ");
		}
	}
	fclose(file);

	cout << "Saving " << poemOutput << endl;
	poemHash.Save(poemOutput);

	file = fopen(novel, "r");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", novel);
		return 0;
	}

	hashTableSize = 10000;
	Hash novelHash;
	novelHash.Create(hashTableSize);

	cout << "Hashing " << novel << endl;
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
			word = strtok(NULL, " ");
		}
	}
	fclose(file);

	cout << "Saving " << novelOutput << endl;
	novelHash.Save(novelOutput);

    return 0;
}