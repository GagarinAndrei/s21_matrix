#include <check.h>

#include "tests.h"

START_TEST(s21_mult_matrix_1) {
  int result_code;
  matrix_t A, B, result, reference;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;
  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  s21_create_matrix(A.rows, B.columns, &reference);
  reference.matrix[0][0] = 9;
  reference.matrix[0][1] = 12;
  reference.matrix[0][2] = 15;
  reference.matrix[1][0] = 19;
  reference.matrix[1][1] = 26;
  reference.matrix[1][2] = 33;
  reference.matrix[2][0] = 29;
  reference.matrix[2][1] = 40;
  reference.matrix[2][2] = 51;

  // s21_create_matrix(A.rows, B.columns, &result);
  result_code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(result_code, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&reference);
  s21_remove_matrix(&result);
}

START_TEST(s21_mult_matrix_2) {
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

  result_code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(result_code, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_mult_matrix_3) {
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

  result_code = s21_mult_matrix(&A, &B, NULL);

  ck_assert_int_eq(result_code, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_mult_matrix_4) {
  int result_code;
  double number = 2.2345;
  matrix_t A, result, reference;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.23456789;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &reference);

  for (int i = 0; i < reference.rows; i++) {
    for (int ii = 0; ii < reference.columns; ii++) {
      reference.matrix[i][ii] = A.matrix[i][ii] * number;
    }
  }

  result_code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(result_code, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reference);
  s21_remove_matrix(&result);
}

START_TEST(s21_mult_matrix_5) {
  int result_code;
  double number = 2.2345;
  matrix_t A, result;
  s21_create_matrix(4, 2, &A);

  result_code = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(result_code, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(s21_mult_matrix_6) {
  int result_code;
  double number = 2.2345;
  matrix_t result;
  s21_create_matrix(2, 2, &result);

  result_code = s21_mult_number(NULL, number, &result);

  ck_assert_int_eq(result_code, 1);
  s21_remove_matrix(&result);
}

START_TEST(s21_mult_matrix_7) {
  int result_code;
  matrix_t A, B, result, reference;
  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 11;
  A.matrix[0][1] = 12;
  A.matrix[0][2] = 13;
  A.matrix[1][0] = 21;
  A.matrix[1][1] = 22;
  A.matrix[1][2] = 23;
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 11;
  B.matrix[0][1] = 12;
  B.matrix[1][0] = 21;
  B.matrix[1][1] = 22;
  B.matrix[2][0] = 31;
  B.matrix[2][1] = 32;
  s21_create_matrix(A.rows, B.columns, &reference);
  reference.matrix[0][0] = A.matrix[0][0] * B.matrix[0][0] +
                           A.matrix[0][1] * B.matrix[1][0] +
                           A.matrix[0][2] * B.matrix[2][0];
  reference.matrix[0][1] = A.matrix[0][0] * B.matrix[0][1] +
                           A.matrix[0][1] * B.matrix[1][1] +
                           A.matrix[0][2] * B.matrix[2][1];
  reference.matrix[1][0] = A.matrix[1][0] * B.matrix[0][0] +
                           A.matrix[1][1] * B.matrix[1][0] +
                           A.matrix[1][2] * B.matrix[2][0];
  reference.matrix[1][1] = A.matrix[1][0] * B.matrix[0][1] +
                           A.matrix[1][1] * B.matrix[1][1] +
                           A.matrix[1][2] * B.matrix[2][1];
  result_code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(result_code, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&reference);
  s21_remove_matrix(&result);
}

Suite *test_mult_matrix(void) {
  Suite *suite = suite_create("\033[45m-=S21_MULT_MATRIX=-\033[0m");
  TCase *test_case = tcase_create("mult_matrix_test_case");

  tcase_add_test(test_case, s21_mult_matrix_1);
  tcase_add_test(test_case, s21_mult_matrix_2);
  tcase_add_test(test_case, s21_mult_matrix_3);
  tcase_add_test(test_case, s21_mult_matrix_4);
  tcase_add_test(test_case, s21_mult_matrix_5);
  tcase_add_test(test_case, s21_mult_matrix_6);
  tcase_add_test(test_case, s21_mult_matrix_7);

  suite_add_tcase(suite, test_case);
  return suite;
}