#include "tests.h"

#include <check.h>

int main(void) {
  int failed = 0;

  Suite *s21_matrix_test[] = {test_create_matrix(), test_remove_matrix(),
                              test_eq_matrix(), test_sum_matrix(), NULL};

  for (int i = 0; s21_matrix_test[i] != NULL; ++i) {
    SRunner *sr = srunner_create(s21_matrix_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  printf("\033[34m\033[47m============ TESTS FAILED: %d ===========\033[0m\n", failed);
  return 0;
}