#include "my_decimal.h"

/*Rounds a decimal value to the nearest integer.*/
int my_round(my_decimal value, my_decimal* result) {
  int error_code = 0;
  int scale = my_get_scale(value);
  if (result == NULL || !is_last_bits_clear(&value) || scale > 28) {
    error_code = 1;
  } else if (scale > 0) {
    set_dec_to_zero(result);
    my_decimal res = value, dec_remainder = {0}, tmp = {0};
    int invisible_remainder = 0, round_check = 0;
    my_set_scale(&res, 0);
    my_set_sign(&res, 0);
    for (int i = 0; i < scale; i++) {
      my_get_remainder(&res, &tmp, &dec_remainder);
      if (dec_remainder.bits[0] && i < scale - 1) invisible_remainder = 1;
      if (i == scale - 1) round_check = (int)dec_remainder.bits[0];
      res = tmp;
    }
    if (round_check > 5 || (round_check == 5 && invisible_remainder)) {
      my_decimal_add_one(&res);
    } else if (round_check == 5 && !invisible_remainder) {
      my_get_remainder(&res, &tmp, &dec_remainder);
      if (dec_remainder.bits[0] % 2 != 0) my_decimal_add_one(&res);
    }
    *result = res;
    my_set_sign(result, my_get_sign(value));
  } else {
    *result = value;
  }
  return error_code;
}