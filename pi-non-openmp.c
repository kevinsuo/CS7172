#include <stdio.h>
#include <omp.h>
#include <time.h>

static long num_steps = 1000000;
double step;
void main(){
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        int i;
        double x, pi, sum = 0.0;
        step = 1.0/(double)num_steps;
        for(i=1;i<= num_steps;i++){
                x = (i-0.5)*step;
                sum=sum+4.0/(1.0+x*x);
        }
        pi=step*sum;

        clock_gettime(CLOCK_MONOTONIC, &end);
        double diff = 1000000000L * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;

        printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
        printf("%lf\n",pi);
}



