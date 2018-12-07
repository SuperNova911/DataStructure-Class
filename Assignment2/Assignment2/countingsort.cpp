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

void countSort(string a[], int size, size_t k)
{
	string *b = new string[size];
	int *c = new int[257];

	for (int i = 0; i < 257; i++)
	{
		c[i] = 0;
	}
	for (int j = 0; j < size; j++)
	{
		c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;      //a[j] is a string
	}

	for (int f = 1; f < 257; f++)
	{
		c[f] += c[f - 1];
	}

	for (int r = size - 1; r >= 0; r--)
	{
		b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
		c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
	}

	for (int l = 0; l < size; l++)
	{
		a[l] = b[l];
	}

	// avold memory leak
	delete[] b;
	delete[] c;
}