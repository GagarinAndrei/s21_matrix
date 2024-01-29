#ifndef TESTS_H
#define TESTS_H
#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_matrix.h"
#include "../utils.h"

Suite *test_create_matrix(void);
Suite *test_remove_matrix(void);
Suite *test_eq_matrix(void);
Suite *test_sum_matrix(void);

#endif