/*
For a upper triangular matrix, all non-zero elements must have their row index less than or 
equal to their column index. 
For a lower triangular matrix, all non-zero elements must have their row index greater than 
or equal to their column index.
*/


#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int row;
    int col;
    int value;
} Tuple;

int toTupleForm(int matrix[MAX_ROWS][MAX_COLS], Tuple tuples[MAX_ROWS * MAX_COLS], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                tuples[count].row = i;
                tuples[count].col = j;
                tuples[count].value = matrix[i][j];
                count++;
            }
        }
    }
    return count; 
}

int isUpperTriangular(Tuple tuples[MAX_ROWS * MAX_COLS], int nonZeroCount) {
    for (int i = 0; i < nonZeroCount; i++) {
        if (tuples[i].row > tuples[i].col) 
            return 0; 
    }
    return 1; 
}

int isLowerTriangular(Tuple tuples[MAX_ROWS * MAX_COLS], int nonZeroCount) {
    for (int i = 0; i < nonZeroCount; i++) {
        if (tuples[i].row < tuples[i].col) 
            return 0; 
    }
    return 1; 
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS] = {
        {1, 0, 0, 0},
        {2, 3, 0, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 10}
    };

    int rows = 4, cols = 4;
    Tuple tuples[MAX_ROWS * MAX_COLS];

    int nonZeroCount = toTupleForm(matrix, tuples, rows, cols);

    printf("Sparse Matrix in Tuple Form:\n");
    for (int i = 0; i < nonZeroCount; i++) 
        printf("Row: %d, Col: %d, Value: %d\n", tuples[i].row, tuples[i].col, tuples[i].value);

    if (isUpperTriangular(tuples, nonZeroCount)) 
        printf("The matrix is upper triangular.\n");
    else 
        printf("The matrix is not upper triangular.\n");

    if (isLowerTriangular(tuples, nonZeroCount)) 
        printf("The matrix is lower triangular.\n");
    else 
        printf("The matrix is not lower triangular.\n");
    return 0;
}
