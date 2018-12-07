#include "mergesort.h"
#include <iostream>

int temp[10000000];

void merge(int *A, int first, int mid, int last)
{
	int first1, last1, first2, last2;
	first1 = first;
	last1 = mid;
	first2 = mid + 1;
	last2 = last;

	int index = first1;
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (A[first1] < A[first2])
		{
			temp[index] = A[first1];
			first1++;
		}
		else
		{
			temp[index] = A[first2];
			first2++;
		}

		index++;
	}

	while (first1 <= last1)
	{
		temp[index] = A[first1];
		first1++;
		index++;
	}

	while (first2 <= last2)
	{
		temp[index] = A[first2];
		first2++;
		index++;
	}

	for (index = first; index <= last; index++)
	{
		A[index] = temp[index];
	}
}

void mergesort(int *A, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(A, first, mid);
		mergesort(A, mid + 1, last);
		merge(A, first, mid, last);
	}
}