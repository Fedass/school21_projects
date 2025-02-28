#include "matrix_suite.h"

START_TEST(test_inverse_1) {
  matrix_t A, result, expected;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 4;
  A.matrix[0][1] = 7;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 6;

  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 0.6;
  expected.matrix[0][1] = -0.7;
  expected.matrix[1][0] = -0.2;
  expected.matrix[1][1] = 0.4;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_inverse_2) {
  matrix_t A, result;

  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < 3; i++) {
    A.matrix[i][i] = 1.0;
  }

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&A, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_3) {
  matrix_t A, result;

  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_4) {
  matrix_t A, result;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 4;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_5) {
  matrix_t *A = NULL;
  matrix_t result;

  ck_assert_int_eq(s21_inverse_matrix(A, &result), MATRIX_INCORRECT);
}
END_TEST

START_TEST(test_inverse_6) {
  matrix_t A, result;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = -1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = -1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -1;
  A.matrix[2][2] = 2;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("\033[42m S21_INVERSE_MATRIX \033[0m");
  TCase *tc = tcase_create("inverse_tc");

  tcase_add_test(tc, test_inverse_1);
  tcase_add_test(tc, test_inverse_2);
  tcase_add_test(tc, test_inverse_3);
  tcase_add_test(tc, test_inverse_4);
  tcase_add_test(tc, test_inverse_5);
  tcase_add_test(tc, test_inverse_6);

  suite_add_tcase(s, tc);
  return s;
}
