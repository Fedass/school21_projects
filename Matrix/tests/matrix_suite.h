#ifndef MATRIX_SUITE_H
#define MATRIX_SUITE_H

#include <check.h>

#include "../s21_matrix.h"

Suite *test_create_matrix(void);
Suite *test_remove_matrix(void);
Suite *test_eq_matrix(void);
Suite *test_sum_matrix(void);
Suite *test_sub_matrix(void);
Suite *test_mult_number(void);
Suite *test_mult_matrix(void);
Suite *test_transpose_matrix(void);
Suite *test_calc_complements(void);
Suite *test_determinate(void);
Suite *test_inverse_matrix(void);
#endif