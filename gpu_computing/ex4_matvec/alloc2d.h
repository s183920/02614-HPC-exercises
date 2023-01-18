#ifndef ALLOC2D_H
#define ALLOC2D_H

/* Routine for allocating two-dimensional array */
double **malloc_2d(int m, int n);

void free_2d(double **A);

//  allocate a double-prec n long vector
double *
dmalloc_1d(int n);

// de-allocting memory, allocated with dmalloc_1d
void
dfree_1d(double *b);

#endif