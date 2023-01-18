#include <stdlib.h>
#include <stdio.h>

/* Routine for allocating two-dimensional array */
double **
malloc_2d(int m, int n)
{
    int i;

    if (m <= 0 || n <= 0)
	return NULL;

    double **A = malloc(m * sizeof(double *));
    if (A == NULL)
	return NULL;

    A[0] = malloc(m*n*sizeof(double));
    if (A[0] == NULL) {
	free(A);
	return NULL;
    }
    for (i = 1; i < m; i++)
	A[i] = A[0] + i * n;

    return A;
}

void
free_2d(double **A) {
    free(A[0]);
    free(A);
}


//  allocate a double-prec n long vector
double *
dmalloc_1d(int n) {
    if (n <= 0) return NULL;
    double *b = malloc(n * sizeof(double));
    if (b == NULL) return NULL;
    return b;
}

// de-allocting memory, allocated with dmalloc_1d
void
dfree_1d(double *b) {
    free(b);
}