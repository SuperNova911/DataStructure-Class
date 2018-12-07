#include "shellsort.h"
#include <iostream>
#include <string.h>
#include <time.h>

#define MAX_LIST 8192

int main(int argc, char *argv[])
{
	int data[MAX_LIST] = { 0, };
	int index = 0;

	FILE *fileStream = NULL;
	fileStream = fopen(argv[1], "r");
	if (fileStream == NULL)
	{
		srand((size_t)time(NULL));

		const int max = 100;
		while (index < max)
		{
			data[index] = rand() % max;
			index++;
		}
	}
	else
	{
		char *item;
		char buffer[8192];

		while (fgets(buffer, sizeof(buffer), fileStream) != NULL)
		{
			item = strtok(buffer, " ");

			while (item != NULL && index < MAX_LIST)
			{
				data[index] = atoi(item);
				item = strtok(NULL, " ");
				index++;
			}
		}
		fclose(fileStream);
	}

	for (int i = 0; i < index; i++)
	{
		printf("%2d ", data[i]);
	}
	printf("\n");

	shellsort(data, index, 2);
	for (int i = 0; i < index; i++)
	{
		printf("%2d ", data[i]);
	}

	return 0;
}