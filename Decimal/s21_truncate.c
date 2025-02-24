#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int status = OK;

  if (result == NULL) {
    status = CALCULATION_ERROR;
  } else {
    *result = value;
    int scale = s21_get_scale(value);
    int sign = s21_get_sign(value);

    if (scale > 0) {
      for (int i = 0; i < scale; i++) {
        s21_div_by_10(result);
      }
      s21_set_scale(result, 0);
    }

    if (sign) {
      result->bits[3] |= (1 << 31);
    }
  }

  return status;
}
