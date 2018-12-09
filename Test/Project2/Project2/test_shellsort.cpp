#include "shellsort.h"
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
	const char *OUTPUT = "test_shellsort.sort";
	const int RANDOM_DATA_SIZE = 1000;

	int *data;
	int dataSize = 0;
	char buffer[512];

	FILE *file;
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		if (argc == 2)
		{
			printf("파일을 열 수 없습니다, file: '%s'\n", argv[1]);
			return 0;
		}
		cout << "랜덤 데이터에 대한 정렬을 수행합니다" << endl;

		dataSize = RANDOM_DATA_SIZE;
		data = new int[dataSize];

		srand((size_t)time(NULL));
		for (int index = 0; index < RANDOM_DATA_SIZE; index++)
		{
			data[index] = rand() % RANDOM_DATA_SIZE;
		}
	}
	else
	{
		cout << "입력파일에 대한 정렬을 수행합니다" << endl;

		char *word;
		while (fgets(buffer, sizeof(buffer), file) != NULL)
		{
			if (buffer[strlen(buffer) - 1] == '\n')
				buffer[strlen(buffer) - 1] = '\0';

			word = strtok(buffer, " ");

			while (word != NULL)
			{
				dataSize++;
				word = strtok(NULL, " ");
			}
		}
		fclose(file);

		data = new int[dataSize];

		fopen(argv[1], "r");
		int inputIndex = 0;
		while (fgets(buffer, sizeof(buffer), file) != NULL)
		{
			if (buffer[strlen(buffer) - 1] == '\n')
				buffer[strlen(buffer) - 1] = '\0';

			word = strtok(buffer, " ");

			while (word != NULL)
			{
				data[inputIndex++] = atoi(word);
				word = strtok(NULL, " ");
			}
		}
		fclose(file);
	}

	remove(OUTPUT);
	file = fopen(OUTPUT, "w");
	if (file == NULL)
	{
		printf("Cannot open file, file: '%s'\n", OUTPUT);
		return 0;
	}

	fputs("Before sort\n", file);
	for (int index = 0; index < dataSize; index++)
	{
		sprintf(buffer, " %3d", data[index]);
		fputs(buffer, file);
	}
	fputs("\n\n", file);

	shellsort(data, dataSize, 2);

	fputs("After sort\n", file);
	for (int index = 0; index < dataSize; index++)
	{
		sprintf(buffer, " %3d", data[index]);
		fputs(buffer, file);
	}
	fclose(file);

	printf("정렬 결과가 '%s' 파일에 저장되었습니다\n", OUTPUT);

	return 0;
}