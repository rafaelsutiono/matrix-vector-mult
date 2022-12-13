#include <stdio.h>

void printMat(int* Mat, int N){

    printf("[");
    for(int i=0; i<N; i++){
        printf("\n");
        for(int j=0; j<N; j++){
            printf("%d,\t",Mat[N*i+j]);
        }
    }
    printf("]\n");

}

void printVec(int* Vec, int N){
    printf("[");
    for(int i=0; i<N; i++){
        printf("\n");
        printf("%d,\t",Vec[i]);
    }
    printf("]\n");
}

void matVecMult(int* Mat, int* Vec, int* MV, int N){

    for(int i=0; i<N; i++){
        MV[i]=0;
        for(int j=0; j<N; j++){
            MV[i] += Mat[N*i+j] * Vec[j];
        }
    }

}