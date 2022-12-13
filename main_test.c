#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

void test_multiply_vector_matrix(int *Mat, int *Vec, int N, int *vector_expected){
    int *MV = (int*)malloc(N * sizeof(int));

    if (MV == NULL){
        printf("Malloc is failed!\n");
        return;
    }
    
    matVecMult(Mat, Vec, MV, N);

    int i;
    for (i = 0; i < N; i++){
        printf("Actual V[%d] = %-2d; Expected V[%d] = %-2d\n", i, MV[i], i, vector_expected[i]);
        assert(MV[i] == vector_expected[i]);
    }
}

int main(){
    int total_test_cases = 3;
    int N = 3;

    int matrix_input_test_case[3][7] = {
        {9,7,6,7,0,3,0,8,9},
        {4,7,2,3,5,5,1,2,2},
        {2,3,1,5,1,5,8,1,4}
    };

    int vector_input_test_case[3][3] = {
        {9, 0, 2},
        {8, 9, 6},
        {2, 0, 0}
    };

    int vector_expected_test_case[3][3] = {
        {67, 54, 27},
        {21, 97, 58},
        {43, 72, 101}
    };

    int i;
    for (i = 0; i < total_test_cases; i++)
    {
        printf("Test #%d:\n", i + 1);

        test_multiply_vector_matrix(
        matrix_input_test_case[i],
        vector_input_test_case[i],
        N,
        vector_expected_test_case[i]
        );
         
        printf("\n");
    }

    return 0;
}