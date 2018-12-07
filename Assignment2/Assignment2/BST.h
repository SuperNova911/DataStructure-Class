#pragma once
#include <iostream>

using namespace std;

typedef struct dataRecord
{
	string Key;
	int count;
} dataType;

typedef struct nodeTreeRecord
{
	dataType Data;
	struct nodeTreeRecord* LChild;
	struct nodeTreeRecord* RChild;
} node;

typedef node* Nptr;

Nptr Search(Nptr T, const char *key);
Nptr Insert(Nptr T, const char *key);
void Delete(Nptr &T, const char *key);
void Update(Nptr &T, const char *key);
