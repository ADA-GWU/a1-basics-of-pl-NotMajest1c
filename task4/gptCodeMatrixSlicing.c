#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** createMatrix(int rows, int cols) {
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

void fillMatrixRandom(int **mat, int rows, int cols, int minVal, int maxVal) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i][j] = rand() % (maxVal - minVal + 1) + minVal;
}

void printMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d", mat[i][j]);
        printf("\n");
    }
}

void sliceAndPrint(int **mat, int rowStart, int rowEnd, int colStart, int colEnd) {
    if (rowEnd < rowStart) {
        int temp = rowStart; rowStart = rowEnd; rowEnd = temp;
    }
    if (colEnd < colStart) {
        int temp = colStart; colStart = colEnd; colEnd = temp;
    }

    printf("\nSliced Submatrix:\n");
    for (int i = rowStart; i < rowEnd; i++) {
        for (int j = colStart; j < colEnd; j++)
            printf("%4d", mat[i][j]);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int rows, cols;
    printf("Input number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Input number of columns in the matrix: ");
    scanf("%d", &cols);

    int **matrix = createMatrix(rows, cols);
    fillMatrixRandom(matrix, rows, cols, 0, 10);

    printf("\nGenerated Matrix:\n");
    printMatrix(matrix, rows, cols);

    int rowStart, rowEnd, colStart, colEnd;
    printf("Enter the slice ranges for rows and columns (start inclusive, end exclusive):\n");
    printf("Start row (0 to %d): ", rows-1); scanf("%d", &rowStart);
    printf("End row (1 to %d): ", rows); scanf("%d", &rowEnd);
    printf("Start column (0 to %d): ", cols-1); scanf("%d", &colStart);
    printf("End column (1 to %d): ", cols); scanf("%d", &colEnd);

    sliceAndPrint(matrix, rowStart, rowEnd, colStart, colEnd);
    freeMatrix(matrix, rows);

    return 0;
}
