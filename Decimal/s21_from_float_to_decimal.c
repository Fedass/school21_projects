#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result = CALCULATION_ERROR;
  if (dst && isfinite(src)) {
    *dst = ZERO_DECIMAL;
    result = OK;
    if (src != 0) {
      s21_decimal tmp = ZERO_DECIMAL;
      binaryfloat *bsrc = (binaryfloat *)&src;
      get_ref(dst, sign) = get_ref(&tmp, sign) = bsrc->sign;
      int e = bsrc->exponenta - 127;

      for (int i = 0; i <= 23 && result == OK; i++) {
        if (i == 0 || (bsrc->mantisse & (1 << (23 - i)))) {
          if (e - i > 95)
            result = CALCULATION_ERROR;
          else if (e - i >= 0)
            set_bit(dst, e - i);
          else if (e - i >= -96)
            set_bit(&tmp, 96 + (e - i));
        }
      }

      while (result == OK && get_ref(dst, exponenta) < 28 && !isnull(tmp)) {
        result += increase_exp(dst);
        mantiss_add(*dst, (s21_decimal){{s21_multiply_by_10(&tmp), 0, 0, 0}},
                    dst);
      }
    }
  }
  return result;
}
