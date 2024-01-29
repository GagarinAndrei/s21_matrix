#include <check.h>

#include "tests.h"

START_TEST(s21_create_matrix_1) {
  matrix_t A;
  int return_value = s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_double_eq(return_value, 0);
}

START_TEST(s21_create_matrix_2) {
  matrix_t A;
  int return_value = s21_create_matrix(-3, 2, &A);
  ck_assert_double_eq(return_value, 1);
}

START_TEST(s21_create_matrix_3) {
  matrix_t A;
  int return_value = s21_create_matrix(-3, -2, &A);
  ck_assert_double_eq(return_value, 1);
}

START_TEST(s21_create_matrix_4) {
  int return_value = s21_create_matrix(-3, -2, NULL);
  ck_assert_double_eq(return_value, 1);
}

START_TEST(s21_create_matrix_5) {
  int return_value = s21_create_matrix(2, 2, NULL);
  ck_assert_double_eq(return_value, 1);
}

Suite *test_create_matrix(void) {
  Suite *suite = suite_create("\033[45m-=S21_CREATE_MATRIX=-\033[0m");
  TCase *test_case = tcase_create("create_matrix_test_case");

  tcase_add_test(test_case, s21_create_matrix_1);
  tcase_add_test(test_case, s21_create_matrix_2);
  tcase_add_test(test_case, s21_create_matrix_3);
  tcase_add_test(test_case, s21_create_matrix_4);
  tcase_add_test(test_case, s21_create_matrix_5);

  suite_add_tcase(suite, test_case);
  return suite;
}