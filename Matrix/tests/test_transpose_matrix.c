#include "matrix_suite.h"

START_TEST(test_s21_transpose_1) {
  matrix_t A, result;

  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  ck_assert_int_eq(s21_transpose(&A, &result), OK);

  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 2);
  ck_assert_double_eq(result.matrix[0][0], 1.0);
  ck_assert_double_eq(result.matrix[0][1], 4.0);
  ck_assert_double_eq(result.matrix[1][0], 2.0);
  ck_assert_double_eq(result.matrix[1][1], 5.0);
  ck_assert_double_eq(result.matrix[2][0], 3.0);
  ck_assert_double_eq(result.matrix[2][1], 6.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_2) {
  matrix_t A, result;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  ck_assert_int_eq(s21_transpose(&A, &result), OK);

  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 3);
  ck_assert_double_eq(result.matrix[0][0], 1.0);
  ck_assert_double_eq(result.matrix[0][1], 4.0);
  ck_assert_double_eq(result.matrix[0][2], 7.0);
  ck_assert_double_eq(result.matrix[1][0], 2.0);
  ck_assert_double_eq(result.matrix[1][1], 5.0);
  ck_assert_double_eq(result.matrix[1][2], 8.0);
  ck_assert_double_eq(result.matrix[2][0], 3.0);
  ck_assert_double_eq(result.matrix[2][1], 6.0);
  ck_assert_double_eq(result.matrix[2][2], 9.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_3) {
  matrix_t A = {};
  matrix_t result = {};
  ck_assert_int_eq(s21_transpose(&A, &result), MATRIX_INCORRECT);
}
END_TEST

START_TEST(test_s21_transpose_4) {
  matrix_t result;
  ck_assert_int_eq(s21_transpose(NULL, &result), MATRIX_INCORRECT);
}
END_TEST

Suite *test_transpose_matrix(void) {
  Suite *s = suite_create("\033[42m S21_TRANSPOSE_MATRIX \033[0m");
  TCase *tc_core = tcase_create("transpose_tc");

  tcase_add_test(tc_core, test_s21_transpose_1);
  tcase_add_test(tc_core, test_s21_transpose_2);
  tcase_add_test(tc_core, test_s21_transpose_3);
  tcase_add_test(tc_core, test_s21_transpose_4);
  suite_add_tcase(s, tc_core);

  return s;
}
