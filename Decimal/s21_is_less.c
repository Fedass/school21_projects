#include "s21_decimal.h"

int s21_is_less(s21_decimal first, s21_decimal second) {
  int result_is_less = 0;

  int get_sign_first = s21_get_sign(first);
  int get_sign_second = s21_get_sign(second);

  int check = 0;

  if (s21_is_zero(first) && s21_is_zero(second)) {
    result_is_less = 0;
  } else if (get_sign_first == 1 && get_sign_second == 0) {
    result_is_less = 1;
  } else if (get_sign_first == 0 && get_sign_second == 1) {
    result_is_less = 0;
  } else if (first.bits[0] == second.bits[0] &&
             first.bits[1] == second.bits[1] &&
             first.bits[2] == second.bits[2] &&
             first.bits[3] == second.bits[3]) {
    result_is_less = 0;
  }

  else {
    if (s21_normalization_scale(&first, &second)) {
      for (int i = 95; i >= 0; i--) {
        if (s21_get_bit(first, i) > s21_get_bit(second, i)) {
          result_is_less = 0;
          check++;
        }
        if (s21_get_bit(first, i) < s21_get_bit(second, i)) {
          result_is_less = 1;
          check++;
        }
        if (check != 0) {
          break;
        }
      }
    }
    if (s21_get_sign(first) == 1 && s21_get_sign(second) == 1 && check) {
      result_is_less = !result_is_less;
    }
  }
  return result_is_less;
}
