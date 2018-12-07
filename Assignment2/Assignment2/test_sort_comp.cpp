#include "shellsort.h"
#include "mergesort.h"
#include "quicksort.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

using namespace std;

double getdtime()
{
	struct timeval tv = { 0 };
	double dtime;
	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);
	return dtime;
}

int main(int argc, char **argv)
{
	double oldtime, elapsed_time;
	int *data, *dataOrigin;
	int N, K;

	srand((size_t)time(NULL));

	N = 10000000;
	data = (int *)malloc(sizeof(int) * N);
	dataOrigin = (int *)malloc(sizeof(int) * N);

	for (int index = 0; index < N; index++)
		dataOrigin[index] = rand();

	K = 3;
	for (N = 1000; N <= 10000000; N *= 10)
	{
		memcpy(data, dataOrigin, sizeof(int) * N);
		oldtime = getdtime();
		shellsort(data, N, K);
		elapsed_time = getdtime() - oldtime;
		printf("N=%d, Shellsort-Pratt, K=%d, elapsed_time: %lf sec\n", N, K, elapsed_time);

		memcpy(data, dataOrigin, sizeof(int) * N);
		oldtime = getdtime();
		shellsort_sedgewick(data, N);
		elapsed_time = getdtime() - oldtime;
		printf("N=%d, Shellsort-Sedgewick,  elapsed_time: %lf sec\n", N, elapsed_time);

		memcpy(data, dataOrigin, sizeof(int) * N);
		oldtime = getdtime();
		mergesort(data, 0, N - 1);
		elapsed_time = getdtime() - oldtime;
		printf("N=%d, Mergesort,            elapsed_time: %lf sec\n", N, elapsed_time);
		
		memcpy(data, dataOrigin, sizeof(int) * N);
		oldtime = getdtime();
		quicksort(data, 0, N - 1);
		elapsed_time = getdtime( ) - oldtime;
		printf("N=%d, Quicksort,            elapsed_time: %lf sec\n", N, elapsed_time);
	}

	return 0;
}