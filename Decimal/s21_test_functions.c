#include "s21_test_functions.h"

// TEST S21_IS_LESS
START_TEST(test_1_less) {
  s21_decimal value_1 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123, 0, 0, (2 << 16)}};

  int expected = FALSE;
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_2_less) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFF1, (0 << 16)}};

  int expected = FALSE;
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_3_less) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};

  int expected = FALSE;
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_4_less) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (3 << 16)}};

  int expected = FALSE;
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_5_less) {
  s21_decimal value_1 = {{12300, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123000, 0, 0, (3 << 16)}};

  int expected = FALSE;
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST
START_TEST(test_6_less) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  int expected = FALSE;
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_7_less) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  int expected = FALSE;
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_8_less) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  int expected = FALSE;
  int result = s21_is_less(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

// TEST S21_IS_EQUAL

START_TEST(test_1_equal) {
  s21_decimal value_1 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123, 0, 0, (2 << 16)}};

  int expected = TRUE;
  int result = s21_is_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_2_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};

  int expected = TRUE;
  int result = s21_is_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_3_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};

  int expected = TRUE;
  int result = s21_is_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_4_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (3 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};

  int expected = FALSE;
  int result = s21_is_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_5_equal) {
  s21_decimal value_1 = {{12300, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123000, 0, 0, (3 << 16)}};

  int expected = TRUE;
  int result = s21_is_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_6_equal) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  int expected = TRUE;
  int result = s21_is_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_7_equal) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (0 << 16)}};

  s21_set_bit(&value_1, 127, 1);

  int expected = TRUE;
  int result = s21_is_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_8_equal) {
  s21_decimal value_1 = {{0, 123, 0, (28 << 16)}};
  s21_decimal value_2 = {{0, 122, 0, (28 << 16)}};

  int expected = FALSE;
  int result = s21_is_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_9_equal) {
  s21_decimal value_1 = {{0, 123, 0, (28 << 16)}};
  s21_decimal value_2 = {{0, 122, 0, (28 << 16)}};
  ;

  int expected = FALSE;
  int result = s21_is_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

// TEST S21_IS_GREATER

START_TEST(test_1_greater) {
  s21_decimal value_1 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123, 0, 0, (2 << 16)}};

  int expected = FALSE;
  int result = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_2_greater) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFF1, (0 << 16)}};

  int expected = TRUE;
  int result = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_3_greater) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};

  int expected = FALSE;
  int result = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_4_greater) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (3 << 16)}};

  int expected = TRUE;
  int result = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_5_greater) {
  s21_decimal value_1 = {{12300, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123000, 0, 0, (3 << 16)}};

  int expected = FALSE;
  int result = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_6_greater) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  int expected = FALSE;
  int result = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_7_greater) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  int expected = FALSE;
  int result = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_8_greater) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  int expected = FALSE;
  int result = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_9_greater) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (0 << 16)}};

  s21_set_bit(&value_2, 127, 1);

  int expected = FALSE;
  int result = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_10_greater) {
  s21_decimal value_1 = {{1234, 0, 0, (2 << 16)}};
  s21_set_bit(&value_1, 127, 1);
  s21_decimal value_2 = {{123, 0, 0, (1 << 16)}};
  int expected = FALSE;
  int result = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(result, expected);
}
END_TEST

// TEST S21_IS_NOT_EQUAL

START_TEST(test_1_not_equal) {
  s21_decimal value_1 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123, 0, 0, (2 << 16)}};

  int expected = FALSE;
  int result = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_2_not_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};

  int expected = FALSE;
  int result = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_3_not_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};

  s21_set_bit(&value_1, 127, 1);

  int expected = TRUE;
  int result = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_4_not_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (3 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};

  int expected = TRUE;
  int result = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_5_not_equal) {
  s21_decimal value_1 = {{12300, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123000, 0, 0, (3 << 16)}};

  int expected = FALSE;
  int result = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_6_not_equal) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  int expected = FALSE;
  int result = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_7_not_equal) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (0 << 16)}};

  s21_set_bit(&value_1, 127, 1);

  int expected = FALSE;
  int result = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_8_not_equal) {
  s21_decimal value_1 = {{0, 123, 0, (28 << 16)}};
  s21_decimal value_2 = {{0, 122, 0, (28 << 16)}};

  int expected = TRUE;
  int result = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_9_not_equal) {
  s21_decimal value_1 = {{0, 123, 0, (28 << 16)}};
  s21_decimal value_2 = {{0, 122, 0, (28 << 16)}};

  s21_set_bit(&value_1, 127, 1);

  int expected = TRUE;
  int result = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

// TEST S21_IS_LESS_OR_EQUAL

START_TEST(test_1_is_less_or_equal) {
  s21_decimal value_1 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123, 0, 0, (2 << 16)}};

  int expected = TRUE;
  int result = s21_is_less_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_2_is_less_or_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFF1, (0 << 16)}};

  int expected = FALSE;
  int result = s21_is_less_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_3_is_less_or_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};

  int expected = TRUE;
  int result = s21_is_less_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_4_is_less_or_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (3 << 16)}};

  int expected = FALSE;
  int result = s21_is_less_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_5_is_less_or_equal) {
  s21_decimal value_1 = {{12300, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123000, 0, 0, (3 << 16)}};

  int expected = TRUE;
  int result = s21_is_less_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_6_is_less_or_equal) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  int expected = TRUE;
  int result = s21_is_less_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_7_is_less_or_equal) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  s21_set_bit(&value_1, 127, 1);

  int expected = TRUE;
  int result = s21_is_less_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_8_is_less_or_equal) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  int expected = TRUE;
  int result = s21_is_less_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_9_is_less_or_equal) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (0 << 16)}};

  s21_set_bit(&value_1, 127, 1);

  int expected = TRUE;
  int result = s21_is_less_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

// TEST S21_IS_GREATER_OR_EQUAL

