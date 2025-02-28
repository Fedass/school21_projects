#include "matrix_suite.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t A, B, result;

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  B.matrix[0][0] = 7;
  B.matrix[0][1] = 8;
  B.matrix[1][0] = 9;
  B.matrix[1][1] = 10;
  B.matrix[2][0] = 11;
  B.matrix[2][1] = 12;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);

  ck_assert_double_eq(result.matrix[0][0], 58);
  ck_assert_double_eq(result.matrix[0][1], 64);
  ck_assert_double_eq(result.matrix[1][0], 139);
  ck_assert_double_eq(result.matrix[1][1], 154);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t A, B, result;

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  B.matrix[0][0] = 7;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 9;
  B.matrix[1][0] = 10;
  B.matrix[1][1] = 11;
  B.matrix[1][2] = 12;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t A, B, result;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 1;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 0;
  B.matrix[2][1] = 0;
  B.matrix[2][2] = 1;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);

  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[0][1], 2);
  ck_assert_double_eq(result.matrix[0][2], 3);
  ck_assert_double_eq(result.matrix[1][0], 4);
  ck_assert_double_eq(result.matrix[1][1], 5);
  ck_assert_double_eq(result.matrix[1][2], 6);
  ck_assert_double_eq(result.matrix[2][0], 7);
  ck_assert_double_eq(result.matrix[2][1], 8);
  ck_assert_double_eq(result.matrix[2][2], 9);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t A, B, result;

  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 1, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  B.matrix[0][0] = 3;
  B.matrix[1][0] = 4;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);

  ck_assert_double_eq(result.matrix[0][0], 11);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_5) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result;

  ck_assert_int_eq(s21_mult_matrix(NULL, &B, &result), MATRIX_INCORRECT);
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, &result), MATRIX_INCORRECT);
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("\033[42m S21_MULT_MATRIX \033[0m");
  TCase *tc = tcase_create("mult_matrix_tc");
  tcase_add_test(tc, s21_mult_matrix_1);
  tcase_add_test(tc, s21_mult_matrix_2);
  tcase_add_test(tc, s21_mult_matrix_3);
  tcase_add_test(tc, s21_mult_matrix_4);
  tcase_add_test(tc, s21_mult_matrix_5);
  tcase_add_test(tc, s21_mult_matrix_6);

  suite_add_tcase(s, tc);
  return s;
}
