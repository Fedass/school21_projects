#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  int value_1_sign = s21_get_sign(value_1);
  value_1.bits[3] &= ~(1 << 31);
  int value_2_sign = s21_get_sign(value_2);
  value_2.bits[3] &= ~(1 << 31);
  int result_sign = 0;

  s21_normalization_round(&value_1, &value_2);
  if (value_1_sign == value_2_sign) {
    result_sign = value_1_sign;
  } else {
    result_sign =
        s21_is_greater(value_1, value_2) ? value_1_sign : value_2_sign;
    if (s21_is_less(value_1, value_2)) {
      s21_unsigned_negate_bits(value_1, &value_1);
    } else {
      s21_unsigned_negate_bits(value_2, &value_2);
    }
  }

  int transposition = 0;
  int n_bits = 4;
  s21_decimal add_result = {{0, 0, 0, 0}};

  for (int i = 0; i < n_bits - 1; i++) {
    transposition =
        s21_add_bit(value_1.bits[i], value_2.bits[i], &add_result.bits[i]);
    for (int k = i + 1; transposition == 1 && k < n_bits - 1; k++) {
      transposition = s21_add_bit(value_1.bits[k], 1, &value_1.bits[k]);
    }

    status = status || transposition;
  }

  add_result.bits[n_bits - 1] = value_1.bits[n_bits - 1];
  add_result.bits[n_bits - 1] |= result_sign << 31;
  *result = add_result;

  if (status && (value_1_sign == value_2_sign)) {
    status = 1 + result_sign;
  } else {
    status = 0;
  }

  return status;
}
