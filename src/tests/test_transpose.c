#include <check.h>

#include "tests.h"

START_TEST(s21_transpose_1) {
  int result_code;
  matrix_t A, result, reference;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;
  s21_create_matrix(A.columns, A.rows, &reference);
  reference.matrix[0][0] = 1;
  reference.matrix[0][1] = 3;
  reference.matrix[0][2] = 5;
  reference.matrix[1][0] = 2;
  reference.matrix[1][1] = 4;
  reference.matrix[1][2] = 6;
  s21_create_matrix(A.columns, A.rows, &result);
  result_code = s21_transpose(&A, &result);
  ck_assert_int_eq(result_code, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);
}

START_TEST(s21_transpose_2) {
  int result_code;
  matrix_t A;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;
  result_code = s21_transpose(&A, NULL);
  ck_assert_int_eq(result_code, 1);
}

START_TEST(s21_transpose_3) {
  int result_code;
  matrix_t A, result;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(A.rows, A.rows, &result);
  result_code = s21_transpose(&A, &result);

  ck_assert_int_eq(result_code, 2);
}

Suite *test_transpose(void) {
  Suite *suite = suite_create("\033[45m-=S21_TRANSPOSE=-\033[0m");
  TCase *test_case = tcase_create("transpose_test_case");

  tcase_add_test(test_case, s21_transpose_1);
  tcase_add_test(test_case, s21_transpose_2);
  tcase_add_test(test_case, s21_transpose_3);

  suite_add_tcase(suite, test_case);
  return suite;
}