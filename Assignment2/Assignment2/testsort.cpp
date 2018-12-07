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
	int N, k = 1;
	cerr << "345";
	int A[1000000] = { 0, };
	cerr << "123";
	for (N = 1000; N < 1000000; N *= 10)
	{
		cout << "111";
		oldtime = getdtime();
		shellsort(A, N, k);
		elapsed_time = getdtime() - oldtime;
		
	}


	return 1;
}