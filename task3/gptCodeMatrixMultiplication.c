#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Allocates a single contiguous 1D array to simulate a 2D matrix
int* allocateMatrixContiguous(int rows, int cols) {
    return (int*) malloc(rows * cols * sizeof(int));
}

// Frees the contiguous matrix
void freeMatrixContiguous(int* matrix) {
    free(matrix);
}

// Helper to access element at (i, j)
int getElement(int* matrix, int cols, int i, int j) {
    return matrix[i * cols + j];
}

void setElement(int* matrix, int cols, int i, int j, int value) {
    matrix[i * cols + j] = value;
}

// Fill matrix with random integers in [min, max]
void fillMatrixRandomContiguous(int* matrix, int rows, int cols, int min, int max) {
    for (int i = 0; i < rows * cols; i++)
        matrix[i] = min + rand() % (max - min + 1);
}

// Multiply matrices A and B into result, using contiguous layout
void multiplyMatricesContiguous(int* A, int* B, int* result, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++)
                sum += getElement(A, colsA, i, k) * getElement(B, colsB, k, j);
            setElement(result, colsB, i, j, sum);
        }
}

// Print contiguous matrix
void printMatrixContiguous(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d", getElement(matrix, cols, i, j));
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    printf("Matrix Multiplication\n");
    printf("Please enter the dimensions for the matrices.\n");

    int rowsA, colsA, rowsB, colsB;
    printf("Enter the number of rows in matrix A: ");
    scanf("%d", &rowsA);
    printf("Enter the number of columns in matrix A: ");
    scanf("%d", &colsA);
    printf("Enter the number of rows in matrix B: ");
    scanf("%d", &rowsB);
    printf("Enter the number of columns in matrix B: ");
    scanf("%d", &colsB);

    if (colsA != rowsB) {
        printf("Error: Number of columns in A must be equal to number of rows in B for multiplication.\n");
        return 1;
    }

    int* matrixA = allocateMatrixContiguous(rowsA, colsA);
    int* matrixB = allocateMatrixContiguous(rowsB, colsB);
    int* matrixResult = allocateMatrixContiguous(rowsA, colsB);

    fillMatrixRandomContiguous(matrixA, rowsA, colsA, 0, 10);
    fillMatrixRandomContiguous(matrixB, rowsB, colsB, 0, 10);

    clock_t startTime = clock();
    multiplyMatricesContiguous(matrixA, matrixB, matrixResult, rowsA, colsA, colsB);
    clock_t endTime = clock();
    double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("\nMatrix A:\n");
    printMatrixContiguous(matrixA, rowsA, colsA);
    printf("Matrix B:\n");
    printMatrixContiguous(matrixB, rowsB, colsB);
    printf("Result of A x B:\n");
    printMatrixContiguous(matrixResult, rowsA, colsB);
    printf("Execution time: %.10f seconds\n", elapsedTime);

    freeMatrixContiguous(matrixA);
    freeMatrixContiguous(matrixB);
    freeMatrixContiguous(matrixResult);

    return 0;
}
