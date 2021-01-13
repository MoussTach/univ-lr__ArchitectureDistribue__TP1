#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "exo3.h"

int **createVector(int h, int v) {
    int **res;

    if (!(res = malloc(sizeof(int *) * v)))
        return NULL;

    for (int i = 0; i < v; i++) {
        if (!(res[i] = malloc((sizeof(int) * h))))
            return NULL;

        for (int j = 0; j < h; j++) {
            res[i][j] = rand() % 10;
        }
    }

    return res;
}

int **multMatrice(int **m1, int **m2, int h, int v) {
    int **res;

    if (!(res = malloc(sizeof(int *) * v)))
        return NULL;

    for (int i = 0; i < v; i++) {
        if (!(res[i] = malloc((sizeof(int) * h))))
            return NULL;

        for (int j = 0; j < h; j++) {
            res[i][j] = 0;
        }
    }

    printf("\n");
#pragma omp parallel for
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < h; j++) {
            res[i][j] = m1[i][j] * m2[i][j];
            printf("thread [%02d]> [%02d]*[%02d]=[%02d]\n", omp_get_thread_num() + 1, m1[i][j], m2[i][j], res[i][j]);
        }
    }

    return res;
}

void    exe_exo3() {

    int h = 3;
    int v = 3;

    srand(time(NULL));
    int **m1 = createVector(h, v);
    int **m2 = createVector(h, v);

    printf("  m1\t\t*\t  m2\n");
    for (int i = 0; i < h; ++i) {
        //m1
        for (int j = 0; j < v; j++) {
            printf("%02d ", m1[i][j]);
        }

        printf("\t|\t");

        //m2
        for (int j = 0; j < v; j++) {
            printf("%02d ", m2[i][j]);
        }
        printf("\n");
    }

    int **m3 = multMatrice(m1, m2, h, v);
    printf("\n\t  m3\n");
    for (int i = 0; i < h; ++i) {
        printf("\t");

        //m3
        for (int j = 0; j < v; j++) {
            printf("%02d ", m3[i][j]);
        }
        printf("\n");
    }
}