#include "countingsort.h"
#include <iostream>
#include <string.h>

void countingsort(int *A, int size, int k)
{
	int *table = (int *)malloc(sizeof(int) * k);
	memset(table, 0, sizeof(int) * k);

	for (int index = 0; index < size; index++)
	{
		table[A[index]] += 1;
	}

	int index = 0;
	for (int tableIndex = 0; index < size; tableIndex++)
	{
		while (table[tableIndex] > 0)
		{
			A[index] = tableIndex;
			index++;
			table[tableIndex] -= 1;
		}
	}

	free(table);
}