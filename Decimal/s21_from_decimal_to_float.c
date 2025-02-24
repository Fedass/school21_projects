#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = CALCULATION_ERROR;
  if (dst) {
    *dst = 0;
    result = OK;
    if (!isnull(src)) {
      binaryfloat *bdst = (binaryfloat *)dst;
      bdst->exponenta = 127 + 95;
      bdst->sign = get_ref(&src, sign);

      while (bdst->exponenta >= 127 && !get_bit(&src, bdst->exponenta - 127)) {
        bdst->exponenta--;
      }
      for (int i = 0; i < 23; i++) {
        int b = bdst->exponenta - i - 128;
        if (b >= 0) bdst->mantisse |= get_bit(&src, b) << (22 - i);
      }
      *dst /= pow(10, get_ref(&src, exponenta));
    }
  }
  return result;
}
