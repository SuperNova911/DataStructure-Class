#include "RBtree.h"

using namespace std;

int main2()
{
	treeRecord root;
	root.key = 10;
	root.LChild = NULL;
	root.RChild = NULL;
	root.Parent = NULL;
	root.color = BLACK;

	Insert(&root, 20);
	Insert(&root, 30);
	Insert(&root, 40);
	Insert(&root, 50);
	Insert(&root, 60);

	RBPrettyPrint("", &root, false);

	getchar();

	return 0;
}