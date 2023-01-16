#include <stdio.h>
#include <stdlib.h>
#include "mandel.h"
#include "writepng.h"

// time
#ifdef _OPENMP
#include <omp.h>
#define mytimer omp_get_wtime
#define delta_t(a,b) (1e3 * ((b)-(a)))
#else
#include <time.h>
#define mytimer clock
#define delta_t(a,b) (1e3 * ((b) - (a)) / CLOCKS_PER_SEC)
#endif


int
main(int argc, char *argv[]) {
    #ifdef _OPENMP
    double t1, t2;
    fprintf(stderr, "OpenMP version: timing wallclock time (in ms)!\n");
    #else
    clock_t t1, t2;
    fprintf(stderr, "Serial version: timing CPU time (in ms)!\n");
    #endif

    int   width, height;
    int	  max_iter;
    int   *image;

    width    = 2601;
    height   = 2601;
    max_iter = 400;

    // command line argument sets the dimensions of the image
    if ( argc == 2 ) width = height = atoi(argv[1]);

    image = (int *)malloc( width * height * sizeof(int));
    if ( image == NULL ) {
       fprintf(stderr, "memory allocation failed!\n");
       return(1);
    }

    t1 = mytimer();
    #pragma omp parallel
    {
    mandel(width, height, image, max_iter);
    } //end parallel
    t2 = mytimer();

    writepng("mandelbrot.png", image, width, height);

    printf("Mandel time = %f ms\n", delta_t(t1, t2));

    return(0);
}
