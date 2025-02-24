#ifndef S21_DECIMAL
#define S21_DECIMAL

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

typedef struct binaryfloat {
  unsigned int mantisse : 23;
  unsigned int exponenta : 8;
  unsigned int sign : 1;
} binaryfloat;

typedef struct s21_exp_sign {
  unsigned int bits[3];
  unsigned zero1 : 16;
  unsigned exponenta : 8;
  unsigned zero2 : 7;
  unsigned sign : 1;
} s21_exp_sign;

#define FALSE 0
#define BIG_SCALE 0
#define DECIMAL_OVERFLOW 0
#define TRUE 1

#define COUNT_BIT_IN_ONE_BITS 32
#define START_NUMBER_SCALE_BIT 112
#define END_NUMBER_SCALE_BIT 119
#define MIN_SCALE 0
#define MAX_SCALE 28

#define INT_MIN -2147483648
#define INT_MAX 2147483647

#define OK 0
#define CALCULATION_ERROR 1

#define TEST_COMPARISON_FALSE 0
#define TEST_COMPARISON_TRUE 1

#define TEST_CONVERSION_ERROR 1
#define TEST_CONVERSION_OK 0

#define TEST_ARITHMETIC_OK 0
#define TEST_ARITHMETIC_BIG 1
#define TEST_ARITHMETIC_SMALL 2
#define TEST_ARITHMETIC_ZERO_DIV 3

#define TEST_OTHER_OK 0
#define TEST_OTHER_ERROR 1

#define ZERO_DECIMAL ((s21_decimal){{0, 0, 0, 0}})
#define get_ref(x, y) ((s21_exp_sign*)x)->y
#define set_bit(x, y) ((x)->bits[(y) / 32] |= (1u << ((y) % 32)))
#define get_bit(x, y) (((x)->bits[(y) / 32] & (1u << ((y) % 32))) >> ((y) % 32))

int s21_get_bit(s21_decimal decimal, int index);

void s21_set_bit(s21_decimal* decimal, int index, int value);

int s21_is_zero(s21_decimal decimal);

int s21_get_sign(s21_decimal decimal);

int s21_get_scale(s21_decimal decimal);

void s21_set_scale(s21_decimal* decimal, int scale);

int s21_normalization_scale(s21_decimal* decimal_first,
                            s21_decimal* decimal_two);

int s21_multiply_by_10(s21_decimal* decimal);

int s21_div_by_10(s21_decimal* decimal);

int s21_is_equal(s21_decimal first, s21_decimal second);

int s21_is_greater_or_equal(s21_decimal first, s21_decimal second);

int s21_is_greater(s21_decimal first, s21_decimal second);

int s21_is_less(s21_decimal first, s21_decimal second);

int s21_is_less_or_equal(s21_decimal first, s21_decimal second);

int s21_is_not_equal(s21_decimal first, s21_decimal second);

int s21_from_int_to_decimal(int src, s21_decimal* dst);

int s21_from_float_to_decimal(float src, s21_decimal* dst);

int s21_from_decimal_to_int(s21_decimal src, int* dst);

int s21_from_decimal_to_float(s21_decimal src, float* dst);

int s21_floor(s21_decimal value, s21_decimal* result);

int s21_round(s21_decimal value, s21_decimal* result);

int s21_truncate(s21_decimal value, s21_decimal* result);

int s21_negate(s21_decimal value, s21_decimal* result);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

int s21_unsigned_negate_bits(s21_decimal value, s21_decimal* result);

int s21_add_bit(int value_1, int value_2, unsigned int* result);

int s21_shift_left_decimal(s21_decimal* value, int shift);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

s21_decimal s21_div_quotient(s21_decimal value_1, s21_decimal value_2,
                             s21_decimal* result);

void s21_div_value_increase_scale(s21_decimal* value_1, s21_decimal* value_2,
                                  int* scale);

int mantiss_add(s21_decimal val1, s21_decimal val2, s21_decimal* result);

int increase_exp(s21_decimal* dec);

int isnull(s21_decimal dec);

int s21_normalization_round(s21_decimal* value_1, s21_decimal* value_2);

#endif
