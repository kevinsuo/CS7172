#include <stdio.h>
#include<time.h>
#define NUMSTEPS 100000

int main() {
        int i;
        double x, pi, sum = 0.0;

        clock_t t1=clock();

        double step = 1.0/(double) NUMSTEPS;
        x = 0.5 * step;

        for (i=0;i<= NUMSTEPS; i++){
                x+=step;
                sum += 4.0/(1.0+x*x);
        }
        pi = step * sum;

        clock_t t2=clock();

        printf("PI is %.20f\n",pi);
        printf("Time: %.2f\n",(float)(t2-t1));

        return 0;
}
