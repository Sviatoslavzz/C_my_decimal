#include "my_decimal.h"

/*Returns the integral digits of the specified Decimal; any fractional digits
 * are discarded, including trailing zeroes.*/
int my_truncate(my_decimal value, my_decimal *result) {
  int error_code = 0;
  int scale = my_get_scale(value);
  if (result == NULL || scale > 28 || !is_last_bits_clear(&value)) {
    error_code = 1;
  } else if (scale > 0) {
    set_dec_to_zero(result);
    my_decimal tmp = value, res;
    my_set_scale(&tmp, 0);
    my_set_sign(&tmp, 0);
    res = tmp;
    for (int i = 0; i < scale; i++) {
      my_div_ten(res, &tmp);
      res = tmp;
    }
    *result = res;
    my_set_sign(result, my_get_sign(value));
  } else {
    *result = value;
  }
  return error_code;
}