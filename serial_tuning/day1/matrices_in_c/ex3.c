#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "matrix.h"

#define mytimer clock
#define delta_t(a,b) (1e3 * (b - a) / CLOCKS_PER_SEC)

bool PRINT_MATRICES = false;

double
experiment(int m, int k, int n){

     // init 
    clock_t start, finish;
    start = mytimer();
    double **A = dmalloc_2d(m, k);
    double **B = dmalloc_2d(k, n);
    double **C = dmalloc_2d(m, n);

    // initialize A and B
    for(int i=0; i<k; i++){
        for(int j=0; j<m; j++){
            A[j][i] = 10 * (1+j) + (1+i);
        }
        for(int j=0; j<n; j++){
            B[i][j] = 20* (1+i) + (1+j);
        }
    }

    
    if (PRINT_MATRICES){
        // print A
        printf("A = \n");
        print_matrix(A, m, k);
  
        // print B
        printf("B = \n");
        print_matrix(B, k, n);
    }

    // C = A * B
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            C[i][j] = 0;
            for(int l=0; l<k; l++){
                C[i][j] = C[i][j] + A[i][l] * B[l][j];
            }
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
        int m = 3;
        int n = 2;
        int k = 5;
        experiment(m, k, n);
    } else {
        int m = 1000;
        int n = 98;
        int k = 90;
        double num_runs = 10;
        double time = 0;
        for(int i=0; i<num_runs; i++){
            time = time + experiment(m, k, n)/num_runs; 
        }
        printf("m = %d \t n = %d \t k = %d \t CPU time =  %.20lf ms.\n", n, m, k, time);
    }
    
    return 0;
};
