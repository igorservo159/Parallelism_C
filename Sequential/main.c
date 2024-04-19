#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int main(int argc, char const *argv[]) {
    if (argc != 5) {
        printf("Use: %s <m1_rows> <m1_columns> <m2_rows> <m2_columns>\n", argv[0]);
        return -1;
    }

    clock_t begin = clock();
    int m1_rows = atoi(argv[1]); int m1_columns = atoi(argv[2]); int m2_rows = atoi(argv[3]); int m2_columns = atoi(argv[4]);

    int *m1 = NULL;
    init(&m1, m1_rows, m1_columns);
    fill(m1, m1_rows, m1_columns, 1);

    int *m2 = NULL;
    init(&m2, m2_rows, m2_columns);
    fill(m2, m2_rows, m2_columns, 2);

    int *transposedM1 = NULL;
    init(&transposedM1, m1_columns, m1_rows);
    transpose_matrix(m1, transposedM1, m1_rows, m1_columns);
    show_matrix(m1, m1_rows, m1_columns);
    show_matrix(transposedM1, m1_columns, m1_rows);

    int *res = NULL;
    init(&res, m1_rows, m2_columns);
    multiply_matrices(m1, m2, res, m1_rows, m1_columns, m2_rows, m2_columns);

    free_matrix(m1, m1_rows);
    free_matrix(m2, m2_rows);
    free_matrix(res, m1_columns);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f s\n", time_spent);

    return 0;
}