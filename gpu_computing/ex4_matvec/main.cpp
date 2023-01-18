#include "alloc2d.h"
#include "matvec.h"
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv) {
    int m = 1000;
    int n = 1000;
    int i, j;
    double **A = malloc_2d(m, n);
    double *x = dmalloc_1d(n);
    double *y = dmalloc_1d(m);
    double *y2 = dmalloc_1d(m);

    // initialize A 
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = i + j;
        }
    }

    // initialize x
    for (j = 0; j < n; j++) {
        x[j] = j*j;
    }
    matvec(A, x, y, m, n);
    // matvec_dgemv(A, x, y2, m, n);

    // check result
    for (i = 0; i < m; i++) {
        if (y[i] != y2[i]) {
            printf("Error: y[%d] = %f, y2[%d] = %f", i, y[i], i, y2[i]);
        }
    }
}