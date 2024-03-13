#include "my_decimal.h"

/*Converts decimal to float*/
int my_from_decimal_to_float(my_decimal src, float *dst) {
  int error_code = 0;
  if (dst == NULL || my_get_scale(src) > 28 || !is_last_bits_clear(&src)) {
    error_code = 1;
  } else {
    double temp_dest = 0;
    for (int i = 0; i < 96; i++) {
      temp_dest += my_get_bit(src, i) * pow(2, i);
    }
    temp_dest *= pow(10, (my_get_scale(src) * (-1)));
    if (my_get_sign(src)) {
      temp_dest *= -1;
    }
    char str[100] = {0};
    sprintf(str, "%.*lf", my_get_scale(src), temp_dest);
    sscanf(str, "%f", dst);
  }
  return error_code;
}