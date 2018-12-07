#include "shellsort.h"
#include <math.h>
#include <stdio.h>

void insertionsort(int *A, int size, int start, int h)
{
	int i, j, pick;
	for (i = start + h; i < size; i += h)
	{
		pick = A[i];
		for (j = i - h; j >= 0 && pick < A[j]; j -= h)
		{
			A[j + h] = A[j];
			A[j] = pick;
		}
	}
}

void shellsort(int *A, int size, int K)
{
	int gap;
	int m = 0;

	do
	{
		if (K == 1)
		{
			m = gap = 1;
			break;
		}
		
		gap = (pow(K, (++m + 1)) - 1) / (K - 1);
	} while (gap <= size);

	while (m > 0)
	{
		if (K == 1)
		{
			gap = 1;
			m = 0;
		}
		else
			gap = (pow(K, m--) - 1) / (K - 1);

		for (int i = 0; i < gap; i++)
		{
			insertionsort(A, size, i, gap);
		}
	}
}

void shellsort_sedgewick(int *A, int size)
{
	int gap, m;
	m = 0;
	do
	{
		if (m == 0)
		{
			gap = 1;
			m++;
			continue;
		}

		gap = pow(4, m) + (3 * pow(2, (m - 1))) + 1;
		m++;
	} while (gap <= size);

	while (m-- > 0)
	{
		if (m == 0)
			gap = 1;
		else
			gap = pow(4, m) + (3 * pow(2, (m - 1))) + 1;

		for (int i = 0; i < gap; i++)
		{
			insertionsort(A, size, i, gap);
		}
	}
}