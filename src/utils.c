#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_matrix.h"

int is_correct_matrix(matrix_t A) {
  return (A.rows <= 0 || A.columns <= 0 || A.matrix == NULL) ? FAILURE
                                                             : SUCCESS;
}

int is_structure_null(matrix_t *A) { return (A == NULL) ? SUCCESS : FAILURE; }

int is_eq_matrix_sizes(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns) ? SUCCESS : FAILURE;
}

int is_square_matrix(matrix_t *A) {
  return (A->rows == A->columns) ? SUCCESS : FAILURE;
}
