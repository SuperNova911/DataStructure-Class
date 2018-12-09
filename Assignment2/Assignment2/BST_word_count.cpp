#include "BST.h"
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int main()
{
	const char *poem = "The-Road-Not-Taken.tokens.txt";
	const char *novel = "Dickens_Oliver_1839.tokens.txt";
	const char *poemOutput = "The-Road-Not-Taken.wordcount";
	const char *novelOutput = "Dickens_Oliver_1839.wordcount";

	FILE *file;
	file = fopen(poem, "r");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", poem);
		return 0;
	}

	TreeNptr poemTree = NULL;

	printf("'%s' word count 계산 중...\n", poem);
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
			Update(poemTree, word);
			word = strtok(NULL, " ");
		}
	}
	fclose(file);

	remove(poemOutput);
	file = fopen(poemOutput, "a");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", poemOutput);
		return 0;
	}

	printf("계산 결과를 '%s'에 저장 중...\n", poemOutput);
	stack<TreeNptr> nodeStack;
	TreeNptr currentNode;
	currentNode = poemTree;
	while (true)
	{
		while (currentNode != NULL)
		{
			nodeStack.push(currentNode);
			currentNode = currentNode->LChild;
		}

		if (nodeStack.empty() == false)
		{
			currentNode = nodeStack.top();
			nodeStack.pop();

			sprintf(buffer, "%s %d\n", currentNode->Data.Key.c_str(), currentNode->Data.count);
			fputs(buffer, file);
			currentNode = currentNode->RChild;
		}
		else
		{
			break;
		}
	}
	fclose(file);

	file = fopen(novel, "r");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", novel);
		return 0;
	}

	TreeNptr novelTree = NULL;

	printf("'%s' word count 계산 중...\n", novel);
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		if (buffer[strlen(buffer) - 1] == '\r')
			buffer[strlen(buffer) - 1] = '\0';

		word = strtok(buffer, " ");

		while (word != NULL)
		{
			Update(novelTree, word);
			word = strtok(NULL, " ");
		}
	}
	fclose(file);

	remove(novelOutput);
	file = fopen(novelOutput, "a");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", novelOutput);
		return 0;
	}

	printf("계산 결과를 '%s'에 저장 중...\n", novelOutput);
	currentNode = novelTree;
	while (true)
	{
		while (currentNode != NULL)
		{
			nodeStack.push(currentNode);
			currentNode = currentNode->LChild;
		}

		if (nodeStack.empty() == false)
		{
			currentNode = nodeStack.top();
			nodeStack.pop();

			sprintf(buffer, "%s %d\n", currentNode->Data.Key.c_str(), currentNode->Data.count);
			fputs(buffer, file);
			currentNode = currentNode->RChild;
		}
		else
		{
			break;
		}
	}
	fclose(file);
	
	cout << "프로그램 종료" << endl;
	return 0;
}