#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "s21_matrix.h"
#include "utils.h"
// #include "utils.h"

int main() {
  // int result_code;
  matrix_t A;
  element_index element = {0, 1};
  srand(time(NULL));

  //  B, result;
  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int ii = 0; ii < A.columns; ii++) {
      A.matrix[i][ii] = rand() % 10;
    }
  }
  // A.matrix[0][0] = 1;
  // A.matrix[0][1] = 2;
  // A.matrix[1][0] = 3;
  // A.matrix[1][1] = 4;
  // A.matrix[][1] = 4;
  // A.matrix[1][1] = 4;
  // s21_create_matrix(2, 2, &B);
  // B.matrix[0][0] = 1.2345678901;
  // B.matrix[0][1] = 2;
  // B.matrix[1][0] = 3;
  // B.matrix[1][1] = 4;
  // s21_create_matrix(2, 2, &result);

  // result_code = s21_sum_matrix(&A, &B, &result);
  print_matrix(A);
  // print_matrix(B);
  // print_matrix(result);
  // printf("RESULT = %d\n", result_code);
  matrix_minor(&A, element);
  // print_matrix(A);

  s21_remove_matrix(&A);
  // s21_remove_matrix(&B);
  // s21_remove_matrix(&result);

  return 0;
}
