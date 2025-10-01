#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int rows, cols;
    printf("Input number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Input number of columns in the matrix: ");
    scanf("%d", &cols);

    int **matrix = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        matrix[i] = malloc(cols * sizeof(int));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 11;

    printf("\nGenerated Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }

    int row_start, row_end, col_start, col_end;
    printf("Enter the slice ranges for rows and columns (start inclusive, end exclusive):\n");
    printf("Start row (0 to %d): ", rows-1);
    scanf("%d", &row_start);
    printf("End row (1 to %d): ", rows);
    scanf("%d", &row_end);
    printf("Start column (0 to %d): ", cols-1);
    scanf("%d", &col_start);
    printf("End column (1 to %d): ", cols);
    scanf("%d", &col_end);

    // Swap if end < start
    if (row_end < row_start) {
        int temp = row_start;
        row_start = row_end;
        row_end = temp;
    }
    if (col_end < col_start) {
        int temp = col_start;
        col_start = col_end;
        col_end = temp;
    }

    printf("\nSliced Submatrix:\n");
    for (int i = row_start; i < row_end; i++) {
        for (int j = col_start; j < col_end; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
