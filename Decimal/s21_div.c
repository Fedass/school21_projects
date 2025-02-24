#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (s21_is_zero(value_2)) {
    return 3;
  }

  int status = 0;
  int value_not_zero = !s21_is_zero(value_1);
  int result_sign = (s21_get_sign(value_1) + s21_get_sign(value_2)) % 2;
  s21_normalization_round(&value_1, &value_2);
  value_1.bits[3] = 0;
  value_2.bits[3] = 0;

  if (value_not_zero && s21_is_zero(value_1)) {
    status = 2;
  } else if (s21_is_zero(value_2)) {
    status = 1 + result_sign;
  } else {
    int result_scale = 0;
    s21_decimal div_quotient = {{0, 0, 0, 0}};   // частное
    s21_decimal div_remainder = {{0, 0, 0, 0}};  // остаток

    div_remainder = s21_div_quotient(value_1, value_2, &div_quotient);

    if (!s21_is_zero(div_remainder)) {
      s21_div_value_increase_scale(&div_quotient, &div_remainder,
                                   &result_scale);

      if (s21_is_zero(div_quotient)) {
        div_remainder = s21_div_quotient(div_remainder, value_2, &div_quotient);
        s21_div_value_increase_scale(&div_quotient, &div_remainder,
                                     &result_scale);
      }

      s21_div_quotient(div_remainder, value_2, &div_remainder);
      s21_add(div_quotient, div_remainder, &div_quotient);
    }

    if (s21_is_zero(value_1) || s21_is_zero(value_2)) result_sign = 0;

    s21_set_scale(&div_quotient, result_scale);
    div_quotient.bits[3] |= result_sign << 31;

    *result = div_quotient;
  }

  return status;
}
