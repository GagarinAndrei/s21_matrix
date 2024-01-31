#include "utils.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_matrix.h"

void print_matrix(matrix_t A) {
  for (int i = 0; i < A.rows; i++) {
    for (int ii = 0; ii < A.columns; ii++) printf("|%10.7lf", A.matrix[i][ii]);
    printf("|\n");
  }
  printf("==============================\n");
}

int memory_check_error(double **matrix) {
  int result_code = 0;
  if (matrix == NULL) {
    printf("%s\n", strerror(errno));
    result_code = 1;
  }

  return result_code;
}

int is_correct_matrix(matrix_t A) {
  return (is_structure_null(&A) || A.rows <= 0 || A.columns <= 0 ||
          A.matrix == NULL)
             ? FAILURE
             : SUCCESS;
}

int is_structure_null(matrix_t *A) { return (A == NULL) ? SUCCESS : FAILURE; }

int is_eq_matrix_sizes(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns) ? SUCCESS : FAILURE;
}
