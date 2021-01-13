#include <stdio.h>
#include <omp.h>

#include "exo1.h"

void    exe_exo1() {

#pragma omp parallel for
    for(int i=0;i<10;i++){
        printf("thread [%d/%d->max[%d]] exe[%d] - nbProc[%d] --> parallel[%d]\n", omp_get_thread_num() + 1, omp_get_num_threads(), omp_get_max_threads(), i, omp_get_num_procs(), omp_in_parallel());
    }
}