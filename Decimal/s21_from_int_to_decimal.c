#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result = CALCULATION_ERROR;

  if (dst) {
    memset(dst, 0, sizeof(s21_decimal));

    if (src < 0) {
      dst->bits[3] |= (1 << 31);
      dst->bits[0] = (unsigned int)(src == INT_MIN ? INT_MIN : -src);
    } else {
      dst->bits[0] = (unsigned int)src;
    }

    result = OK;
  }

  return result;
}
