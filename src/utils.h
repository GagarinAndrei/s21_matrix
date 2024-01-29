#ifndef UTILS_H
#define UTILS_H
#include "s21_matrix.h"

void print_matrix(matrix_t A);
int memory_error(double** matrix);
int is_correct_matrix(matrix_t A);
int is_structure_null(matrix_t* A);
int is_eq_matrix_sizes(matrix_t* A, matrix_t* B);

#endif