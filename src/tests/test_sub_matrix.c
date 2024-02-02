#include <check.h>

#include "tests.h"

START_TEST(s21_sub_matrix_1) {
  int result_code;
  matrix_t A, B, result, reference;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.23456789;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  s21_create_matrix(2, 2, &reference);
  reference.matrix[0][0] = 0.2345678;
  reference.matrix[0][1] = 0;
  reference.matrix[1][0] = 0;
  reference.matrix[1][1] = 0;
  s21_create_matrix(2, 2, &result);

  result_code = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(result_code, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&reference);
  s21_remove_matrix(&result);
}

START_TEST(s21_sub_matrix_2) {
  int result_code;
  matrix_t A, B, result;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 2;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  s21_create_matrix(2, 2, &result);

  result_code = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(result_code, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(s21_sub_matrix_3) {
  int result_code;
  matrix_t A, B;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  result_code = s21_sub_matrix(&A, &B, NULL);

  ck_assert_int_eq(result_code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

Suite *test_sub_matrix(void) {
  Suite *suite = suite_create("\033[45m-=S21_SUB_MATRIX=-\033[0m");
  TCase *test_case = tcase_create("sub_matrix_test_case");

  tcase_add_test(test_case, s21_sub_matrix_1);
  tcase_add_test(test_case, s21_sub_matrix_2);
  tcase_add_test(test_case, s21_sub_matrix_3);

  suite_add_tcase(suite, test_case);
  return suite;
}