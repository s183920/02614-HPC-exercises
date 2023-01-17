#ifndef _MANDEL_H
#define _MANDEL_H

void mandel_cpu(int width, int height, int *image, int max_iter);
void mandel_omp_loop(int width, int height, int *image, int max_iter);
void mandel_omp_parallel(int width, int height, int *image, int max_iter);

#endif
