#include "matrix_suite.h"

START_TEST(s21_sum_matrix_1) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = 8;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 6.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 8.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 10.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], 12.0, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 2, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(s21_sum_matrix(NULL, &B, &result), MATRIX_INCORRECT);
  ck_assert_int_eq(s21_sum_matrix(&A, NULL, &result), MATRIX_INCORRECT);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), MATRIX_INCORRECT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 0;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 0.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 0.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 0.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], 0.0, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = 2.2;
  A.matrix[1][0] = 3.3;
  A.matrix[1][1] = 4.4;

  B.matrix[0][0] = 5.5;
  B.matrix[0][1] = 6.6;
  B.matrix[1][0] = 7.7;
  B.matrix[1][1] = 8.8;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 6.6, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 8.8, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 11.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], 13.2, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *test_sum_matrix(void) {
  Suite *s = suite_create("\033[42m S21_SUM_MATRIX \033[0m");
  TCase *tc = tcase_create("sum_tc");

  tcase_add_test(tc, s21_sum_matrix_1);
  tcase_add_test(tc, s21_sum_matrix_2);
  tcase_add_test(tc, s21_sum_matrix_3);
  tcase_add_test(tc, s21_sum_matrix_4);
  tcase_add_test(tc, s21_sum_matrix_5);

  suite_add_tcase(s, tc);
  return s;
}
