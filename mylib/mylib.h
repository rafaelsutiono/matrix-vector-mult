int generateRandomInt(int lower, int upper);
void initMat(int* Mat, int N);
void initVec(int* Vec, int N);
void printMat(int* Mat, int N);
void printVec(int* Vec, int N);
void matVecMult(int* Mat, int* Vec, int* MV, int N);
void test_multiply_vector_matrix(int *Mat, int *Vec, int N, int *vector_expected);