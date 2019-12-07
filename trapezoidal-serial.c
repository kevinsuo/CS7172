/*
 * compile: gcc trapezoidal-serial.c -o trapezoidal-serial.o -lm
 */

#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>

double Size;

double f(double x)
{
	return sin(x) + 2;
}

double Trap(double a, double b, int n)
{
	double h = (b-a)/n;
	int i;

	for (i = 0; i < n; i++) {
		double x_i = a + i*h;
		Size = Size + f(x_i) * h;
	}

	return Size;
}

int main() {
	double a, b;
	int n;
	struct timeval tvs,tve;

	gettimeofday(&tvs,NULL);  //get start time

	a = 1, b = 10;
	n = 1000;

	Size = Trap(a, b, n);

	printf("Size = %.2lf\n", Size);

	gettimeofday(&tve,NULL);   //get end time
        double span = tve.tv_sec-tvs.tv_sec + (tve.tv_usec-tvs.tv_usec)/1000000.0;
        printf("Time: %.12f\n", span);

	return 0;
}


