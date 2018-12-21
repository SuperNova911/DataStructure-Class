#pragma once
#include <iostream>

#define RED true
#define BLACK false

using namespace std;

typedef struct treeRecord
{
	int key;
	struct treeRecord * LChild;
	struct treeRecord * RChild;
	struct treeRecord * Parent;
	bool color;
}node;

typedef node * Nptr;

void Insert(Nptr node, int key);
void Delete(Nptr node, int key);

bool RBVertify(Nptr node);
void RBPrettyPrint(const string & prefix, Nptr node, bool isLeft);