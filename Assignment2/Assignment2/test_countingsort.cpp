#include "countingsort.h"
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

int main()
{
	double oldtime, elapsed_time;
	int *data, *dataOrigin;
	int N, K;

	srand((size_t)time(NULL));

	N = 1000000;
	data = (int *)malloc(sizeof(int) * N);
	dataOrigin = (int *)malloc(sizeof(int) * N);

	K = 100;
	for (int index = 0; index < N; index++)
		dataOrigin[index] = rand() % K;

	for (N = 1000; N <= 1000000; N *= 10)
	{
		memcpy(data, dataOrigin, sizeof(int) * N);
		oldtime = getdtime();
		countingsort(data, N, K);
		elapsed_time = getdtime() - oldtime;
		printf("N=%d, CountingSort, K=%d, elapsed_time: %lf sec\n", N, K, elapsed_time);
	}

	return 0;
}