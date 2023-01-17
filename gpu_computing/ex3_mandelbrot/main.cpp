#include <stdio.h>
#include <stdlib.h>
#include "mandel_omp.h"
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

    int version = 2;
    if (argc == 2) {
        version = atoi(argv[1]);
    }
    int warm = 0;
    if (argc == 3) {
        warm = atoi(argv[2]);
    }

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

    // warm up gpu
    if (warm == 1) {
        int dummy = 0;
        #pragma omp target map(tofrom:dummy)
        {}
    }


    t1 = mytimer();
    if (version == 0){
        mandel_cpu(width, height, image, max_iter);
    } else if (version == 1){
        mandel_omp_loop(width, height, image, max_iter);
    } else if (version == 2){
        mandel_omp_parallel(width, height, image, max_iter);
    } else {
        fprintf(stderr, "Invalid version number!\n");
        return(1);
    }
    // mandel(width, height, image, max_iter);
    t2 = mytimer();

    writepng("mandelbrot.png", image, width, height);

    printf("Mandel time with transfer = %f ms\n", delta_t(t1, t2));

    return(0);
}
