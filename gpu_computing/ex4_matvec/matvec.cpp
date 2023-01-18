#include <omp.h>
#include <stdio.h>
#include <cblas.h>
#include "alloc2d.h"

// mattix vector multiplicatiomn

void matvec(double **A, double *x, double *y, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        y[i] = 0.0;
        for (j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

// matvec using dgemv
void matvec_dgemv(double **A, double *x, double *y, int m, int n) {
    cblas_dgemv(CblasRowMajor, CblasNoTrans, m, n, 1.0, A[0], n, x, 1, 0.0, y, 1);
}

