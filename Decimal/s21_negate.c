#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int status = OK;

  if (result == NULL) {
    status = CALCULATION_ERROR;
  } else {
    *result = value;

    result->bits[3] ^= (1 << 31);
  }

  return status;
}
