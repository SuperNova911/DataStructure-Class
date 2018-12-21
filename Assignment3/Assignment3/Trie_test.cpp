#include "Trie.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "[Trie1] Create new Trie" << endl;
	Trie trie1;
	trie1.Create();
	cout << endl;

	cout << "[Trie1] Insert new keys (by, 1), (bye, 2), (byte, 3), (data, 4), (day, 5), (done, 6), (do, 7), (did, 8)" << endl;
	trie1.Insert("by", 1);
	trie1.Insert("bye", 2);
	trie1.Insert("byte", 3);
	trie1.Insert("data", 4);
	trie1.Insert("day", 5);
	trie1.Insert("done", 6);
	trie1.Insert("do", 7);
	trie1.Insert("did", 8);
	cout << endl;

	cout << "[Trie1] Insert exist keys (by, 10), (data, 40), (done, 60)" << endl;
	trie1.Insert("by", 10);
	trie1.Insert("data", 40);
	trie1.Insert("done", 60);
	cout << endl;

	cout << "[Trie1] Save current Trie, fileName: 'trie1_test_log1'" << endl;
	trie1.Save("trie1_test_log1");
	cout << endl;

	cout << "[Trie1] Search for exist keys (by, byte, data, did)" << endl;
	Nptr searchResult;
	cout << "Search 'by', ";
	searchResult = trie1.Search("by");
	searchResult == NULL
		? (cout << "not found" << endl)
		: (cout << "value: " << searchResult->val << endl);

	cout << "Search 'byte', ";
	searchResult = trie1.Search("byte");
	searchResult == NULL
		? (cout << "not found" << endl)
		: (cout << "value: " << searchResult->val << endl);

	cout << "Search 'data', ";
	searchResult = trie1.Search("data");
	searchResult == NULL
		? (cout << "not found" << endl)
		: (cout << "value: " << searchResult->val << endl);

	cout << "Search 'did', ";
	searchResult = trie1.Search("did");
	searchResult == NULL
		? (cout << "not found" << endl)
		: (cout << "value: " << searchResult->val << endl);
	cout << endl;

	cout << "[Trie1] Search for nonexist keys (b, daylight, effect, dig)" << endl;
	cout << "Search 'b', ";
	searchResult = trie1.Search("b");
	searchResult == NULL
		? (cout << "not found" << endl)
		: (cout << "value: " << searchResult->val << endl);

	cout << "Search 'daylight', ";
	searchResult = trie1.Search("daylight");
	searchResult == NULL
		? (cout << "not found" << endl)
		: (cout << "value: " << searchResult->val << endl);

	cout << "Search 'effect', ";
	searchResult = trie1.Search("effect");
	searchResult == NULL
		? (cout << "not found" << endl)
		: (cout << "value: " << searchResult->val << endl);

	cout << "Search 'dig', ";
	searchResult = trie1.Search("dig");
	searchResult == NULL
		? (cout << "not found" << endl)
		: (cout << "value: " << searchResult->val << endl);
	cout << endl;

	cout << "[Trie1] Delete for exist keys (by, data, did)" << endl;
	trie1.Delete("by");
	trie1.Delete("data");
	trie1.Delete("did");
	cout << endl;

	cout << "[Trie1] Delete for nonexist keys (byt, effect, didi)" << endl;
	trie1.Delete("byt");
	trie1.Delete("effect");
	trie1.Delete("didi");
	cout << endl;

	cout << "[Trie1] Save current Trie, fileName: 'trie1_test_log2'" << endl;
	trie1.Save("trie1_test_log2");
	cout << endl;

	cout << "[Trie2] Create new Trie" << endl;
	Trie trie2;
	trie2.Create();
	cout << endl;

	cout << "[Trie2] Open(Load) Trie from file, fileName: 'trie1_test_log2'" << endl;
	trie2.Open("trie1_test_log2");
	cout << endl;

	cout << "[Trie2] Insert new keys (daylignt, 100), (doing, 150)" << endl;
	trie1.Insert("daylignt", 100);
	trie1.Insert("doing", 150);
	cout << endl;

	cout << "[Trie2] Save Trie, fileName: 'trie2_test_log1'" << endl;
	trie2.Save("trie2_test_log1");
	cout << endl;

	return 0;
}