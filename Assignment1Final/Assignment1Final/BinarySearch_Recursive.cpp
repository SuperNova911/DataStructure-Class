#include <iostream>

using namespace std;

int BinarySearch(int A[], int start, int end, int key);

int main()
{
	const int MAX_LIST = 1024;

	char fileName[] = "input.txt";

	char *item, *context;
	int index = 0;
	int list[MAX_LIST] = { 0 };

	FILE *stream;
	if (fopen_s(&stream, fileName, "r") != 0)
	{
		cout << "������ �� �� �����ϴ�. FileName: " << fileName << endl;
		return 0;
	}

	char buffer[1024];

	while (fgets(buffer, sizeof(buffer), stream) != NULL)
	{
		item = strtok_s(buffer, " ", &context);

		for (; item != NULL && index < MAX_LIST; index++)
		{
			list[index] = atoi(item);
			item = strtok_s(context, " ", &context);
		}
	}

	fclose(stream);

	int key = 0;
	cout << "�˻� �� ����: ";
	cin >> key;

	int binarySearchResult = BinarySearch(list, 0, index - 1, key);

	if (binarySearchResult == -1)
	{
		cout << key << "�� ���� �������� ����" << endl;
	}
	else
	{
		cout << key << "�� �ε���: " << binarySearchResult << endl;
	}

	return 0;
}

int BinarySearch(int A[], int start, int end, int key)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;

	if (A[mid] > key)
	{
		return BinarySearch(A, start, mid - 1, key);
	}
	else if (A[mid] < key)
	{
		return BinarySearch(A, mid + 1, end, key);
	}
	else
	{
		return mid;
	}
}
