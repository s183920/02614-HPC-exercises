#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "matrix.h"

#define mytimer clock
#define delta_t(a,b) (1e3 * (b - a) / CLOCKS_PER_SEC)

bool PRINT_MATRICES = false;

double
experiment(int m, int n){

     // init 
    clock_t start, finish;
    start = mytimer();
    double **A = dmalloc_2d(m, n);
    double **B = dmalloc_2d(m, n);
    double **C = dmalloc_2d(m, n);

    // initialize A and B
    for(int k=0; k<m; k++){
        for(int l=0; l<n; l++){
            A[k][l] = 1.0 * k + l;
            B[k][l] = 2.0 * k + l;
        }
    }

    
    if (PRINT_MATRICES){
        // print A
        printf("A = \n");
        print_matrix(A, m, n);
  
        // print B
        printf("B = \n");
        print_matrix(B, m, n);
    }

    // C = A + B
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // print C
    if (PRINT_MATRICES){
        printf("C = \n");
        print_matrix(C, m, n);
    }
    

    // free the memory
    dfree_2d(A);
    dfree_2d(B);
    dfree_2d(C);

    // print time
    finish = mytimer();
    double time = delta_t(start, finish);
    
    return time;
}

int 
main(){
    if (PRINT_MATRICES){
        int m = 10;
        int n = 9;
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