START_TEST(test_1_is_greater_or_equal) {
  s21_decimal value_1 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123, 0, 0, (2 << 16)}};

  int expected = TRUE;
  int result = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_2_is_greater_or_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};

  int expected = TRUE;
  int result = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_3_is_greater_or_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};

  s21_set_bit(&value_2, 127, 1);

  int expected = TRUE;
  int result = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_4_is_greater_or_equal) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (3 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};

  int expected = FALSE;
  int result = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_5_is_greater_or_equal) {
  s21_decimal value_1 = {{12300, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123000, 0, 0, (3 << 16)}};

  int expected = TRUE;
  int result = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_6_is_greater_or_equal) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (1 << 16)}};

  int expected = TRUE;
  int result = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_7_is_greater_or_equal) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (0 << 16)}};

  s21_set_bit(&value_1, 127, 1);

  int expected = TRUE;
  int result = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_8_is_greater_or_equal) {
  s21_decimal value_1 = {{0, 123, 0, (28 << 16)}};
  s21_decimal value_2 = {{0, 122, 0, (28 << 16)}};

  int expected = TRUE;
  int result = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_9_is_greater_or_equal) {
  s21_decimal value_1 = {{0, 123, 0, (28 << 16)}};
  s21_decimal value_2 = {{0, 122, 0, (28 << 16)}};

  int expected = TRUE;
  int result = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_10_is_greater_or_equal) {
  s21_decimal value_1 = {{123, 123, 0, (25 << 16)}};
  s21_decimal value_2 = {{123, 122, 0, (6 << 16)}};

  int expected = FALSE;
  int result = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(result, expected);
}
END_TEST

