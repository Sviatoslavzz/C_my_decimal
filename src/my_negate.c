#include "my_decimal.h"

/*Returns the result of multiplying the specified Decimal value by negative
 * one.*/
int my_negate(my_decimal value, my_decimal *result) {
  int error_code = 0;
  if (result == NULL || my_get_scale(value) > 28 ||
      !is_last_bits_clear(&value)) {
    error_code = 1;
  } else {
    *result = value;
    my_set_sign(result, !my_get_sign(value));
  }
  return error_code;
}
