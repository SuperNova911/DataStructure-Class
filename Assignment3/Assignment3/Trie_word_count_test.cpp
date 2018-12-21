#include "Trie.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "입력파일의 이름을 입력해야합니다" << endl;
		return 0;
	}

	const char *inputFile = argv[1];

	int trieNodeCount = 126 - 32 + 1;
	Trie trie;
	trie.Create(trieNodeCount);

	cout << "Open " << inputFile << endl;
	trie.Open(inputFile);

	cout << "Loading is complete" << endl;

	string userInput;
	Nptr searchResult;
	while (true)
	{
		cout << "input> ";
		cin >> userInput;
		fflush(stdin);

		searchResult = trie.Search(userInput.c_str());
		if (searchResult != NULL)
		{
			cout << searchResult->val << endl;
		}
		else
		{
			cout << "Not found" << endl;
		}
	}

	return 0;
}