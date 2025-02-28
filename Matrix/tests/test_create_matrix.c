#include "matrix_suite.h"

START_TEST(s21_create_matrix_1) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  ck_assert_int_eq(s21_create_matrix(2, 2, NULL), MATRIX_INCORRECT);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(5, 0, &A), MATRIX_INCORRECT);
}

START_TEST(s21_create_matrix_4) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(-4, -4, &A), MATRIX_INCORRECT);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(1000, 1000, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(0, 5, &A), MATRIX_INCORRECT);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(-1, 5, &A), MATRIX_INCORRECT);
}
END_TEST

START_TEST(s21_create_matrix_8) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j], 0.0, 1e-7);
    }
  }
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_9) {
  matrix_t A;
  int result = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(result, MATRIX_INCORRECT);
}
END_TEST

START_TEST(s21_create_matrix_10) {
  matrix_t result;
  int rows = INT_MAX;
  int columns = INT_MAX;
  int error = s21_create_matrix(rows, columns, &result);

  ck_assert_int_eq(error, MATRIX_INCORRECT);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *s = suite_create("\033[42m S21_CREATE_MATRIX \033[0m");
  TCase *tc = tcase_create("create_tc");
  tcase_add_test(tc, s21_create_matrix_1);
  tcase_add_test(tc, s21_create_matrix_2);
  tcase_add_test(tc, s21_create_matrix_3);
  tcase_add_test(tc, s21_create_matrix_4);
  tcase_add_test(tc, s21_create_matrix_5);
  tcase_add_test(tc, s21_create_matrix_6);
  tcase_add_test(tc, s21_create_matrix_7);
  tcase_add_test(tc, s21_create_matrix_8);
  tcase_add_test(tc, s21_create_matrix_9);
  tcase_add_test(tc, s21_create_matrix_10);

  suite_add_tcase(s, tc);
  return s;
}