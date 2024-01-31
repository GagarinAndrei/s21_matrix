#include <check.h>

#include "tests.h"

START_TEST(s21_remove_matrix_1) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}

START_TEST(s21_remove_matrix_2) {
  matrix_t A;
  s21_create_matrix(-3, 2, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}

// START_TEST(s21_remove_matrix_3) {
//   matrix_t matrix;
//   s21_remove_matrix(&matrix);
//   ck_assert_ptr_null(matrix.matrix);
//   ck_assert_int_eq(matrix.rows, 0);
//   ck_assert_int_eq(matrix.columns, 0);
// }
// END_TEST

Suite *test_remove_matrix(void) {
  Suite *suite = suite_create("\033[45m-=S21_REMOVE_MATRIX=-\033[0m");
  TCase *test_case = tcase_create("remove_matrix_test_case");

  tcase_add_test(test_case, s21_remove_matrix_1);
  tcase_add_test(test_case, s21_remove_matrix_2);
  // tcase_add_test(test_case, s21_remove_matrix_3);

  suite_add_tcase(suite, test_case);
  return suite;
}