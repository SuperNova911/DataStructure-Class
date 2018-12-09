#include "BST.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("입력파일 이름을 입력하세요\n");
		return 0;
	}

	FILE *file;
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", argv[1]);
		return 0;
	}

	char buffer[128];
	int lineNumber;
	for (lineNumber = 0; fgets(buffer, sizeof(buffer), file) != NULL; lineNumber++)
	{

	}
	fclose(file);

	dataTreeType *data = new dataTreeType[lineNumber];	

	file = fopen(argv[1], "r");
	for (int index = 0; fgets(buffer, sizeof(buffer), file) != NULL; index++)
	{
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		if (buffer[strlen(buffer) - 1] == '\r')
			buffer[strlen(buffer) - 1] = '\0';

		data[index].Key = strtok(buffer, " ");
		data[index].count = atoi(strtok(NULL, " "));
	}
	fclose(file);

	cout << "Loading is complete" << endl;

	int left, mid, right;
	string userInput;
	while (true)
	{
		cout << "input> ";
		cin >> userInput;
		fflush(stdin);

		left = 0;
		right = lineNumber;
		while (true)
		{
			if (left > right)
			{
				cout << "Not found" << endl;
				break;
			}

			mid = (left + right) / 2;
			if (data[mid].Key == userInput)
			{
				cout << data[mid].count << endl;
				break;
			}
			else if (data[mid].Key > userInput)
			{
				right = mid - 1;
			}
			else if (data[mid].Key < userInput)
			{
				left = mid + 1;
			}
		}
	}

	delete data;
	return 0;
}