//gcc pi-cal.c -o pi-cal.o -fopenmp

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define n 100000

int main(int argc, char *argv[]) {
        double factor = 1.0;
        double sum, pi_approx = 0.0;
        int k = 0;


#       pragma omp parallel for reduction(+:sum)
        for (k=0; k<n; k++) {
                sum += factor/(2*k+1);
                factor = -factor;
        }
        pi_approx = 4.0 * sum;

        printf("pi is %f\n", pi_approx);
        return 0;
}


