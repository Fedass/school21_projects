#include "matrix_suite.h"

START_TEST(test_mult_number_1) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  double number = 2.0;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 2.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 6.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], 8.0, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_2) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 5.0;
  A.matrix[0][1] = -3.0;
  A.matrix[1][0] = 7.0;
  A.matrix[1][1] = 2.0;

  double number = 0.0;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 0.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 0.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 0.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], 0.0, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_3) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = -1.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -2.0;

  double number = -3.0;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);

  ck_assert_double_eq_tol(result.matrix[0][0], -3.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 3.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], -6.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], 6.0, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_4) {
  matrix_t A = {0}, result;
  double number = 2.0;

  ck_assert_int_eq(s21_mult_number(NULL, number, &result), MATRIX_INCORRECT);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), MATRIX_INCORRECT);
}
END_TEST

START_TEST(test_mult_number_5) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1e10;
  A.matrix[0][1] = -1e10;
  A.matrix[1][0] = 1e-10;
  A.matrix[1][1] = -1e-10;

  double number = 1e5;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 1e15, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], -1e15, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 1e-5, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], -1e-5, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_6) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 42.0;

  double number = 1.0;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 42.0, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_7) {
  matrix_t A, result;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = -1.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -2.0;

  double positive_infinity = INFINITY;
  ck_assert_int_eq(s21_mult_number(&A, positive_infinity, &result),
                   CALCULATION_ERROR);

  double negative_infinity = -INFINITY;
  ck_assert_int_eq(s21_mult_number(&A, negative_infinity, &result),
                   CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite *test_mult_number(void) {
  Suite *s = suite_create("\033[42m S21_MULT_NUMBER \033[0m");
  TCase *tc = tcase_create("mult_number_tc");

  tcase_add_test(tc, test_mult_number_1);
  tcase_add_test(tc, test_mult_number_2);
  tcase_add_test(tc, test_mult_number_3);
  tcase_add_test(tc, test_mult_number_4);
  tcase_add_test(tc, test_mult_number_5);
  tcase_add_test(tc, test_mult_number_6);
  tcase_add_test(tc, test_mult_number_7);
  suite_add_tcase(s, tc);
  return s;
}
