#include "Heap.h"
#include <iostream>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

double getdtime()
{
	struct timeval tv = { 0 };
	double dtime = 0;
	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);
	return dtime;
}

int main()
{
	const int N = 10000000;

	srand((size_t)time(NULL));
	int *randomValue = new int[N];
	for (int index = 0; index < N; index++)
	{
		randomValue[index] = rand();
	}

	int *data = new int[N];
	int *sort = new int[N];
	double oldtime, elapsed_time;
	for (int n = 100000; n <= N; n *= 10)
	{
		memcpy(data, randomValue, sizeof(int) * n);
		oldtime = getdtime();
		build_heap(data, n);
		for (int index = 0; index < n; index++)
		{
			sort[index] = remove_heap(data, n - index);
		}
		elapsed_time = getdtime() - oldtime;
		printf("N=%d, heapsort, elapsed_time: %lf sec\n", n, elapsed_time);
	}

	delete[] randomValue;
	delete[] data;
	delete[] sort;
	return 0;
}