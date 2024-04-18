#ifndef MATRIX_H
#define MATRIX_H

int init(int **matrix, int rows, int columns);
void free_matrix(int *matrix, int rows);
void set_matrix(int *matrix, int rows, int columns);
int init_identity(int **matrix, int rows, int columns);
void show_matrix(int *matrix, int rows, int columns);
int multiply_matrices(int *m1, int *m2, int *res, int m1R, int m1C, int m2R, int m2C);
int get_multiplication_element(int *m1, int *m2, int row, int column, int tam);
void fill(int **matrix, int rows, int columns, int seed);

#endif