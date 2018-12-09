#include "Heap.h"

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void downHeap(int *A, int size, int currentIndex)
{
	int leftChild, rightChild, p;

	leftChild = 2 * currentIndex + 1;
	rightChild = 2 * currentIndex + 2;

	p = currentIndex;
	if (leftChild <= size && A[leftChild] > A[p])
	{
		p = leftChild;
	}
	if (rightChild <= size && A[rightChild] > A[p])
	{
		p = rightChild;
	}

	if (p != currentIndex)
	{
		swap(&A[currentIndex], &A[p]);
		downHeap(A, size, p);
	}
}

int remove(int *A, int size)
{
	int rootValue = A[0];

	A[0] = A[size - 1];
	downHeap(A, size - 1, 0);

	return rootValue;
}

void build_heap(int *A, int size)
{
	for (int index = (size - 1) / 2; index >= 0; index--)
	{
		downHeap(A, size, index);
	}
}

int remove_heap(int *A, int size)
{
	return remove(A, size);
}
