#include "s21_decimal.h"

int s21_is_not_equal(s21_decimal first, s21_decimal second) {
  int result = 1;
  if (s21_is_equal(first, second)) {
    result = 0;
  }
  return result;
}
