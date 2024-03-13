#include "my_decimal.h"

/* Transform int value to decimal*/
int my_from_int_to_decimal(int src, my_decimal *dst) {
  int error_code = 0;
  if (dst == NULL) {
    error_code++;
  } else {
    set_dec_to_zero(dst);
    if (src < 0) {
      my_set_sign(dst, 1);
      src *= (-1);
    }
    dst->bits[0] = src;
  }
  return error_code;
}