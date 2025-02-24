#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;
  int DECIMAL_N_INT = 3;
  int INT_BITS = 32;
  int value_1_sign = s21_get_sign(value_1);
  value_1.bits[3] &= ~(1 << 31);
  int value_2_sign = s21_get_sign(value_2);
  value_2.bits[3] &= ~(1 << 31);
  int result_sign = (value_1_sign + value_2_sign) % 2;
  int result_scale = s21_get_scale(value_1) + s21_get_scale(value_2);
  s21_decimal mul_result = {{0, 0, 0, 0}};

  if (s21_is_zero(value_1) || s21_is_zero(value_2)) {
    result_sign = 0;
    *result = mul_result;
  } else {
    if (result_scale > MAX_SCALE) {
      status = 1 + result_sign;
    }

    else {
      int shift_position = 0;
      for (int i = 0; i < DECIMAL_N_INT; i++) {
        for (int k = 0; k < INT_BITS; k++) {
          if (value_2.bits[i] >> k & 1) {
            int shift = (k + INT_BITS * i) - shift_position;
            status = s21_shift_left_decimal(&value_1, shift) || status;
            shift_position += shift;
            status = s21_add(mul_result, value_1, &mul_result) || status;
          }
        }
      }
      mul_result.bits[3] |= result_scale << 16;
    }
    mul_result.bits[3] |= result_sign << 31;
    *result = mul_result;

    if (status) {
      status = 1 + result_sign;
    }
  }
  return status;
}
