#include "utils.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_matrix.h"

void print_matrix(matrix_t A) {
  for (int i = 0; i < A.rows; i++) {
    for (int ii = 0; ii < A.columns; ii++) printf("%lf ", A.matrix[i][ii]);
    printf("\n");
  }
}

int memory_check_error(double **matrix) {
  int result_code = 0;
  if (matrix == NULL) {
    printf("%s\n", strerror(errno));
    result_code = 1;
  }

  return result_code;
}