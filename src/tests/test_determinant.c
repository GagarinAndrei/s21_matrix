#include <check.h>

#include "tests.h"

START_TEST(s21_determinant_1) {
  int result_code;
  double determinant;
  double reference = -40;
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  result_code = s21_determinant(&A, &determinant);

  ck_assert_int_eq(result_code, 0);
  ck_assert_double_eq_tol(determinant, reference, ACCURACY);
  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_2) {
  int result_code;
  double determinant;
  matrix_t A;
  s21_create_matrix(4, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  A.matrix[3][2] = 1;
  A.matrix[3][2] = 1;
  A.matrix[3][2] = 1;

  result_code = s21_determinant(&A, &determinant);

  ck_assert_int_eq(result_code, 2);
  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_3) {
  int result_code;
  double determinant;
  double reference = 0;
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  result_code = s21_determinant(&A, &determinant);

  ck_assert_int_eq(result_code, 0);
  ck_assert_double_eq_tol(determinant, reference, ACCURACY);
  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_4) {
  int result_code;
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  result_code = s21_determinant(&A, NULL);

  ck_assert_int_eq(result_code, 1);
  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_5) {
  int result_code;
  double result;

  result_code = s21_determinant(NULL, &result);

  ck_assert_int_eq(result_code, 1);
}

Suite *test_determinant(void) {
  Suite *suite = suite_create("\033[45m-=S21_DETERMINANT=-\033[0m");
  TCase *test_case = tcase_create("determinant_test_case");

  tcase_add_test(test_case, s21_determinant_1);
  tcase_add_test(test_case, s21_determinant_2);
  tcase_add_test(test_case, s21_determinant_3);
  tcase_add_test(test_case, s21_determinant_4);
  tcase_add_test(test_case, s21_determinant_5);

  suite_add_tcase(suite, test_case);
  return suite;
}