#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double integrand(double x){
    return 4.0/(1 + pow(x, 2));
}

double calc_pi(int N){
    double pi = 0.0;
    for(int i = 0; i < N; i++)
    {
        double x = (i-0.5)/N;
        pi += integrand(x);
    }
    pi = pi/N;
    return pi;
}

int main(int argc, char *argv[])
{
    // int N = 1000000;
    int N = atoi(argv[1]);
    double pi = calc_pi(N);

    printf("N = %d\npi = %f\n", N, pi);

    return 0;
}