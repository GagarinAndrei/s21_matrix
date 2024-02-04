#ifndef UTILS_H
#define UTILS_H

typedef struct {
  int row;
  int column;
} element_index;

#include "s21_matrix.h"

int is_correct_matrix(matrix_t A);
int is_structure_null(matrix_t *A);
int is_eq_matrix_sizes(matrix_t *A, matrix_t *B);
int is_square_matrix(matrix_t *A);
int order_of_matrix(matrix_t *A);

void matrix_of_minors(matrix_t *A, matrix_t *result);
void minor_of_matrix(matrix_t *A, int row, int column, matrix_t *result);

#endif