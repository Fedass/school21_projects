#include "s21_decimal.h"

int s21_get_bit(s21_decimal decimal, int index) {
  unsigned int check_bit = 1;
  int number_byte = index / COUNT_BIT_IN_ONE_BITS;
  int number_decimal_bit = index % COUNT_BIT_IN_ONE_BITS;
  return (decimal.bits[number_byte] & (check_bit << number_decimal_bit)) >>
         number_decimal_bit;
}

void s21_set_bit(s21_decimal* decimal, int index, int value) {
  unsigned int check_bit = 1;
  int number_byte = index / COUNT_BIT_IN_ONE_BITS;
  int number_decimal_bit = index % COUNT_BIT_IN_ONE_BITS;
  if (value == 1) {
    decimal->bits[number_byte] |= (check_bit << number_decimal_bit);
  }
  if (value == 0) {
    decimal->bits[number_byte] &= ~(check_bit << number_decimal_bit);
  }
}

int s21_is_zero(s21_decimal decimal) {
  return (decimal.bits[0] == 0 && decimal.bits[1] == 0 && decimal.bits[2] == 0)
             ? TRUE
             : FALSE;
}

int s21_get_sign(s21_decimal decimal) {
  unsigned int check_bit = 1;
  return (decimal.bits[3] & (check_bit << (COUNT_BIT_IN_ONE_BITS - 1))) >>
         (COUNT_BIT_IN_ONE_BITS - 1);
}

int s21_get_scale(s21_decimal decimal) {
  int scale = 0;
  for (int i = START_NUMBER_SCALE_BIT; i <= END_NUMBER_SCALE_BIT; i++) {
    scale |= s21_get_bit(decimal, i) << (i - START_NUMBER_SCALE_BIT);
  }
  return scale;
}

void s21_set_scale(s21_decimal* decimal, int scale) {
  if (scale >= MIN_SCALE && scale <= MAX_SCALE) {
    for (int i = START_NUMBER_SCALE_BIT; i <= END_NUMBER_SCALE_BIT; i++) {
      s21_set_bit(decimal, i, 0);
    }
    for (int i = START_NUMBER_SCALE_BIT; i <= END_NUMBER_SCALE_BIT; i++) {
      int bit_value = (scale >> (i - START_NUMBER_SCALE_BIT)) & 1;
      s21_set_bit(decimal, i, bit_value);
    }
  }
}

int s21_normalization_scale(s21_decimal* decimal_first,
                            s21_decimal* decimal_two) {
  int scale_first_decimal = s21_get_scale(*decimal_first);
  int scale_two_decimal = s21_get_scale(*decimal_two);

  int diff_scale = abs(scale_first_decimal - scale_two_decimal);

  int check_error = TRUE;

  s21_decimal* lower_scale_decimal =
      (scale_first_decimal < scale_two_decimal) ? decimal_first : decimal_two;

  while (diff_scale > 0) {
    if (s21_multiply_by_10(lower_scale_decimal) == FALSE) {
      s21_decimal* higher_scale_decimal =
          (lower_scale_decimal == decimal_first) ? decimal_two : decimal_first;
      if (s21_div_by_10(higher_scale_decimal) == FALSE) {
        check_error = FALSE;
        break;
      }
    }
    diff_scale--;
  }
  if (diff_scale != 0) {
    check_error = FALSE;
  }
  return check_error;
}

int s21_multiply_by_10(s21_decimal* decimal) {
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal tmp_decimal = *decimal;

  int carry = 0;
  int check_error = TRUE;

  for (int i = 0; i < 3; i++) {
    long long int product = (long long int)tmp_decimal.bits[i] * 10 + carry;
    result.bits[i] = (int)(product & 0xFFFFFFFF);
    carry = (int)(product >> COUNT_BIT_IN_ONE_BITS);
  }

  if (carry != 0) {
    check_error = DECIMAL_OVERFLOW;
  } else {
    int scale = s21_get_scale(*decimal);
    if (scale < MAX_SCALE) {
      scale++;
      s21_set_scale(&result, scale);
    } else {
      check_error = BIG_SCALE;
    }
  }

  if (check_error) {
    s21_set_bit(&result, 127, s21_get_bit(*decimal, 127));
    *decimal = result;
  }

  return check_error;
}
int s21_div_by_10(s21_decimal* decimal) {
  s21_decimal result = {{0}};

  int check_error = TRUE;
  int remainder = 0;

  for (int i = 95; i >= 0; i--) {
    remainder = (remainder << 1) | (s21_get_bit(*decimal, i));
    if (remainder >= 10) {
      remainder -= 10;
      s21_set_bit(&result, i, 1);
    }
  }

  int scale = s21_get_scale(*decimal);
  if (scale > MIN_SCALE) {
    scale--;
    s21_set_scale(&result, scale);
  } else {
    check_error = MIN_SCALE;
  }
  s21_set_bit(&result, 127, s21_get_bit(*decimal, 127));
  *decimal = result;

  return check_error;
}

int s21_unsigned_negate_bits(s21_decimal value, s21_decimal* result) {
  int status = 0;
  s21_decimal ONE = {{1, 0, 0, 0}};

  value.bits[0] = ~value.bits[0];
  value.bits[1] = ~value.bits[1];
  value.bits[2] = ~value.bits[2];
  int tmp_bits_3 = value.bits[3];
  value.bits[3] = 0;

  status = s21_add(value, ONE, &value);

  *result = value;
  result->bits[3] = tmp_bits_3;

  return status;
}

