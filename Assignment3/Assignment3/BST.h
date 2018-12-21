#pragma once
#include <iostream>

using namespace std;

typedef struct dataTreeRecord
{
	string Key;
	int count;
} dataTreeType;

typedef struct nodeTreeRecord
{
	dataTreeType Data;
	struct nodeTreeRecord* LChild;
	struct nodeTreeRecord* RChild;
} treeNode;

typedef treeNode* TreeNptr;

TreeNptr Search(TreeNptr T, const char *key);
TreeNptr Insert(TreeNptr T, const char *key);
void Delete(TreeNptr &T, const char *key);
void Update(TreeNptr &T, const char *key);
