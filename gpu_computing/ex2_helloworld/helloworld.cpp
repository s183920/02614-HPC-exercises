#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int bug = 0;
    if (argc > 1) bug = atoi(argv[1]);

    #pragma omp target teams parallel \
        num_teams(4) thread_limit(64)
    {
        int tid = omp_get_thread_num();
        int nthreads = omp_get_num_threads();
        int team = omp_get_team_num();
        int global_tid = tid+omp_get_team_num()*omp_get_num_threads();
        int global_nthreads = omp_get_num_threads() * omp_get_num_teams();
        
        if (bug == 1){
            if (global_tid == 100) { int *a = (int*) 0x10000; *a = 0; }
        }

        printf("Hello world! I'm thread %d of %d in team %d. My global thread id is %d out of %d\n",
            tid, nthreads, team, global_tid, global_nthreads);
    } // end of parallel region
    return 0;   
}