#include <stdio.h>

#include "s21_matrix.h"
#include "utils.h"

int main() {
  matrix_t A;
  int res = s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  printf("RES = %d\n", res);
  print_matrix(A);
  return 0;
}