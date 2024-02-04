#include <check.h>
#include <stdio.h>

#include "tests.h"

START_TEST(s21_calc_complements_1) {
  int result_code;
  matrix_t A, result, reference;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  s21_create_matrix(2, 2, &reference);
  reference.matrix[0][0] = 4;
  reference.matrix[0][1] = -3;
  reference.matrix[1][0] = -2;
  reference.matrix[1][1] = 1;

  result_code = s21_calc_complements(&A, &result);

  ck_assert_int_eq(result_code, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reference);
  s21_remove_matrix(&result);
}

START_TEST(s21_calc_complements_2) {
  int result_code;
  matrix_t A, reference, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 6;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 76;
  A.matrix[1][2] = 23;
  A.matrix[2][0] = 92;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 2;
  s21_create_matrix(3, 3, &reference);
  reference.matrix[0][0] = 129;
  reference.matrix[0][1] = 2112;
  reference.matrix[0][2] = -6990;
  reference.matrix[1][0] = -2;
  reference.matrix[1][1] = -548;
  reference.matrix[1][2] = 366;
  reference.matrix[2][0] = -364;
  reference.matrix[2][1] = -34;
  reference.matrix[2][2] = 144;

  result_code = s21_calc_complements(&A, &result);

  ck_assert_int_eq(result_code, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reference);
  s21_remove_matrix(&result);
}

START_TEST(s21_calc_complements_3) {
  int result_code;
  matrix_t A, reference, result;
  s21_create_matrix(4, 4, &A);
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
  A.matrix[3][0] = 9;
  A.matrix[3][1] = 1;
  A.matrix[3][2] = 8;
  A.matrix[3][3] = 2;
  s21_create_matrix(4, 4, &reference);
  reference.matrix[0][0] = -155;
  reference.matrix[0][1] = 37;
  reference.matrix[0][2] = 175;
  reference.matrix[0][3] = -21;
  reference.matrix[1][0] = -65;
  reference.matrix[1][1] = 127;
  reference.matrix[1][2] = 85;
  reference.matrix[1][3] = -111;
  reference.matrix[2][0] = 130;
  reference.matrix[2][1] = -110;
  reference.matrix[2][2] = -170;
  reference.matrix[2][3] = 150;
  reference.matrix[3][0] = 50;
  reference.matrix[3][1] = -70;
  reference.matrix[3][2] = -10;
  reference.matrix[3][3] = 30;
  result_code = s21_calc_complements(&A, &result);

  ck_assert_int_eq(result_code, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reference);
  s21_remove_matrix(&result);
}

START_TEST(s21_calc_complements_4) {
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

  result_code = s21_calc_complements(&A, &result);

  ck_assert_int_eq(result_code, 2);
  s21_remove_matrix(&A);
}

START_TEST(s21_calc_complements_5) {
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

  result_code = s21_calc_complements(&A, NULL);

  ck_assert_int_eq(result_code, 1);
  s21_remove_matrix(&A);
}

START_TEST(s21_calc_complements_6) {
  int result_code;
  matrix_t A, result, reference;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;

  s21_create_matrix(1, 1, &reference);
  reference.matrix[0][0] = 1;
  result_code = s21_calc_complements(&A, &result);

  ck_assert_int_eq(result_code, 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&reference);
  s21_remove_matrix(&result);
}

Suite *test_calc_complements(void) {
  Suite *suite = suite_create("\033[45m-=S21_CALC_COMPLEMENTS=-\033[0m");
  TCase *test_case = tcase_create("calc_complements_test_case");

  tcase_add_test(test_case, s21_calc_complements_1);
  tcase_add_test(test_case, s21_calc_complements_2);
  tcase_add_test(test_case, s21_calc_complements_3);
  tcase_add_test(test_case, s21_calc_complements_4);
  tcase_add_test(test_case, s21_calc_complements_5);
  tcase_add_test(test_case, s21_calc_complements_6);

  suite_add_tcase(suite, test_case);
  return suite;
}