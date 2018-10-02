#include <iostream>

using namespace std;

int KarySearch(int A[], int k, int start, int end, int key);

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
		cout << "파일을 열 수 없습니다. FileName: " << fileName << endl;
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

	int k = 2;
	cout << "k-arySearch. k값: ";
	cin >> k;

	if (k < 2)
	{
		cout << "k값은 2보다 작을 수 없음" << endl;
		return 0;
	}

	int key = 0;
	cout << "검색 할 숫자: ";
	cin >> key;

	int binarySearchResult = KarySearch(list, k, 0, index - 1, key);

	if (binarySearchResult == -1)
	{
		cout << key << "의 값이 존재하지 않음" << endl;
	}
	else
	{
		cout << key << "의 인덱스: " << binarySearchResult << endl;
	}

	return 0;
}

int KarySearch(int A[], int k, int start, int end, int key)
{
	if (start > end)
		return -1;

	int pivot1 = -1, pivot2 = start;

	for (int n = 1; n <= k; n++)
	{
		pivot1 = pivot2;
		pivot2 = start + round((end - start) / (float)k * (float)n);

		if (A[pivot2] == key)
		{
			return pivot2;
		}
		else if (key < A[pivot2])
		{
			return KarySearch(A, k, pivot1, pivot2 - 1, key);
		}
		else if (A[pivot2] < key && pivot2 == end)
		{
			return KarySearch(A, k, pivot1, pivot2 - 1, key);
		}
		else
		{
			continue;
		}
	}

	// 여기까지 오지 않음
	return -2;
}