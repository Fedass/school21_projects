#include "s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal first, s21_decimal second) {
  int result = 0;
  if (!s21_is_less(first, second) || s21_is_equal(first, second) == 1) {
    result = 1;
  }
  return result;
}