int s21_add_bit(int value_1, int value_2, unsigned int* result) {
  int status = 0;
  int transposition = 0;
  int INT_BITS = 32;

  for (int i = 0; value_2 != 0 && i < INT_BITS; i++) {
    int bit_value = value_1 >> i & 1;

    value_1 ^= (value_2 >> i & 1) << i;
    value_2 &= ~(1 << i);

    transposition = (((value_1 >> i & 1) == 0) && (bit_value == 1));

    for (int k = i + 1; transposition && k < INT_BITS; k++) {
      bit_value = value_1 >> k & 1;
      value_1 ^= 1 << k;
      transposition = (((value_1 >> k & 1) == 0) && (bit_value == 1));
    }

    if (transposition) {
      status = 1;
    }
  }
  *result = value_1;

  return status;
}

int s21_shift_left_decimal(s21_decimal* value, int shift) {
  int status = 0;
  s21_decimal result = *value;
  int DECIMAL_N_BITS = 96;

  if (shift > DECIMAL_N_BITS - 1) {
    result.bits[0] = 0;
    result.bits[1] = 0;
    result.bits[2] = 0;
    status = 1 + s21_get_sign(result);
    shift = 0;
  }

  for (int i = shift; i > 0; i--) {
    int tmp_status = s21_add(result, result, &result);

    if (tmp_status) {
      status = tmp_status;
    }
  }

  *value = result;

  return status;
}

s21_decimal s21_div_quotient(s21_decimal value_1, s21_decimal value_2,
                             s21_decimal* result) {
  s21_decimal div_quotient = {{0, 0, 0, 0}};   // частное
  s21_decimal div_remainder = {{0, 0, 0, 0}};  // остаток
  int DECIMAL_N_INT = 3;
  int INT_BITS = 32;
  int MAX_BITS = INT_BITS * DECIMAL_N_INT - 1;

  for (int i = MAX_BITS; i >= 0; i--) {
    s21_shift_left_decimal(&div_remainder, 1);
    if (s21_get_bit(value_1, i) == 1) {
      div_remainder.bits[0] |= 1;
    }

    s21_shift_left_decimal(&div_quotient, 1);
    if (s21_is_greater_or_equal(div_remainder, value_2)) {
      s21_sub(div_remainder, value_2, &div_remainder);
      div_quotient.bits[0] |= 1;
    }
  }

  *result = div_quotient;

  return div_remainder;
}

void s21_div_value_increase_scale(s21_decimal* value_1, s21_decimal* value_2,
                                  int* scale) {
  s21_decimal TEN = {{10, 0, 0, 0}};

  s21_decimal div_quotient = *value_1;
  s21_decimal div_remainder = *value_2;

  int next_step = s21_mul(div_quotient, TEN, &div_quotient) == 0;
  next_step = (s21_mul(div_remainder, TEN, &div_remainder) == 0) && next_step;

  for (; next_step && (*scale) < MAX_SCALE; (*scale)++) {
    *value_1 = div_quotient;
    *value_2 = div_remainder;

    next_step = s21_mul(div_quotient, TEN, &div_quotient) == 0;
    next_step = (s21_mul(div_remainder, TEN, &div_remainder) == 0) && next_step;
  }
}

int mantiss_add(s21_decimal val1, s21_decimal val2, s21_decimal* result) {
  int ret = 0;
  result->bits[0] = val1.bits[0] + val2.bits[0];
  if (result->bits[0] < val2.bits[0] || result->bits[0] < val1.bits[0]) {
    val1.bits[1]++;
    if (val1.bits[1] == 0) {
      val1.bits[2]++;
      if (val1.bits[2] == 0) ret = 1;
    }
  }
  result->bits[1] = val1.bits[1] + val2.bits[1];
  if (result->bits[1] < val2.bits[1] || result->bits[1] < val1.bits[1]) {
    val1.bits[2]++;
    if (val1.bits[2] == 0) ret = 1;
  }
  result->bits[2] = val1.bits[2] + val2.bits[2];
  if (result->bits[2] < val2.bits[2] || result->bits[2] < val1.bits[2]) ret = 1;

  return ret;
}

int increase_exp(s21_decimal* dec) {
  if (get_ref(dec, exponenta) >= 28U) return 1;
  s21_decimal tmp = *dec;
  int error = s21_multiply_by_10(&tmp);

  if (!error) {
    dec->bits[0] = tmp.bits[0];
    dec->bits[1] = tmp.bits[1];
    dec->bits[2] = tmp.bits[2];
    get_ref(dec, exponenta)++;
  }
  return error;
}

int isnull(s21_decimal dec) {
  return dec.bits[0] == 0 && dec.bits[1] == 0 && dec.bits[2] == 0;
}

int s21_normalization_round(s21_decimal* value_1, s21_decimal* value_2) {
  int status = 0;
  s21_decimal tmp_value_1 = *value_1;
  s21_decimal tmp_value_2 = *value_2;
  int value_1_scale = s21_get_scale(*value_1);
  int value_2_scale = s21_get_scale(*value_2);

  status = s21_normalization_scale(value_1, value_2);

  if (s21_get_scale(*value_1) < value_1_scale) {
    int res_scale = s21_get_scale(*value_1);
    s21_set_scale(&tmp_value_1, value_1_scale - res_scale);
    s21_round(tmp_value_1, value_1);
    s21_set_scale(value_1, res_scale);
  }

  if (s21_get_scale(*value_2) < value_2_scale) {
    int res_scale = s21_get_scale(*value_2);
    s21_set_scale(&tmp_value_2, value_2_scale - res_scale);
    s21_round(tmp_value_2, value_2);
    s21_set_scale(value_2, res_scale);
  }

  return status;
}
