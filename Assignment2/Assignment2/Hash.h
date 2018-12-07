#pragma once
#include <iostream>

using namespace std;

typedef struct dataRecord
{
	string Key;
	int count;
} dataType;

typedef struct nodeRecord
{
	dataType Data;
	struct nodeRecord* next;
} node;

typedef node* Nptr;

class Hash
{
public:
	int size;
	Nptr *table;

public:
	void Create(int tableSize);
	int Insert(const char *key);
	Nptr Search(const char *key);
	void Update(const char *key);
	void Delete(const char *key);
	void Save(const char *fileName);
	void Open(const char *fileName);
	void Rehash(int newTableSize);
};