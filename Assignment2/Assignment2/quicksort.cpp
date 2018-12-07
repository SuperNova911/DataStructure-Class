#include "quicksort.h"
#include <iostream>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *A, int left, int right)
{
	int low, high, pivot, length;

	pivot = A[left];
	low = left + 1;
	high = right;
	length = right - left + 1;

	while (low <= high)
	{
		while (pivot >= A[low] && low <= right)
		{
			if (low == length - 1)
				break;
			low++;
		}

		while (pivot <= A[high] && high >= (left + 1))
		{
			high--;
		}

		if (low <= high)
			swap(&A[low], &A[high]);

		if (low == length - 1)
			break;
	}

	swap(&A[left], &A[high]);

	return high;
}

void quicksort(int *A, int left, int right)
{
	if (left < right)
	{
		int pivot = partition(A, left, right);
		quicksort(A, left, pivot - 1);
		quicksort(A, pivot + 1, right);
	}
}