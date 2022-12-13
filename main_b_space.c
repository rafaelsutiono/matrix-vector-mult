#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylib/mylib.h"

#define LOWER 1
#define UPPER 7

int generateRandomInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

void initMat(int* Mat, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            Mat[N*i+j] = generateRandomInt(LOWER,UPPER);
        }
    }
}

void initVec(int* Vec, int N){
    for(int i=0; i<N; i++){
        Vec[i] = generateRandomInt(LOWER,UPPER);
    }
}

int main(void) {

    int N = 3000;
    int* Mat = (int *) malloc(N*N*sizeof(int));
    int* Vec = (int *) malloc(N*sizeof(int));
    int* MV = (int *) malloc(N*sizeof(int));

    initMat(Mat, N);
    printf("Matrix = ");
    initVec(Vec, N);
    printf("Vector = ");

    while (1) {
        matVecMult(Mat, Vec, MV, N);
        }

    return 0;

    
}