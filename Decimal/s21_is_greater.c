#include "s21_decimal.h"

int s21_is_greater(s21_decimal first, s21_decimal second) {
  int result_is_greater = 1;
  if (s21_is_equal(first, second)) {
    result_is_greater = 0;
  }
  if (s21_is_less(first, second)) {
    result_is_greater = 0;
  }
  return result_is_greater;
}
