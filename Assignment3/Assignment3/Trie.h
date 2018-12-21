#pragma once

#define NUM_ALPHABET 26
#define EMPTY_VALUE -1

typedef struct trieRecord
{
	int val;
	struct trieRecord **nodes;
} node;

typedef node * Nptr;

class Trie
{
public:
	int size;
	Nptr root;

public:
	void Create();
	void Create(int nodeCount);
	int Insert(const char *key, int val);
	Nptr Search(const char *key);
	void Delete(const char *key);
	void Save(const char *fileName);
	void Open(const char *fileName);
	void Update(const char *key);
};