#include <stdio.h>

#include "s21_matrix.h"
// #include "utils.h"

int main() {
  int result_code;
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.2345678901;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  s21_create_matrix(2, 2, &result);

  result_code = s21_sum_matrix(&A, &B, &result);
  print_matrix(A);
  print_matrix(B);
  print_matrix(result);
  printf("RESULT = %d\n", result_code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  return 0;
}
