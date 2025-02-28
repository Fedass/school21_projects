#include "matrix_suite.h"

START_TEST(s21_remove_matrix_1) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);

  s21_remove_matrix(&A);

  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&A);

  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_3) { s21_remove_matrix(NULL); }
END_TEST

START_TEST(s21_remove_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  s21_remove_matrix(&A);

  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  s21_remove_matrix(&A);

  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_6) {
  matrix_t A = {NULL, 3, 3};
  s21_remove_matrix(&A);

  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

Suite *test_remove_matrix(void) {
  Suite *s = suite_create("\033[42m S21_REMOVE_MATRIX \033[0m");
  TCase *tc = tcase_create("remove_tc");
  tcase_add_test(tc, s21_remove_matrix_1);
  tcase_add_test(tc, s21_remove_matrix_2);
  tcase_add_test(tc, s21_remove_matrix_3);
  tcase_add_test(tc, s21_remove_matrix_4);
  tcase_add_test(tc, s21_remove_matrix_5);
  tcase_add_test(tc, s21_remove_matrix_6);

  suite_add_tcase(s, tc);
  return s;
}