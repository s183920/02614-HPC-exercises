#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
#include <omp.h>
#endif

// time
// #ifdef _OPENMP
// #include <omp.h>
// #define mytimer omp_get_wtime
// #define delta_t(a,b) (1e3 * ((b)-(a)))
// #else
// #include <time.h>
// #define mytimer clock
// #define delta_t(a,b) (1e3 * ((b) - (a)) / CLOCKS_PER_SEC)
// #endif




double integrand(double x){
    return 4.0/(1 + x*x);
}

int main(int argc, char *argv[])
{
    // #ifdef _OPENMP
    // double t1, t2;
    // fprintf(stderr, "OpenMP version: timing wallclock time (in ms)!\n");
    // #else
    // clock_t t1, t2;
    // fprintf(stderr, "Serial version: timing CPU time (in ms)!\n");
    // #endif

    // t1 = mytimer();

    // program
    double x, sum, h;
    int N, i;

    sum = 0.0;
    N = 1000000000;
    h = 1.0 / (double)N;
    #pragma omp parallel for default(none) \
                                shared(N,h) private(i,x) \
                                reduction(+: sum)
    for(i = 1; i <= N; i++){
        x = h * ((double)i -0.5);
        sum += integrand(x);
    }// end parallel

    double pi = sum*h;
    // end program

    // t2 = mytimer();
    // printf("N = %d\npi = %f\ntime = %f ms\n", N, pi, delta_t(t1, t2));
    printf("N = %d\npi = %f\n", N, pi);
    return 0;
}

