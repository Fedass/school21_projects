#include "s21_decimal.h"

int s21_is_equal(s21_decimal first, s21_decimal second) {
  int result = 0;

  int is_sign_first = s21_get_sign(first);
  int is_sign_second = s21_get_sign(second);

  if (s21_is_zero(first) == 1 && s21_is_zero(second) == 1) {
    result = 1;
  } else if (s21_normalization_scale(&first, &second)) {
    if (first.bits[0] == second.bits[0] && first.bits[1] == second.bits[1] &&
        first.bits[2] == second.bits[2] && is_sign_first == is_sign_second) {
      result = 1;
    }
  }
  return result;
}
