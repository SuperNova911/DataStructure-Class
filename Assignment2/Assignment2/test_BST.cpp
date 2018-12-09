#include "BST.h"
#include <iostream>
#include <stack>

using namespace std;

void printTree(TreeNptr tree)
{
	stack<TreeNptr> nodeStack;
	TreeNptr currentNode = tree;

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

			printf("node, count: %d, key: %s\n", currentNode->Data.count, currentNode->Data.Key.c_str());
			currentNode = currentNode->RChild;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	// 새로운 이진트리 생성
	cout << "새로운 이진트리 생성" << endl;
	TreeNptr tree = NULL;
	cout << endl;

	// 이진트리 삽입
	cout << "이진트리 삽입 (AAA, BBB, FFF, GGG, CCC)" << endl;
	tree = Insert(tree, "AAA");
	tree = Insert(tree, "BBB");
	tree = Insert(tree, "FFF");
	tree = Insert(tree, "GGG");
	tree = Insert(tree, "CCC");
	printTree(tree);
	cout << endl;

	// 이진트리 삭제
	cout << "이진트리 삭제 (AAA, BBB, CCC, XXX)" << endl;
	Delete(tree, "AAA");
	Delete(tree, "BBB");
	Delete(tree, "CCC");
	Delete(tree, "XXX");
	printTree(tree);
	cout << endl;

	// 이진트리 업데이트
	cout << "이진트리 업데이트 (AAA, AAA, CCC, DDD, GGG, GGG, GGG, KKK)" << endl;
	Update(tree, "AAA");
	Update(tree, "AAA");
	Update(tree, "CCC");
	Update(tree, "DDD");
	Update(tree, "GGG");
	Update(tree, "GGG");
	Update(tree, "GGG");
	Update(tree, "KKK");
	printTree(tree);
	cout << endl;

	// 이진트리 검색
	cout << "이진트리 검색 (AAA, BBB, CCC, XXX)" << endl;
	TreeNptr searchResult;
	searchResult = Search(tree, "AAA");
	if (searchResult != NULL)
		printf("AAA search result, key: '%s', count: '%d'\n", searchResult->Data.Key.c_str(), searchResult->Data.count);
	else
		cout << "AAA not found" << endl;

	searchResult = Search(tree, "BBB");
	if (searchResult != NULL)
		printf("BBB search result, key: '%s', count: '%d'\n", searchResult->Data.Key.c_str(), searchResult->Data.count);
	else
		cout << "BBB not found" << endl;

	searchResult = Search(tree, "CCC");
	if (searchResult != NULL)
		printf("CCC search result, key: '%s', count: '%d'\n", searchResult->Data.Key.c_str(), searchResult->Data.count);
	else
		cout << "CCC not found" << endl;

	searchResult = Search(tree, "XXX");
	if (searchResult != NULL)
		printf("XXX search result, key: '%s', count: '%d'\n", searchResult->Data.Key.c_str(), searchResult->Data.count);
	else
		cout << "XXX not found" << endl;

	return 0;
}