#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  s21_decimal sub_result = {{0, 0, 0, 0}};

  int value_1_sign = s21_get_sign(value_1);
  value_1.bits[3] &= ~(1 << 31);
  int value_2_sign = s21_get_sign(value_2);
  value_2.bits[3] &= ~(1 << 31);

  int result_sign = 0;
  if (s21_is_equal(value_1, value_2) &&
      (value_1_sign == 1 && value_2_sign == 0)) {
    result_sign = 1;
  } else if (s21_is_greater(value_1, value_2)) {
    result_sign = value_1_sign;
  } else if (s21_is_greater(value_2, value_1)) {
    result_sign = !value_2_sign;
  }

  s21_normalization_round(&value_1, &value_2);

  if ((value_1_sign == value_2_sign)) {
    if (s21_is_less(value_1, value_2)) {
      s21_unsigned_negate_bits(value_1, &value_1);
    } else {
      s21_unsigned_negate_bits(value_2, &value_2);
    }
  }
  status = s21_add(value_1, value_2, &sub_result);

  sub_result.bits[3] |= result_sign << 31;
  result->bits[0] = sub_result.bits[0];
  result->bits[1] = sub_result.bits[1];
  result->bits[2] = sub_result.bits[2];
  result->bits[3] = sub_result.bits[3];

  if (value_1_sign == value_2_sign) {
    status = 0;
  } else if (status != 0) {
    status += result_sign;
  }

  return status;
}
