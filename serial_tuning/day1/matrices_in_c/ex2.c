#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "matrix.h"

#define mytimer clock
#define delta_t(a,b) (1e3 * (b - a) / CLOCKS_PER_SEC)

bool PRINT_MATRICES = true;

double
experiment(int m, int n){

     // init 
    clock_t start, finish;
    start = mytimer();
    double **A = dmalloc_2d(m, n);
    double *b = dmalloc_1d(n);
    double *c = dmalloc_1d(m);

    // initialize A and B
    

    for(int l=0; l<n; l++){
        b[l] = 3.0 * l;
        for(int k=0; k<m; k++){
            A[k][l] = 1.0 * k + l;
        }
    }

    
    if (PRINT_MATRICES){
        // print A
        printf("A = \n");
        print_matrix(A, m, n);
  
        // print B
        printf("b = \n");
        print_vector(b, n);
    }

    // c = A * b
    for(int i=0; i<m; i++){
        c[i] = 0;
        for(int j=0; j<n; j++){
            c[i] += A[i][j] * b[j];
        }
    }

    // print C
    if (PRINT_MATRICES){
        printf("c = \n");
        print_vector(c, m);
    }
    

    // free the memory
    dfree_2d(A);
    dfree_1d(b);
    dfree_1d(c);

    // print time
    finish = mytimer();
    double time = delta_t(start, finish);
    
    return time;
}

int 
main(){
    if (PRINT_MATRICES){
        int m = 10;
        int n = 10;
        experiment(m, n);
    } else {
        int m = 1000;
        int n = 1000;
        double num_runs = 10;
        double time = 0;
        for(int i=0; i<num_runs; i++){
            time = time + experiment(m, n)/num_runs; 
        }
        printf("m = %d \t n = %d \t CPU time =  %.20lf ms.\n", n, m, time);
    }
    
    return 0;
};
