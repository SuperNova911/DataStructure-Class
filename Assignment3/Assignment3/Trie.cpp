#include "Trie.h"
#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int NUM_NODE;
int ASCII_START;

Nptr CreateTrieNode()
{
	Nptr p = new node;
	p->val = EMPTY_VALUE;
	p->nodes = new node*[NUM_NODE];

	for (int index = 0; index < NUM_NODE; index++)
	{
		p->nodes[index] = NULL;
	}
	return p;
}

bool DeleteHelper(string key, Nptr parentNode)
{
	if (parentNode == NULL)
	{
		return false;
	}

	bool hasNode = false;
	for (int index = 0; index < NUM_NODE; index++)
	{
		if (parentNode->nodes[index] != NULL)
		{
			hasNode = true;
			break;
		}
	}

	if (key.length() == 1)
	{
		if (hasNode)
		{
			parentNode->nodes[key.front() - ASCII_START]->val = EMPTY_VALUE;
			return false;
		}
		else
		{
			return true;
		}
	}

	bool deleteResult = false;
	if (hasNode)
	{
		deleteResult = DeleteHelper(key.substr(1), parentNode->nodes[key.front() - ASCII_START]);
	}

	if (deleteResult == false)
	{
		return false;
	}

	hasNode = false;
	for (int index = 0; index < NUM_NODE; index++)
	{
		if (parentNode->nodes[index] != NULL && index != key.front() - ASCII_START)
		{
			hasNode = true;
			break;
		}
	}

	if (hasNode == false)
	{
		delete parentNode->nodes[key.front() - ASCII_START];
		parentNode->nodes[key.front() - ASCII_START] = NULL;
		return true;
	}

	return false;
}

void SaveHelper(string key, Nptr targetNode, FILE *file)
{
	if (targetNode->val != EMPTY_VALUE)
	{
		char buffer[64];
		sprintf(buffer, "%s %d\n", key.c_str(), targetNode->val);
		fputs(buffer, file);
	}

	for (int index = 0; index < NUM_NODE; index++)
	{
		if (targetNode->nodes[index] != NULL)
		{
			key.push_back(index + ASCII_START);
			SaveHelper(key, targetNode->nodes[index], file);
			key.pop_back();
		}
	}
}

void Trie::Create()
{
	NUM_NODE = NUM_ALPHABET;
	ASCII_START = 'a';

	size = 0;
	root = CreateTrieNode();
}

void Trie::Create(int nodeCount)
{
	NUM_NODE = nodeCount;
	ASCII_START = 32;

	size = 0;
	root = CreateTrieNode();
}

int Trie::Insert(const char * key, int val)
{
	Nptr targetNode = root;

	for (int index = 0; key[index] != 0; index++)
	{
		if (targetNode->nodes[key[index] - ASCII_START] == NULL)
		{
			targetNode->nodes[key[index] - ASCII_START] = CreateTrieNode();
		}
		targetNode = targetNode->nodes[key[index] - ASCII_START];
	}
	targetNode->val = val;

	return 0;
}

Nptr Trie::Search(const char * key)
{
	Nptr targetNode = root;

	for (int index = 0; key[index] != 0; index++)
	{
		if (targetNode->nodes[key[index] - ASCII_START] == NULL)
		{
			return NULL;
		}
		targetNode = targetNode->nodes[key[index] - ASCII_START];
	}

	if (targetNode->val == EMPTY_VALUE)
		return NULL;

	return targetNode;
}

void Trie::Delete(const char * key)
{
	DeleteHelper(key, root);
}

void Trie::Save(const char * fileName)
{
	FILE *file;
	remove(fileName);
	file = fopen(fileName, "w");
	if (file == NULL)
	{
		printf("Cannot open file, fileName: '%s'\n", fileName);
		return;
	}

	SaveHelper("", root, file);
	fclose(file);
}

void Trie::Open(const char * fileName)
{
	FILE *file;
	file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("Cannot open file, fileName: '%s'\n", fileName);
		return;
	}

	char *token;
	char buffer[64];
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = 0;

		token = strtok(buffer, " ");
		if (token != NULL)
		{
			Insert(token, atoi(strtok(NULL, " ")));
		}
	}
	fclose(file);
}

void Trie::Update(const char * key)
{
	Nptr targetNode = Search(key);

	if (targetNode == NULL)
	{
		Insert(key, 1);
	}
	else
	{
		targetNode->val++;
	}
}
