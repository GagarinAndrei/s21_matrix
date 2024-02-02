#include <check.h>

#include "tests.h"

START_TEST(s21_eq_matrix_1) {
  int result;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_eq_matrix_2) {
  int result;
  matrix_t A;
  matrix_t B;
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

  result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
START_TEST(s21_eq_matrix_3) {
  int result;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_eq_matrix_4) {
  int result;
  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  result = s21_eq_matrix(NULL, &B);

  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&B);
}

Suite *test_eq_matrix(void) {
  Suite *suite = suite_create("\033[45m-=S21_EQ_MATRIX=-\033[0m");
  TCase *test_case = tcase_create("eq_matrix_test_case");

  tcase_add_test(test_case, s21_eq_matrix_1);
  tcase_add_test(test_case, s21_eq_matrix_2);
  tcase_add_test(test_case, s21_eq_matrix_3);
  tcase_add_test(test_case, s21_eq_matrix_4);

  suite_add_tcase(suite, test_case);
  return suite;
}