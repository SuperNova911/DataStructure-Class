#include "Hash.h"
#include <string>
#include <string.h>

using namespace std;

int main()
{
	const char *novelOutput = "Dickens_Oliver_1839.hash";

	Hash hash;
	int hashTableSize = 10000;
	hash.Create(hashTableSize);
	cout << "Open " << novelOutput << endl;
	hash.Open(novelOutput);

	cout << "Loading is complete" << endl;

	string userInput;
	Nptr searchResult;
	while (true)
	{
		cout << "input> ";
		cin >> userInput;
		fflush(stdin);

		searchResult = hash.Search(userInput.c_str());
		if (searchResult != NULL)
		{
			cout << searchResult->Data.count << endl;
		}
		else
		{
			cout << "Not found" << endl;
		}
	}
}