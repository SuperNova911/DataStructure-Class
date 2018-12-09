#include "shellsort.h"
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
	int N;

	srand((size_t)time(NULL));

	N = 1000000;
	data = new int[N];
	dataOrigin = new int[N];

	for (int index = 0; index < N; index++)
		dataOrigin[index] = rand();

	for (N = 1000; N <= 1000000; N *= 10)
	{
		for (int k = 1; k <= 3; k++)
		{
			memcpy(data, dataOrigin, sizeof(int) * N);
			oldtime = getdtime();
			shellsort(data, N, k);
			elapsed_time = getdtime() - oldtime;
			cerr << "N=" << N << ", K=" << k << ", elapsed_time: " << fixed << elapsed_time << " sec" << endl;
		}
	}

	delete[] data;
	delete[] dataOrigin;
	return 0;
}