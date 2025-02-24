#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal* result) {
  int status = OK;

  if (result == NULL) {
    status = CALCULATION_ERROR;
  } else {
    s21_decimal truncated;
    status = s21_truncate(value, &truncated);

    if (status == OK) {
      s21_decimal fractional;
      s21_sub(value, truncated, &fractional);

      int sign = s21_get_sign(value);
      if (sign) {
        s21_negate(fractional, &fractional);
      }

      s21_decimal half = {{5, 0, 0, 0}};
      s21_set_scale(&half, 1);

      if (s21_is_greater_or_equal(fractional, half)) {
        s21_decimal one = {{1, 0, 0, 0}};
        if (sign) {
          s21_sub(truncated, one, result);
        } else {
          s21_add(truncated, one, result);
        }
      } else {
        *result = truncated;
      }

      s21_set_scale(result, 0);
    }
  }

  return status;
}
