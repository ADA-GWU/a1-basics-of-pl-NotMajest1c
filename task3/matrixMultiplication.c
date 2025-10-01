#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** allocateMatrix(int rows, int cols) {
    int **mat = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        mat[i] = malloc(cols * sizeof(int));
    return mat;
}

void freeMatrix(int **mat, int rows) {
    for (int i = 0; i < rows; i++)
        free(mat[i]);
    free(mat);
}

void fillRandomMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i][j] = rand() % 10;
}

void matrixMultiplication(int **A, int **B, int **C, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void printMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void testMatrixMultiplication() {
    int A_test[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B_test[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int expected[2][2] = {{58, 64}, {139, 154}};
    int C[2][2] = {0};

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++)
                C[i][j] += A_test[i][k] * B_test[k][j];

    int pass = 1;
    for (int i = 0; i < 2 && pass; i++)
        for (int j = 0; j < 2 && pass; j++)
            if (C[i][j] != expected[i][j]) pass = 0;

    if (pass) printf("Test passed\n");
    else printf("Test failed\n");
}

int main() {
    srand(time(NULL)); // for seeding the random number generator

    int rows_A, cols_A, rows_B, cols_B;

    printf("Input number of Rows in A: ");
    scanf("%d", &rows_A);
    printf("Input number of Cols in A: ");
    scanf("%d", &cols_A);

    printf("Input number of Rows in B: ");
    scanf("%d", &rows_B);
    printf("Input number of Cols in B: ");
    scanf("%d", &cols_B);

    if (cols_A != rows_B) {
        printf("Error: A's columns must equal B's rows for matrix multiplication, please run the program again\n");
        return 1;
    }

    int **A = allocateMatrix(rows_A, cols_A);
    int **B = allocateMatrix(rows_B, cols_B);
    int **multAB = allocateMatrix(rows_A, cols_B);

    fillRandomMatrix(A, rows_A, cols_A);
    fillRandomMatrix(B, rows_B, cols_B);

    clock_t start = clock();
    matrixMultiplication(A, B, multAB, rows_A, cols_A, cols_B);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nMatrix A:\n");
    printMatrix(A, rows_A, cols_A);
    printf("Matrix B:\n");
    printMatrix(B, rows_B, cols_B);
    printf("A x B = \n");
    printMatrix(multAB, rows_A, cols_B);
    printf("Time: %.8f sec\n", time_taken);

    testMatrixMultiplication();

    freeMatrix(A, rows_A);
    freeMatrix(B, rows_B);
    freeMatrix(multAB, rows_A);

    return 0;
}
