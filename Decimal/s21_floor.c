#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int status = OK;

  if (result == NULL) {
    status = CALCULATION_ERROR;
  } else {
    status = s21_truncate(value, result);

    if (status == OK) {
      int sign = s21_get_sign(value);

      if (sign && !s21_is_equal(value, *result)) {
        s21_decimal one = {{1, 0, 0, 0}};
        status = s21_sub(*result, one, result);
      }
    }
  }

  return status;
}