// TESTS CONVERSION FROM INT TO DECIMAL
START_TEST(test_from_int_to_decimal_1) {
  s21_decimal result;
  int src = 12345;
  int status = s21_from_int_to_decimal(src, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 12345);
  ck_assert_int_eq(result.bits[3] & (1 << 31), 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_2) {
  s21_decimal result;
  int src = -12345;
  int status = s21_from_int_to_decimal(src, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 12345);
  ck_assert_int_eq(result.bits[3] & (1U << 31), (1U << 31));
}
END_TEST

START_TEST(test_from_int_to_decimal_3) {
  s21_decimal result;
  int src = 0;
  int status = s21_from_int_to_decimal(src, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[3] & (1 << 31), 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_4) {
  s21_decimal result;
  int src = INT_MAX;
  int status = s21_from_int_to_decimal(src, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], INT_MAX);
  ck_assert_int_eq(result.bits[3] & (1 << 31), 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_5) {
  int src = 12345;
  int status = s21_from_int_to_decimal(src, NULL);

  ck_assert_int_eq(status, CALCULATION_ERROR);
}
END_TEST

// TESTS CONVERSION FROM FLOAT TO DECIMAL

START_TEST(test_from_float_to_decimal_1) {
  float zero = 0.0, val = zero;
  s21_decimal dec_1, dec_2;
  s21_from_float_to_decimal(val, &dec_1);
  ck_assert_float_eq(val, 0.0);
  dec_2 = dec_1;
  float res;
  s21_from_decimal_to_float(dec_2, &res);
  ck_assert_float_eq(val, res);
}
END_TEST

START_TEST(test_from_float_to_decimal_2) {
  float zero = 0.0, val = (0 / zero);
  s21_decimal dec_1;
  int res = s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_3) {
  float zero = 0.0, val = (1.0 / zero);
  s21_decimal dec_1;
  int res = s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_4) {
  float val = 1e-29;
  s21_decimal dec_1;
  int res = s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(dec_1.bits[0], 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_5) {
  float val = 79228162514264337593543950336.0;
  s21_decimal dec_1;
  int res = s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_6) {
  float val = -79228162514264337593543950336.0;
  s21_decimal dec_1;
  int res = s21_from_float_to_decimal(val, &dec_1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_7) {
  float val = -792281625142643.3;
  s21_decimal dec_1, dec_2;
  s21_from_float_to_decimal(val, &dec_1);
  dec_2 = dec_1;
  float res;
  s21_from_decimal_to_float(dec_2, &res);
  ck_assert_float_eq(val, res);
}
END_TEST

START_TEST(test_from_float_to_decimal_11) {
  float val = 10000000000000000.0, res;
  s21_decimal dec_1, dec_2;
  s21_from_float_to_decimal(val, &dec_1);
  dec_2 = dec_1;
  s21_from_decimal_to_float(dec_2, &res);
  ck_assert_float_eq(val, res);
}
END_TEST

START_TEST(test_from_float_to_decimal_12) {
  s21_decimal dec_1 = {{123456, 0, 0, 196608}};
  float res;
  s21_from_decimal_to_float(dec_1, &res);
  ck_assert_float_eq(res, 123.456);
}
END_TEST

START_TEST(test_from_float_to_decimal_13) {
  s21_decimal dec_1 = {{12345678, 0, 0, -2147155968}};
  float res;
  s21_from_decimal_to_float(dec_1, &res);
  ck_assert_float_eq(res, -123.45678);
}
END_TEST

START_TEST(test_from_float_to_decimal_14) {
  s21_decimal dec_1 = {{1, 0, 0, 0x80000000}};
  get_ref(&dec_1, exponenta) = 1;
  float res;
  float get = -0.1;
  s21_from_decimal_to_float(dec_1, &res);
  ck_assert_float_eq(res, get);
}
END_TEST

START_TEST(test_from_float_to_decimal_15) {
  s21_decimal dec_1 = {{1, 0, 0, 0x80000000}};
  int res = s21_from_decimal_to_float(dec_1, NULL);
  ck_assert_msg(res == 1, "Null pointer dec to float test failed");
}
END_TEST

START_TEST(test_from_float_to_decimal_16) {
  int res = s21_from_float_to_decimal(0, NULL);
  ck_assert_msg(res == 1, "Null pointer float to dec test failed");
}
END_TEST

START_TEST(test_from_float_to_decimal_17) {
  int res = s21_from_float_to_decimal(1 / 0.0, NULL);
  ck_assert_msg(res == 1, "Nan float to dec test failed");
}
END_TEST

START_TEST(test_float_random) {
  int sign = rand() % 2;
  float expected = rand() / rand(), result;
  if (sign) expected = -expected;
  s21_decimal src = {{0}};
  int status = s21_from_float_to_decimal(expected, &src);
  s21_from_decimal_to_float(src, &result);
  ck_assert_float_eq(result, expected);
  ck_assert_int_eq(status, !isfinite(expected));
}

// TESTS CONVERSION FROM DECIMAL TO INT
START_TEST(test_from_decimal_to_int_1) {
  s21_decimal src = {{123, 0, 0, 0}};
  int dst = 0;
  int result = s21_from_decimal_to_int(src, &dst);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(dst, 123);
}
END_TEST

START_TEST(test_from_decimal_to_int_2) {
  s21_decimal src = {{123, 0, 0, 0}};
  src.bits[3] = 1 << 31;
  int dst = 0;
  int result = s21_from_decimal_to_int(src, &dst);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(dst, -123);
}
END_TEST

START_TEST(test_from_decimal_to_int_3) {
  s21_decimal src = {{123000, 0, 0, 0}};
  src.bits[3] = 3 << 16;
  int dst = 0;
  int result = s21_from_decimal_to_int(src, &dst);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(dst, 123);
}
END_TEST

START_TEST(test_from_decimal_to_int_4) {
  s21_decimal src = {{123000, 0, 0, 0}};
  src.bits[3] = (3 << 16) | (1 << 31);
  int dst = 0;
  int result = s21_from_decimal_to_int(src, &dst);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(dst, -123);
}
END_TEST

START_TEST(test_from_decimal_to_int_5) {
  s21_decimal src = {{123001, 0, 0, 0}};
  src.bits[3] = 3 << 16;
  int dst = 0;
  int result = s21_from_decimal_to_int(src, &dst);

  ck_assert_int_eq(result, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_6) {
  s21_decimal src = {{INT_MAX, 0, 0, 0}};
  int dst = 0;
  int result = s21_from_decimal_to_int(src, &dst);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(dst, INT_MAX);
}
END_TEST

START_TEST(test_from_decimal_to_int_7) {
  s21_decimal src = {{(unsigned int)INT_MAX + 1u, 0, 0, 0}};
  src.bits[3] = 1 << 31;
  int dst = 0;
  int result = s21_from_decimal_to_int(src, &dst);

  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(dst, INT_MIN);
}
END_TEST

START_TEST(test_from_decimal_to_int_8) {
  s21_decimal src = {{0xFFFFFFFF, 0, 0, 0}};
  int dst = 0;
  int result = s21_from_decimal_to_int(src, &dst);

  ck_assert_int_eq(result, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_9) {
  s21_decimal src = {{123, 0, 0, 0}};
  int result = s21_from_decimal_to_int(src, NULL);

  ck_assert_int_eq(result, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_10) {
  s21_decimal src = {{123, 0, 0, 0}};
  src.bits[3] = 29 << 16;
  int dst = 0;
  int result = s21_from_decimal_to_int(src, &dst);

  ck_assert_int_eq(result, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_11) {
  s21_decimal src = {{0, 1, 0, 0}};
  int dst = 0;
  int result = s21_from_decimal_to_int(src, &dst);

  ck_assert_int_eq(result, CALCULATION_ERROR);
}
END_TEST

// TESTS CONVERSION FROM DECIMAL TO FLOAT
START_TEST(test_from_decimal_to_float_1) {
  s21_decimal src = {{12345678, 0, 0, (2 << 16)}};
  float dst = 0.0f;
  int result = s21_from_decimal_to_float(src, &dst);

  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(dst, 123456.78f);
}
END_TEST

START_TEST(test_from_decimal_to_float_4) {
  s21_decimal src = {{12345678, 0, 0, (2 << 16) | (1u << 31)}};
  float dst = 0.0f;
  int result = s21_from_decimal_to_float(src, &dst);

  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(dst, -123456.78f);
}
END_TEST

START_TEST(test_from_decimal_to_float_6) {
  s21_decimal src = {{123456789, 0, 0, (2 << 16)}};
  float dst = 0.0f;
  int result = s21_from_decimal_to_float(src, &dst);

  ck_assert_int_eq(result, OK);
  ck_assert_float_eq(dst, 1234567.89f);
}
END_TEST

START_TEST(test_truncate_1) {
  s21_decimal value = {{123456789, 0, 0, 0}};
  s21_set_scale(&value, 5);

  s21_decimal result = {{0, 0, 0, 0}};
  int status = s21_truncate(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 1234);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_truncate_2) {
  s21_decimal value = {{123456789, 0, 0, 0}};
  s21_set_scale(&value, 5);
  value.bits[3] |= (1 << 31);

  s21_decimal result = {{0, 0, 0, 0}};
  int status = s21_truncate(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 1234);
  ck_assert_int_eq(result.bits[3] & (1U << 31), (1U << 31));
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_truncate_3) {
  s21_decimal value = {{12345, 0, 0, 0}};
  s21_set_scale(&value, 2);

  int status = s21_truncate(value, NULL);

  ck_assert_int_eq(status, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_truncate_4) {
  s21_decimal value = {{123450000, 0, 0, 0}};
  s21_set_scale(&value, 6);

  s21_decimal result;
  int status = s21_truncate(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 123);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_truncate_5) {
  s21_decimal value = {{5999999, 0, 0, 0}};
  s21_set_scale(&value, 6);

  s21_decimal result;
  int status = s21_truncate(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_truncate_6) {
  s21_decimal value = {{5999999, 0, 0, 0}};
  s21_set_scale(&value, 6);
  value.bits[3] |= (1 << 31);

  s21_decimal result;
  int status = s21_truncate(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(result.bits[3] & (1U << 31), (1U << 31));
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_floor_1) {
  s21_decimal value = {{5, 0, 0, 0}};
  s21_decimal result;
  int status = s21_floor(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_floor_2) {
  s21_decimal value = {{58, 0, 0, 1 << 16}};
  s21_decimal result;
  int status = s21_floor(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_floor_3) {
  s21_decimal value = {{37, 0, 0, (1 << 16) | (1 << 31)}};
  s21_decimal result;
  int status = s21_floor(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 4);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_floor_4) {
  s21_decimal value = {{4, 0, 0, (1 << 31)}};
  s21_decimal result;
  int status = s21_floor(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 4);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_floor_5) {
  s21_decimal value = {{29999, 0, 0, (4 << 16) | (1 << 31)}};
  s21_decimal result;
  int status = s21_floor(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 3);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_floor_6) {
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result;
  int status = s21_floor(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_floor_7) {
  s21_decimal value = {{5, 0, 0, 0}};
  int status = s21_floor(value, NULL);

  ck_assert_int_eq(status, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_floor_8) {
  s21_decimal value = {{98765, 0, 0, (4 << 16)}};
  s21_decimal result;
  int status = s21_floor(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 9);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_floor_9) {
  s21_decimal value = {{29999, 0, 0, (3 << 16) | (1 << 31)}};
  s21_decimal result;
  int status = s21_floor(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 30);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_round_1) {
  s21_decimal value = {{58, 0, 0, 1 << 16}};
  s21_decimal result;
  int status = s21_round(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 6);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_round_2) {
  s21_decimal value = {{53, 0, 0, 1 << 16}};
  s21_decimal result;
  int status = s21_round(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_round_3) {
  s21_decimal value = {{37, 0, 0, (1 << 16) | (1 << 31)}};
  s21_decimal result;
  int status = s21_round(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 4);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_round_4) {
  s21_decimal value = {{15, 0, 0, 1 << 16}};
  s21_decimal result;
  int status = s21_round(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 2);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_round_5) {
  s21_decimal value = {{25, 0, 0, (1 << 16) | (1 << 31)}};
  s21_decimal result;
  int status = s21_round(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 3);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_round_6) {
  s21_decimal value = {{15, 0, 0, 1 << 16}};
  int status = s21_round(value, NULL);

  ck_assert_int_eq(status, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_round_7) {
  s21_decimal value = {{3499, 0, 0, (3 << 16) | (1 << 31)}};
  s21_decimal result;
  int status = s21_round(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 3);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_round_8) {
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result;
  int status = s21_round(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(s21_get_scale(result), 0);
}
END_TEST

START_TEST(test_negate_1) {
  s21_decimal value = {{123, 0, 0, 0}};
  s21_decimal result;
  int status = s21_negate(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(test_negate_2) {
  s21_decimal value = {{123, 0, 0, (1 << 31)}};
  s21_decimal result;
  int status = s21_negate(value, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(test_negate_3) {
  s21_decimal value = {{123, 0, 0, 0}};
  int status = s21_negate(value, NULL);

  ck_assert_int_eq(status, CALCULATION_ERROR);
}
END_TEST

// TEST S21_IS_ADD

START_TEST(test_1_add) {
  s21_decimal value_1 = {{123, 0, 0, 0}};
  s21_decimal value_2 = {{123, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{246, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_2_add) {
  s21_decimal value_1 = {{0, 123, 0, 0}};
  s21_decimal value_2 = {{0, 123, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 246, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_3_add) {
  s21_decimal value_1 = {{0, 0, 123, 0}};
  s21_decimal value_2 = {{0, 0, 123, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 246, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_4_add) {
  s21_decimal value_1 = {{123, 0, 0, 1 << 31}};
  s21_decimal value_2 = {{123, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{246, 0, 0, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_5_add) {
  s21_decimal value_1 = {{0, 123, 0, 1 << 31}};
  s21_decimal value_2 = {{0, 123, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 246, 0, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_6_add) {
  s21_decimal value_1 = {{0, 0, 123, 1 << 31}};
  s21_decimal value_2 = {{0, 0, 123, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 246, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_7_add) {
  s21_decimal value_1 = {{0, 0, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0, 0, 0xFFFFFFFF, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0xFFFFFFFE, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 1;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_8_add) {
  s21_decimal value_1 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0xFFFFFFFE, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 2;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_9_add) {
  s21_decimal value_1 = {{0, 0xFFFFFFFF, 0, 0}};
  s21_decimal value_2 = {{0, 0xFFFFFFFF, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0xFFFFFFFE, 1, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_10_add) {
  s21_decimal value_1 = {{0, 0xFFFFFFFF, 0, 1 << 31}};
  s21_decimal value_2 = {{0, 0xFFFFFFFF, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0xFFFFFFFE, 1, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_11_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 1, 0, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_12_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 1, 0, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_13_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 1;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_14_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 2;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_15_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 1;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_16_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{1, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 2;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_17_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0, 1, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0, 0, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 1;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_18_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0, 1, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0, 0, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 2;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_19_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 1;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_20_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0, 0, 1, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 2;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_21_add) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_22_add) {
  s21_decimal value_1 = {{0, 0, 0, 1 << 31}};
  s21_decimal value_2 = {{0, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_23_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_24_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_25_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 2;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_26_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 1, 0, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_27_add) {
  s21_decimal value_1 = {{0, 0xFFFFFFFF, 0, 1 << 31}};
  s21_decimal value_2 = {{0, 0xFFFFFFFF, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0xFFFFFFFE, 1, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_28_add) {
  s21_decimal value_1 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0xFFFFFFFE, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 2;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_29_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_30_add) {
  s21_decimal value_1 = {{0, 0xFFFFFFFF, 0, 0 << 31}};
  s21_decimal value_2 = {{0, 0xFFFFFFFF, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_31_add) {
  s21_decimal value_1 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{1, 0, 0, 0 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_32_add) {
  s21_decimal value_1 = {{1, 0, 0, 0 << 31}};
  s21_decimal value_2 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 1 << 31}};

  int status = s21_add(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_33_add) {
  s21_decimal value_1 = {{123, 123, 123, (2 << 16)}};
  s21_decimal value_2 = {{123, 123, 123, (2 << 16)}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{246, 246, 246, (2 << 16)}};

  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_34_add) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFF1, (0 << 16)}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFF1, (0 << 16)}};

  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_35_add) {
  s21_decimal value_1 = {{0xFFFFFFF1, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFF1, 0xFFFFFFFF, 0xFFFFFFF1, (0 << 16)}};
  s21_decimal value_result = {{0}};

  int expected = 1;
  int result = s21_add(value_1, value_2, &value_result);

  ck_assert_int_eq(result, expected);
}
END_TEST
START_TEST(test_36_add) {
  s21_decimal value_1 = {{0, 0, 0, (0 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0, (0 << 16)}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0, (0 << 16)}};

  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_37_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (28 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFF1, 0xFFFFFFFF, 0xFFFFFFFF, (28 << 16)}};
  value_2.bits[3] |= 1 << 31;
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{14, 0, 0, (28 << 16)}};

  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_38_add) {
  s21_decimal value_1 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123, 0, 0, (1 << 16)}};

  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{1353, 0, 0, (2 << 16)}};

  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_39_add) {
  s21_decimal value_1 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123, 0, 0, (1 << 16)}};
  value_2.bits[3] |= 1 << 31;
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{1107, 0, 0, (2 << 16)}};
  value_expected.bits[3] |= 1 << 31;

  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_40_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{6, 0, 0, (1 << 16)}};
  s21_decimal value_result = {{0}};

  int status = s21_add(value_1, value_2, &value_result);

  // По тестам Сереги, тут должно быть status - 1
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_41_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFF155, (7 << 16)}};
  // s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0}};
  s21_add(value_1, value_1, &value_expected);

  s21_add(value_1, value_1, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_42_add) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFF155, (3 << 16)}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFF333, (26 << 16)}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0x000C16D8, 0, 0xFFFFF156, 3 << 16}};

  s21_add(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

// TEST S21_IS_SUB

START_TEST(test_1_sub) {
  s21_decimal value_1 = {{123, 0, 0, 0}};
  s21_decimal value_2 = {{123, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_2_sub) {
  s21_decimal value_1 = {{0, 123, 0, 0}};
  s21_decimal value_2 = {{0, 123, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_3_sub) {
  s21_decimal value_1 = {{0, 0, 123, 0}};
  s21_decimal value_2 = {{0, 0, 123, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_4_sub) {
  s21_decimal value_1 = {{123, 0, 0, 1 << 31}};
  s21_decimal value_2 = {{123, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_5_sub) {
  s21_decimal value_1 = {{0, 123, 0, 1 << 31}};
  s21_decimal value_2 = {{0, 123, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_6_sub) {
  s21_decimal value_1 = {{0, 0, 123, 1 << 31}};
  s21_decimal value_2 = {{0, 0, 123, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;
  s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_7_sub) {
  s21_decimal value_1 = {{0, 0, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0, 0, 0xFFFFFFFF, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_8_sub) {
  s21_decimal value_1 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_9_sub) {
  s21_decimal value_1 = {{0, 0xFFFFFFFF, 0, 0}};
  s21_decimal value_2 = {{0, 0xFFFFFFFF, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_10_sub) {
  s21_decimal value_1 = {{0, 0xFFFFFFFF, 0, 1 << 31}};
  s21_decimal value_2 = {{0, 0xFFFFFFFF, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_11_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_12_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_13_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_14_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_15_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_16_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{1, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_17_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0, 1, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFF, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_18_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0, 1, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFF, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_19_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_20_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0, 0, 1, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_21_sub) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_22_sub) {
  s21_decimal value_1 = {{0, 0, 0, 1 << 31}};
  s21_decimal value_2 = {{0, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_23_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 1;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_24_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 2;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_25_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_26_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_27_sub) {
  s21_decimal value_1 = {{0, 0xFFFFFFFF, 0, 1 << 31}};
  s21_decimal value_2 = {{0, 0xFFFFFFFF, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_28_sub) {
  s21_decimal value_1 = {{0, 0, 0, 1 << 31}};
  s21_decimal value_2 = {{0, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_29_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 1 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 1, 0, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_30_sub) {
  s21_decimal value_1 = {{0, 0xFFFFFFFF, 0, 0 << 31}};
  s21_decimal value_2 = {{0, 0xFFFFFFFF, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0xFFFFFFFE, 1, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_31_sub) {
  s21_decimal value_1 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{1, 0, 0, 0 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{1, 0, 0xFFFFFFFF, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_32_sub) {
  s21_decimal value_1 = {{1, 0, 0, 0 << 31}};
  s21_decimal value_2 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{1, 0, 0xFFFFFFFF, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 0;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_33_sub) {
  s21_decimal value_1 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0, 0, 1, 0 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 2;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_34_sub) {
  s21_decimal value_1 = {{0, 0, 1, 0 << 31}};
  s21_decimal value_2 = {{0, 0, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 1;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_35_sub) {
  s21_decimal value_1 = {{0, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0, 1, 0, 0 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 2;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_36_sub) {
  s21_decimal value_1 = {{0, 1, 0, 0 << 31}};
  s21_decimal value_2 = {{0, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 1;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_37_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{1, 0, 0, 0 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 1 << 31}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 2;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_38_sub) {
  s21_decimal value_1 = {{1, 0, 0, 0 << 31}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int status = s21_sub(value_1, value_2, &value_result);
  int status_expected = 1;

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert(status == status_expected);
}
END_TEST

START_TEST(test_39_sub) {
  s21_decimal value_1 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, (0 << 16)}};

  int expected = 0;
  int result = s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_40_sub) {
  s21_decimal value_1 = {{123, 0, 0, (2 << 16)}};
  value_1.bits[3] |= 1 << 31;
  s21_decimal value_2 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{246, 0, 0, (2 << 16)}};
  value_expected.bits[3] |= 1 << 31;

  int expected = 0;
  int result = s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_41_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};
  value_1.bits[3] |= 1 << 31;
  s21_decimal value_2 = {{1, 0, 0, (0 << 16)}};

  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0}};

  int expected = 2;
  int result = s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_42_sub) {
  s21_decimal value_1 = {{123, 0, 0, (0 << 16)}};
  value_1.bits[3] |= 1 << 31;
  s21_decimal value_2 = {{123, 0, 0, (0 << 16)}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{246, 0, 0, (0 << 16)}};
  value_expected.bits[3] |= 1 << 31;

  int expected = 0;
  int result = s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_43_sub) {
  s21_decimal value_1 = {{123, 0, 0, (2 << 16)}};
  s21_decimal value_2 = {{123, 0, 0, (1 << 16)}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{1107, 0, 0, (2 << 16)}};
  value_expected.bits[3] |= 1 << 31;

  int expected = 0;
  int result = s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_44_sub) {
  s21_decimal value_1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal value_2 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  int expected = 0;
  int result = s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_45_sub) {
  s21_decimal value_1 = {{0, 0, 0, (1 << 16)}};
  s21_decimal value_2 = {{0, 0, 0, (2 << 16)}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, (2 << 16)}};

  int expected = 0;
  int result = s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_46_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (0 << 16)}};
  s21_decimal value_2 = {{1, 0, 0, (0 << 16)}};
  value_2.bits[3] |= 1 << 31;

  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0}};

  int expected = 1;
  int result = s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_47_sub) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (2 << 16)}};
  value_1.bits[3] |= 1 << 31;
  s21_decimal value_2 = {{1, 0, 0, (10 << 16)}};
  value_2.bits[3] |= 1 << 31;
  s21_decimal value_result = {{0}};

  int expected = 0;
  int result = s21_sub(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_1));
  ck_assert_int_eq(result, expected);
}
END_TEST

// TEST S21_IS_MUL
START_TEST(test_1_mul) {
  s21_decimal value_1 = {{123, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{246, 0, 0, 0}};

  int expected = 0;
  int result = s21_mul(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_2_mul) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{123, 0, 0xFFFFFFFF, 3 << 16}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  int expected = 0;
  int result = s21_mul(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_3_mul) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0 << 16}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0 << 16}};
  ;

  int expected = 1;
  int result = s21_mul(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_4_mul) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 28 << 16}};
  value_1.bits[3] |= 1 << 31;
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0}};

  s21_add(value_1, value_1, &value_expected);
  s21_mul(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_5_mul) {
  s21_decimal value_1 = {{12345678, 0, 0, 0}};
  s21_decimal value_2 = {{87654321, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{652409070, 251958, 0, 0}};

  s21_mul(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_6_mul) {
  s21_decimal value_1 = {{3, 0, 0, 0}};
  value_1.bits[3] |= 1 << 31;
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{6, 0, 0, 0}};
  value_expected.bits[3] |= 1 << 31;

  s21_mul(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_7_mul) {
  s21_decimal value_1 = {{123456, 0xFFFFFFFF, 0xFFFFFFFF, 28 << 16}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{123456, 0xFFFFFFFF, 0xFFFFFFFF, 28 << 16}};

  s21_mul(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_8_mul) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  s21_mul(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_9_mul) {
  s21_decimal value_1 = {{123456, 12345, 0, 13 << 16}};
  s21_decimal value_2 = {{1, 0, 0, 28 << 16}};
  s21_decimal value_result = {{0}};

  int status = s21_mul(value_1, value_2, &value_result);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_10_mul) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 16}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};

  int status = s21_mul(value_1, value_2, &value_result);

  ck_assert_int_eq(status, 2);
}
END_TEST

START_TEST(test_11_mul) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 10 << 16}};
  s21_decimal value_2 = {{3, 0, 0, 1 << 31}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0}};

  s21_add(value_1, value_1, &value_expected);
  s21_add(value_expected, value_1, &value_expected);
  value_expected.bits[3] |= 1 << 31;

  int status = s21_mul(value_1, value_2, &value_result);

  ck_assert_int_eq(status, 2);
}
END_TEST

// TEST S21_IS_SUB
START_TEST(test_1_div) {
  s21_decimal value_1 = {{246, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{123, 0, 0, 0}};

  s21_div(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_2_div) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{123, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  s21_div(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_3_div) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal value_result = {{0}};

  int status = s21_div(value_1, value_2, &value_result);

  ck_assert_int_eq(status, 3);
}
END_TEST

START_TEST(test_4_div) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  value_1.bits[3] |= 1 << 31;
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  value_expected.bits[3] |= 1 << 31;

  s21_div(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_5_div) {
  s21_decimal value_1 = {{12345678, 0, 0, 0}};
  s21_decimal value_2 = {{87654321, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xAD4CB3FC, 0x65776EBA, 0x48D0B03, 28 << 16}};

  s21_div(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_6_div) {
  s21_decimal value_1 = {{6, 0, 0, (1 << 16)}};
  value_1.bits[3] |= 1 << 31;
  s21_decimal value_2 = {{3, 0, 0, (5 << 16)}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{20000, 0, 0, 0}};
  value_expected.bits[3] |= 1 << 31;

  s21_div(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_7_div) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 5}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 5}};

  s21_div(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_8_div) {
  s21_decimal value_1 = {{0, 0, 0, 5}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0, 0, 0, 0}};

  s21_div(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_9_div) {
  s21_decimal value_1 = {{13, 0, 0, (10 << 16)}};
  value_1.bits[3] |= 1 << 31;
  s21_decimal value_2 = {{17, 0, 0, (15 << 16)}};
  s21_decimal value_result = {{0}};
  s21_decimal value_expected = {{0x89696969, 0xCC2A1231, 0xF716FCEE, 24 << 16}};
  value_expected.bits[3] |= 1 << 31;

  s21_div(value_1, value_2, &value_result);

  ck_assert(s21_is_equal(value_result, value_expected));
}
END_TEST

START_TEST(test_10_div) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFF1, 0}};
  s21_decimal value_2 = {{123, 0, 0, 7 << 16}};
  s21_decimal value_result = {{0}};

  int status = s21_div(value_1, value_2, &value_result);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test_11_div) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFF1, 1 << 31}};
  s21_decimal value_2 = {{123, 0, 0, 7 << 16}};
  s21_decimal value_result = {{0}};

  int status = s21_div(value_1, value_2, &value_result);

  ck_assert_int_eq(status, 2);
}
END_TEST

int main(void) {
  Suite *s;
  SRunner *sr;
  s = s21_test_is_less();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_is_equal();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_is_greater();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_is_not_equal();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_is_less_or_equal();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_is_greater_or_equal();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_from_int_to_decimal();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_from_float_to_decimal();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_from_decimal_to_int();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_from_decimal_to_float();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_truncate();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_floor();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_round();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_negate();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_is_add();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_is_sub();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_is_mul();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  s = s21_test_is_div();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  return 0;
}

Suite *s21_test_is_less(void) {
  Suite *suite = suite_create("s21_test_is_less");
  TCase *testCase = tcase_create("is_less");
  tcase_add_test(testCase, test_1_less);
  tcase_add_test(testCase, test_2_less);
  tcase_add_test(testCase, test_3_less);
  tcase_add_test(testCase, test_4_less);
  tcase_add_test(testCase, test_5_less);
  tcase_add_test(testCase, test_6_less);
  tcase_add_test(testCase, test_7_less);
  tcase_add_test(testCase, test_8_less);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_is_equal(void) {
  Suite *suite = suite_create("s21_test_is_equal");
  TCase *testCase = tcase_create("is_equal");
  tcase_add_test(testCase, test_1_equal);
  tcase_add_test(testCase, test_2_equal);
  tcase_add_test(testCase, test_3_equal);
  tcase_add_test(testCase, test_4_equal);
  tcase_add_test(testCase, test_5_equal);
  tcase_add_test(testCase, test_6_equal);
  tcase_add_test(testCase, test_7_equal);
  tcase_add_test(testCase, test_8_equal);
  tcase_add_test(testCase, test_9_equal);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_is_greater(void) {
  Suite *suite = suite_create("s21_test_is_greater");
  TCase *testCase = tcase_create("is_greater");
  tcase_add_test(testCase, test_1_greater);
  tcase_add_test(testCase, test_2_greater);
  tcase_add_test(testCase, test_3_greater);
  tcase_add_test(testCase, test_4_greater);
  tcase_add_test(testCase, test_5_greater);
  tcase_add_test(testCase, test_6_greater);
  tcase_add_test(testCase, test_7_greater);
  tcase_add_test(testCase, test_8_greater);
  tcase_add_test(testCase, test_9_greater);
  tcase_add_test(testCase, test_10_greater);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_is_not_equal(void) {
  Suite *suite = suite_create("s21_test_is_not_equal");
  TCase *testCase = tcase_create("is_equal");
  tcase_add_test(testCase, test_1_not_equal);
  tcase_add_test(testCase, test_2_not_equal);
  tcase_add_test(testCase, test_3_not_equal);
  tcase_add_test(testCase, test_4_not_equal);
  tcase_add_test(testCase, test_5_not_equal);
  tcase_add_test(testCase, test_6_not_equal);
  tcase_add_test(testCase, test_7_not_equal);
  tcase_add_test(testCase, test_8_not_equal);
  tcase_add_test(testCase, test_9_not_equal);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_is_less_or_equal(void) {
  Suite *suite = suite_create("s21_test_is_less_or_equal");
  TCase *testCase = tcase_create("is_equal");
  tcase_add_test(testCase, test_1_is_less_or_equal);
  tcase_add_test(testCase, test_2_is_less_or_equal);
  tcase_add_test(testCase, test_3_is_less_or_equal);
  tcase_add_test(testCase, test_4_is_less_or_equal);
  tcase_add_test(testCase, test_5_is_less_or_equal);
  tcase_add_test(testCase, test_6_is_less_or_equal);
  tcase_add_test(testCase, test_7_is_less_or_equal);
  tcase_add_test(testCase, test_8_is_less_or_equal);
  tcase_add_test(testCase, test_9_is_less_or_equal);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_is_greater_or_equal(void) {
  Suite *suite = suite_create("s21_test_is_greater_or_equal");
  TCase *testCase = tcase_create("is_equal");
  tcase_add_test(testCase, test_1_is_greater_or_equal);
  tcase_add_test(testCase, test_2_is_greater_or_equal);
  tcase_add_test(testCase, test_3_is_greater_or_equal);
  tcase_add_test(testCase, test_4_is_greater_or_equal);
  tcase_add_test(testCase, test_5_is_greater_or_equal);
  tcase_add_test(testCase, test_6_is_greater_or_equal);
  tcase_add_test(testCase, test_7_is_greater_or_equal);
  tcase_add_test(testCase, test_8_is_greater_or_equal);
  tcase_add_test(testCase, test_9_is_greater_or_equal);
  tcase_add_test(testCase, test_10_is_greater_or_equal);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_from_int_to_decimal(void) {
  Suite *suite = suite_create("s21_test_from_int_to_decimal");
  TCase *testCase = tcase_create("int_to_dec");
  tcase_add_test(testCase, test_from_int_to_decimal_1);
  tcase_add_test(testCase, test_from_int_to_decimal_2);
  tcase_add_test(testCase, test_from_int_to_decimal_3);
  tcase_add_test(testCase, test_from_int_to_decimal_4);
  tcase_add_test(testCase, test_from_int_to_decimal_5);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_from_float_to_decimal(void) {
  Suite *suite = suite_create("s21_test_from_float_to_decimal");
  TCase *testCase = tcase_create("float_to_dec");
  tcase_add_test(testCase, test_from_float_to_decimal_1);
  tcase_add_test(testCase, test_from_float_to_decimal_2);
  tcase_add_test(testCase, test_from_float_to_decimal_3);
  tcase_add_test(testCase, test_from_float_to_decimal_4);
  tcase_add_test(testCase, test_from_float_to_decimal_5);
  tcase_add_test(testCase, test_from_float_to_decimal_6);
  tcase_add_test(testCase, test_from_float_to_decimal_7);
  tcase_add_test(testCase, test_from_float_to_decimal_11);
  tcase_add_test(testCase, test_from_float_to_decimal_12);
  tcase_add_test(testCase, test_from_float_to_decimal_13);
  tcase_add_test(testCase, test_from_float_to_decimal_14);
  tcase_add_test(testCase, test_from_float_to_decimal_15);
  tcase_add_test(testCase, test_from_float_to_decimal_16);
  tcase_add_test(testCase, test_from_float_to_decimal_17);
  tcase_add_loop_test(testCase, test_float_random, 0, 500);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_from_decimal_to_int(void) {
  Suite *suite = suite_create("s21_test_from_decimal_to_int");
  TCase *testCase = tcase_create("dec_to_int");
  tcase_add_test(testCase, test_from_decimal_to_int_1);
  tcase_add_test(testCase, test_from_decimal_to_int_2);
  tcase_add_test(testCase, test_from_decimal_to_int_3);
  tcase_add_test(testCase, test_from_decimal_to_int_4);
  tcase_add_test(testCase, test_from_decimal_to_int_5);
  tcase_add_test(testCase, test_from_decimal_to_int_6);
  tcase_add_test(testCase, test_from_decimal_to_int_7);
  tcase_add_test(testCase, test_from_decimal_to_int_8);
  tcase_add_test(testCase, test_from_decimal_to_int_9);
  tcase_add_test(testCase, test_from_decimal_to_int_10);
  tcase_add_test(testCase, test_from_decimal_to_int_11);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_from_decimal_to_float(void) {
  Suite *suite = suite_create("s21_test_from_decimal_to_float");
  TCase *testCase = tcase_create("dec_to_float");
  tcase_add_test(testCase, test_from_decimal_to_float_1);
  tcase_add_test(testCase, test_from_decimal_to_float_4);
  tcase_add_test(testCase, test_from_decimal_to_float_6);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_truncate(void) {
  Suite *suite = suite_create("s21_test_truncate");
  TCase *testCase = tcase_create("truncate");
  tcase_add_test(testCase, test_truncate_1);
  tcase_add_test(testCase, test_truncate_2);
  tcase_add_test(testCase, test_truncate_3);
  tcase_add_test(testCase, test_truncate_4);
  tcase_add_test(testCase, test_truncate_5);
  tcase_add_test(testCase, test_truncate_6);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_floor(void) {
  Suite *suite = suite_create("s21_test_floor");
  TCase *testCase = tcase_create("floor");
  tcase_add_test(testCase, test_floor_1);
  tcase_add_test(testCase, test_floor_2);
  tcase_add_test(testCase, test_floor_3);
  tcase_add_test(testCase, test_floor_4);
  tcase_add_test(testCase, test_floor_5);
  tcase_add_test(testCase, test_floor_6);
  tcase_add_test(testCase, test_floor_7);
  tcase_add_test(testCase, test_floor_8);
  tcase_add_test(testCase, test_floor_9);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_round(void) {
  Suite *suite = suite_create("s21_test_round");
  TCase *testCase = tcase_create("round");
  tcase_add_test(testCase, test_round_1);
  tcase_add_test(testCase, test_round_2);
  tcase_add_test(testCase, test_round_3);
  tcase_add_test(testCase, test_round_4);
  tcase_add_test(testCase, test_round_5);
  tcase_add_test(testCase, test_round_6);
  tcase_add_test(testCase, test_round_7);
  tcase_add_test(testCase, test_round_8);

  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_negate(void) {
  Suite *suite = suite_create("s21_test_negate");
  TCase *testCase = tcase_create("negate");
  tcase_add_test(testCase, test_negate_1);
  tcase_add_test(testCase, test_negate_2);
  tcase_add_test(testCase, test_negate_3);
  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_is_add(void) {
  Suite *suite = suite_create("s21_test_is_add");
  TCase *testCase = tcase_create("is_add");

  tcase_add_test(testCase, test_1_add);
  tcase_add_test(testCase, test_2_add);
  tcase_add_test(testCase, test_3_add);
  tcase_add_test(testCase, test_4_add);
  tcase_add_test(testCase, test_5_add);
  tcase_add_test(testCase, test_6_add);
  tcase_add_test(testCase, test_7_add);
  tcase_add_test(testCase, test_8_add);
  tcase_add_test(testCase, test_9_add);
  tcase_add_test(testCase, test_10_add);
  tcase_add_test(testCase, test_11_add);
  tcase_add_test(testCase, test_12_add);
  tcase_add_test(testCase, test_13_add);
  tcase_add_test(testCase, test_14_add);
  tcase_add_test(testCase, test_15_add);
  tcase_add_test(testCase, test_16_add);
  tcase_add_test(testCase, test_17_add);
  tcase_add_test(testCase, test_18_add);
  tcase_add_test(testCase, test_19_add);
  tcase_add_test(testCase, test_20_add);
  tcase_add_test(testCase, test_21_add);
  tcase_add_test(testCase, test_22_add);
  tcase_add_test(testCase, test_23_add);
  tcase_add_test(testCase, test_24_add);
  tcase_add_test(testCase, test_25_add);
  tcase_add_test(testCase, test_26_add);
  tcase_add_test(testCase, test_27_add);
  tcase_add_test(testCase, test_28_add);
  tcase_add_test(testCase, test_29_add);
  tcase_add_test(testCase, test_30_add);
  tcase_add_test(testCase, test_31_add);
  tcase_add_test(testCase, test_32_add);
  tcase_add_test(testCase, test_33_add);
  tcase_add_test(testCase, test_34_add);
  tcase_add_test(testCase, test_35_add);
  tcase_add_test(testCase, test_36_add);
  tcase_add_test(testCase, test_37_add);
  tcase_add_test(testCase, test_38_add);
  tcase_add_test(testCase, test_39_add);
  tcase_add_test(testCase, test_40_add);
  tcase_add_test(testCase, test_41_add);
  tcase_add_test(testCase, test_42_add);

  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_is_sub(void) {
  Suite *suite = suite_create("s21_test_is_sub");
  TCase *testCase = tcase_create("is_sub");

  tcase_add_test(testCase, test_1_sub);
  tcase_add_test(testCase, test_2_sub);
  tcase_add_test(testCase, test_3_sub);
  tcase_add_test(testCase, test_4_sub);
  tcase_add_test(testCase, test_5_sub);
  tcase_add_test(testCase, test_6_sub);
  tcase_add_test(testCase, test_7_sub);
  tcase_add_test(testCase, test_8_sub);
  tcase_add_test(testCase, test_9_sub);
  tcase_add_test(testCase, test_10_sub);
  tcase_add_test(testCase, test_11_sub);
  tcase_add_test(testCase, test_12_sub);
  tcase_add_test(testCase, test_13_sub);
  tcase_add_test(testCase, test_14_sub);
  tcase_add_test(testCase, test_15_sub);
  tcase_add_test(testCase, test_16_sub);
  tcase_add_test(testCase, test_17_sub);
  tcase_add_test(testCase, test_18_sub);
  tcase_add_test(testCase, test_19_sub);
  tcase_add_test(testCase, test_20_sub);
  tcase_add_test(testCase, test_21_sub);
  tcase_add_test(testCase, test_22_sub);
  tcase_add_test(testCase, test_23_sub);
  tcase_add_test(testCase, test_24_sub);
  tcase_add_test(testCase, test_25_sub);
  tcase_add_test(testCase, test_26_sub);
  tcase_add_test(testCase, test_27_sub);
  tcase_add_test(testCase, test_28_sub);
  tcase_add_test(testCase, test_29_sub);
  tcase_add_test(testCase, test_30_sub);
  tcase_add_test(testCase, test_31_sub);
  tcase_add_test(testCase, test_32_sub);
  tcase_add_test(testCase, test_33_sub);
  tcase_add_test(testCase, test_34_sub);
  tcase_add_test(testCase, test_35_sub);
  tcase_add_test(testCase, test_36_sub);
  tcase_add_test(testCase, test_37_sub);
  tcase_add_test(testCase, test_38_sub);
  tcase_add_test(testCase, test_39_sub);
  tcase_add_test(testCase, test_40_sub);
  tcase_add_test(testCase, test_41_sub);
  tcase_add_test(testCase, test_42_sub);
  tcase_add_test(testCase, test_43_sub);
  tcase_add_test(testCase, test_44_sub);
  tcase_add_test(testCase, test_45_sub);
  tcase_add_test(testCase, test_46_sub);
  tcase_add_test(testCase, test_47_sub);

  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_is_mul(void) {
  Suite *suite = suite_create("s21_test_is_mul");
  TCase *testCase = tcase_create("is_mul");

  tcase_add_test(testCase, test_1_mul);
  tcase_add_test(testCase, test_2_mul);
  tcase_add_test(testCase, test_3_mul);
  tcase_add_test(testCase, test_4_mul);
  tcase_add_test(testCase, test_5_mul);
  tcase_add_test(testCase, test_6_mul);
  tcase_add_test(testCase, test_7_mul);
  tcase_add_test(testCase, test_8_mul);
  tcase_add_test(testCase, test_9_mul);
  tcase_add_test(testCase, test_10_mul);
  tcase_add_test(testCase, test_11_mul);

  suite_add_tcase(suite, testCase);

  return suite;
}

Suite *s21_test_is_div(void) {
  Suite *suite = suite_create("s21_test_is_div");
  TCase *testCase = tcase_create("is_div");

  tcase_add_test(testCase, test_1_div);
  tcase_add_test(testCase, test_2_div);
  tcase_add_test(testCase, test_3_div);
  tcase_add_test(testCase, test_4_div);
  tcase_add_test(testCase, test_5_div);
  tcase_add_test(testCase, test_6_div);
  tcase_add_test(testCase, test_7_div);
  tcase_add_test(testCase, test_8_div);
  tcase_add_test(testCase, test_9_div);
  tcase_add_test(testCase, test_10_div);
  tcase_add_test(testCase, test_11_div);

  suite_add_tcase(suite, testCase);

  return suite;
}
