#include "matrix_suite.h"

START_TEST(test_s21_determinant_1) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;

  double determinant = 0;
  int result = s21_determinant(&A, &determinant);

  ck_assert_int_eq(result, OK);
  ck_assert_double_eq(determinant, 5);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  double determinant = 0;
  int result = s21_determinant(&A, &determinant);

  ck_assert_int_eq(result, OK);
  ck_assert_double_eq(determinant, -2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 6;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -2;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 7;

  double determinant = 0;
  int result = s21_determinant(&A, &determinant);

  ck_assert_int_eq(result, OK);
  ck_assert_double_eq_tol(determinant, -306, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_4) {
  double determinant = 0;
  int result = s21_determinant(NULL, &determinant);

  ck_assert_int_eq(result, MATRIX_INCORRECT);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  matrix_t A;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;

  double determinant = 0;
  int result = s21_determinant(&A, &determinant);

  ck_assert_int_eq(result, MATRIX_INCORRECT);
}
END_TEST

START_TEST(test_s21_determinant_6) {
  matrix_t A;
  s21_create_matrix(2, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  double determinant = 0;
  int result = s21_determinant(&A, &determinant);

  ck_assert_int_eq(result, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_7) {
  matrix_t A;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 11;
  A.matrix[2][3] = 12;
  A.matrix[3][0] = 13;
  A.matrix[3][1] = 14;
  A.matrix[3][2] = 15;
  A.matrix[3][3] = 16;

  double determinant = 0;
  int result = s21_determinant(&A, &determinant);

  ck_assert_int_eq(result, OK);
  ck_assert_double_eq_tol(determinant, 0, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

Suite *test_determinate(void) {
  Suite *s = suite_create("\033[42m S21_DETERMINATE \033[0m");
  TCase *tc = tcase_create("determinate_tc");

  tcase_add_test(tc, test_s21_determinant_1);
  tcase_add_test(tc, test_s21_determinant_2);
  tcase_add_test(tc, test_s21_determinant_3);
  tcase_add_test(tc, test_s21_determinant_4);
  tcase_add_test(tc, test_s21_determinant_5);
  tcase_add_test(tc, test_s21_determinant_6);
  tcase_add_test(tc, test_s21_determinant_7);

  suite_add_tcase(s, tc);
  return s;
}
