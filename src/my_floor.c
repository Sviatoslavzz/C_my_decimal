#include "my_decimal.h"

/*Rounds a specified Decimal number to the closest integer toward negative
 * infinity.*/
int my_floor(my_decimal value, my_decimal *result) {
  int error_code = 0;
  int scale = my_get_scale(value);
  if (result == NULL || scale > 28 || !is_last_bits_clear(&value)) {
    error_code = 1;
  } else if (scale > 0) {
    set_dec_to_zero(result);
    my_decimal tmp = value, dec_remainder = {0}, res = {0}, tmp2 = {0};
    my_set_scale(&tmp, 0);
    my_set_sign(&tmp, 0);
    res = tmp;
    tmp2 = tmp;
    for (int i = 0; i < scale; i++) {
      my_div_ten(res, &tmp);
      res = tmp;
    }
    for (int i = 0; i < scale; i++) {
      my_multi_ten(&tmp);
    }
    my_sub(tmp2, tmp, &dec_remainder);
    if (my_decimal_not_empty(&dec_remainder)) {
      float f = 0;
      my_from_decimal_to_float(dec_remainder, &f);
      for (int i = 0; i < scale - 1; i++) {
        f /= 10;
      }
      if (my_get_sign(value)) {
        my_decimal add = {{1, 0, 0, 0}};
        my_sum(res, add, &res);
      }
    }
    *result = res;
    my_set_sign(result, my_get_sign(value));
  } else {
    *result = value;
  }
  return error_code;
}