#include <check.h>

#include "tests.h"

START_TEST(s21_inverse_matrix_1) {
  int result_code;
  matrix_t A, result, reference;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  s21_create_matrix(3, 3, &reference);
  reference.matrix[0][0] = 1;
  reference.matrix[0][1] = -1;
  reference.matrix[0][2] = 1;
  reference.matrix[1][0] = -38;
  reference.matrix[1][1] = 41;
  reference.matrix[1][2] = -34;
  reference.matrix[2][0] = 27;
  reference.matrix[2][1] = -29;
  reference.matrix[2][2] = 24;

  result_code = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(result_code, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reference);
  s21_remove_matrix(&result);
}

START_TEST(s21_inverse_matrix_2) {
  int result_code;
  matrix_t A, result;
  s21_create_matrix(3, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 9;
  A.matrix[1][1] = 8;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 6;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 4;
  A.matrix[2][3] = 7;

  result_code = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(result_code, 2);
  s21_remove_matrix(&A);
}

START_TEST(s21_inverse_matrix_3) {
  int result_code;
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 9;
  A.matrix[1][1] = 8;
  A.matrix[1][2] = 7;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 4;

  result_code = s21_inverse_matrix(&A, NULL);

  ck_assert_int_eq(result_code, 1);
  s21_remove_matrix(&A);
}

Suite *test_inverse_matrix(void) {
  Suite *suite = suite_create("\033[45m-=S21_inverse_matrix=-\033[0m");
  TCase *test_case = tcase_create("inverse_matrix_test_case");

  tcase_add_test(test_case, s21_inverse_matrix_1);
  tcase_add_test(test_case, s21_inverse_matrix_2);
  tcase_add_test(test_case, s21_inverse_matrix_3);

  suite_add_tcase(suite, test_case);
  return suite;
}