#ifndef __MATRIX_H
#define __MATRIX_H

#include <stdio.h>
#include <stdlib.h>

//  allocate a double-prec m x n matrix
double ** dmalloc_2d(int m, int n);

// de-allocting memory, allocated with
// dmalloc_2d
void dfree_2d(double **A);


//  allocate a double-prec n long vector
double * dmalloc_1d(int n);

// de-allocting memory, allocated with dmalloc_1d
void dfree_1d(double *b);


// print a matrix
void print_matrix(double **A, int m, int n);

// print a vector
void print_vector(double *b, int n);

#endif