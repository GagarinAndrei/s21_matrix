#ifndef UTILS_H
#define UTILS_H

typedef struct coordinates_struct {
  int row;
  int column;
} element_index;

#include "s21_matrix.h"

void print_matrix(matrix_t A);
int memory_error(double **matrix);
int is_correct_matrix(matrix_t A);
int is_structure_null(matrix_t *A);
int is_eq_matrix_sizes(matrix_t *A, matrix_t *B);
int is_square_matrix(matrix_t A);
int order_of_matrix(matrix_t *A);

double matrix_minor(matrix_t *A, element_index index);
double minor_of_second_order_matrix(matrix_t *A);
double minor_of_third_order_matrix(matrix_t *A, element_index index);

#endif