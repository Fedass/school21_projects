#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int result = CALCULATION_ERROR;

  if (dst != NULL) {
    *dst = 0;
    result = OK;

    int sign = s21_get_sign(src);
    int scale = (src.bits[3] >> 16) & 0xFF;

    if (scale > 28 || scale < 0) {
      result = CALCULATION_ERROR;
    } else if (src.bits[1] == 0 && src.bits[2] == 0) {
      unsigned int value = src.bits[0];

      for (int i = 0; i < scale && result == OK; ++i) {
        if (value % 10 != 0) {
          result = CALCULATION_ERROR;
        }
        value /= 10;
      }

      if (result == OK) {
        if (value <= INT_MAX) {
          *dst = sign ? -(int)value : (int)value;
        } else if (sign && value == (unsigned int)INT_MAX + 1) {
          *dst = INT_MIN;
        } else {
          result = CALCULATION_ERROR;
        }
      }
    } else {
      result = CALCULATION_ERROR;
    }
  }

  return result;
}
