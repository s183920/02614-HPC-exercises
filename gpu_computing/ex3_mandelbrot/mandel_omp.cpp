#ifdef _OPENMP
#include <omp.h>
#endif
#include <stdio.h>

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


// cpu version
void
mandel_cpu(int disp_width, int disp_height, int *array, int max_iter) {

    double 	scale_real, scale_imag;
    double 	x, y, u, v, u2, v2;
    int 	i, j, iter;

    scale_real = 3.5 / (double)disp_width;
    scale_imag = 3.5 / (double)disp_height;

	#pragma omp for private(i,j) schedule(dynamic,1)
    for(i = 0; i < disp_width; i++) {
	x = ((double)i * scale_real) - 2.25; 
	for(j = 0; j < disp_height; j++) {
	    y = ((double)j * scale_imag) - 1.75; 

	    u    = 0.0;
	    v    = 0.0;
	    u2   = 0.0;
	    v2   = 0.0;
	    iter = 0;

	    while ( u2 + v2 < 4.0 &&  iter < max_iter ) {
		v = 2 * v * u + y;
		u = u2 - v2 + x;
		u2 = u*u;
		v2 = v*v;
		iter = iter + 1;
	    }

	    // if we exceed max_iter, reset to zero
	    iter = iter == max_iter ? 0 : iter;

	    array[i*disp_height + j] = iter;
	}
    }
}

// omp loop version
void
mandel_omp_loop(int disp_width, int disp_height, int *array, int max_iter) {
	#ifdef _OPENMP
    double t1, t2;
    fprintf(stderr, "OpenMP version: timing wallclock time (in ms)!\n");
    #else
    clock_t t1, t2;
    fprintf(stderr, "Serial version: timing CPU time (in ms)!\n");
    #endif

    double 	scale_real, scale_imag;
	scale_real = 3.5 / (double)disp_width;
    scale_imag = 3.5 / (double)disp_height;

    double 	x, y, u, v, u2, v2;
    int 	i, j, iter;

	t1 = mytimer();
	#pragma omp target teams loop \
				map(from: array[0:disp_width*disp_height]) \
				num_teams(108) thread_limit(64)
	for(i = 0; i < disp_width; i++) {

	x = ((double)i * scale_real) - 2.25; 

	for(j = 0; j < disp_height; j++) {
	    y = ((double)j * scale_imag) - 1.75; 

	    u    = 0.0;
	    v    = 0.0;
	    u2   = 0.0;
	    v2   = 0.0;
	    iter = 0;

	    while ( u2 + v2 < 4.0 &&  iter < max_iter ) {
		v = 2 * v * u + y;
		u = u2 - v2 + x;
		u2 = u*u;
		v2 = v*v;
		iter = iter + 1;
	    }

	    // if we exceed max_iter, reset to zero
	    iter = iter == max_iter ? 0 : iter;

	    array[i*disp_height + j] = iter;
	}
    }
	t2 = mytimer();
	printf("Mandel time without transfer: %f ms\n", delta_t(t1, t2));
}

// omp parallel version
void
mandel_omp_parallel(int disp_width, int disp_height, int *array, int max_iter) {
	#ifdef _OPENMP
    double t1, t2;
    fprintf(stderr, "OpenMP version: timing wallclock time (in ms)!\n");
    #else
    clock_t t1, t2;
    fprintf(stderr, "Serial version: timing CPU time (in ms)!\n");
    #endif

	#pragma omp target data map(tofrom: array[0:disp_width*disp_height])
	{
    double 	scale_real, scale_imag;
	scale_real = 3.5 / (double)disp_width;
    scale_imag = 3.5 / (double)disp_height;

    double 	x, y, u, v, u2, v2;
    int 	i, j, iter;

	t1 = mytimer();
	#pragma omp target teams distribute parallel for \
				num_teams(disp_height) thread_limit(disp_width) collapse(2)
	for(i = 0; i < disp_width; i++) {
	for(j = 0; j < disp_height; j++) {
		x = ((double)i * scale_real) - 2.25; 
	    y = ((double)j * scale_imag) - 1.75; 

	    u    = 0.0;
	    v    = 0.0;
	    u2   = 0.0;
	    v2   = 0.0;
	    iter = 0;

	    while ( u2 + v2 < 4.0 &&  iter < max_iter ) {
		v = 2 * v * u + y;
		u = u2 - v2 + x;
		u2 = u*u;
		v2 = v*v;
		iter = iter + 1;
	    }

	    // if we exceed max_iter, reset to zero
	    iter = iter == max_iter ? 0 : iter;

	    array[i*disp_height + j] = iter;
	}
    }
	t2 = mytimer();
	printf("Mandel time without transfer: %f ms\n", delta_t(t1, t2));
	} // end target data
}

