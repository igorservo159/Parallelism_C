#include <stdio.h>
#include <stdlib.h>

int init(int **matrix, int rows, int columns) {
    (*matrix) = (int *) malloc(rows*columns*sizeof(int));
    if((*matrix) == NULL) {
        printf("Allocation error!\n");
        free(*matrix);
        return -1;
    }

    return 0;
}

void free_matrix(int *matrix, int rows) {
    if(matrix == NULL){
        return;
    }

    free(matrix);
}

void set_matrix(int *matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d, %d]:  ", i, j);
            scanf("%d", &matrix[j + (i*columns)]);
        }
    }
    printf("\n");
}

int init_identity(int **matrix, int rows, int columns) {
    (*matrix) == (int *) malloc(rows*columns*sizeof(int));
    if((*matrix) == NULL) {
        printf("Allocation error!\n");
        free(*matrix);
        return -1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            (*matrix)[j + (i*columns)] = (i == j);
        }
    }

    return 0;
}

void show_matrix(int *matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[j + (i*columns)]);
        }
        printf("\n");
    }
    printf("\n");
}

int get_multiplication_element(int *m1, int *m2, int row, int column, int tam) {
    int sum = 0;
    for (int x = 0; x < tam; x++) {
        sum += m1[(row*tam) + x] * m2[(x*tam) + column];
    }
    return sum;
}

int multiply_matrices(int *m1, int *m2, int *res, int m1Rows, int m1Columns, int m2Rows, int m2Columns) {
    if (m1Columns == m2Rows) {
        for (int i = 0; i < m1Rows; i++) {
            for (int j = 0; j < m2Columns; j++) {
                res[j + (i*m2Columns)] = get_multiplication_element(m1, m2, i, j, m1Columns);
            }
        }
        return 0;
    } else {
        printf("Columns number of A is different from rows number of B");
        return -1;
    }
}

int transpose_matrix(int *matrix, int **res, int rows, int columns) {

    int test = init(res, columns, rows);

    if(test == -1) return -1;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            (*res)[i + j*rows] = matrix[j + i*columns];
        }
    }

    return 0;
}

void transpose_quad_in_place(int *matrix, int rows, int columns) {
    int temp;
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < columns; j++) {
            temp = matrix[i * columns + j];
            matrix[i * columns + j] = matrix[j * rows + i];
            matrix[j * rows + i] = temp;
        }
    }
}

void fill(int *matrix, int rows, int columns, int seed){
    srand(seed);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[j + (i*columns)] = rand() % 10;
        }
    }
}