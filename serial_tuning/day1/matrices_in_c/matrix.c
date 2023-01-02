#include "matrix.h"

//  allocate a double-prec m x n matrix
double **
dmalloc_2d(int m, int n) {
    if (m <= 0 || n <= 0) return NULL;
    double **A = malloc(m * sizeof(double *));
    if (A == NULL) return NULL;
    A[0] = malloc(m*n*sizeof(double));
    if (A[0] == NULL) {
        free(A);
        return NULL;
    }
    for (int i = 1; i < m; i++)
        A[i] = A[0] + i * n;
    return A;
}

// de-allocting memory, allocated with
// dmalloc_2d
void
dfree_2d(double **A) {
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


// print a matrix
void print_matrix(double **A, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
}

// print a vector
void print_vector(double *b, int n){
    for(int i=0; i<n; i++){
        printf("%f ", b[i]);
    }
    printf("\n");
}
