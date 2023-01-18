#ifndef MATVEC_H
#define MATVEC_H


void matvec(double **A, double *x, double *y, int m, int n);
void matvec_dgemv(double **A, double *x, double *y, int m, int n);

#endif