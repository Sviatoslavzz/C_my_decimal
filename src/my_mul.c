#include "my_decimal.h"

/*Multiply of two decimal numbers*/
int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int error = 0;
  if (result == NULL || my_get_scale(value_1) > 28 ||
      my_get_scale(value_2) > 28 || !is_last_bits_clear(&value_1) ||
      !is_last_bits_clear(&value_2)) {
    error = 1;
  } else if (my_decimal_not_empty(&value_1) && my_decimal_not_empty(&value_2)) {
    my_big_decimal big_1 = {0}, big_2 = {0}, big_3 = {0};
    my_decimal tmp = {0};
    num_to_big_decimal(&big_1, value_1);
    num_to_big_decimal(&big_2, value_2);
    for (int i = 0; i < 223; i++) {
      if (my_big_get_bit(big_2, i)) {
        my_big_sum(big_1, big_3, &big_3);
      }
      my_big_left_shift(&big_1, 1);
    }
    my_set_scale(&tmp, my_get_scale(value_1) + my_get_scale(value_2));
    error = my_big_overflow(&big_3, &tmp);
    if (error == 1 && (my_get_sign(value_1) ^ my_get_sign(value_2))) error++;
    if (!error) {
      my_set_sign(&tmp, my_get_sign(value_1) ^ my_get_sign(value_2));
      *result = tmp;
      big_decimal_to_num(big_3, result);
    }
  } else {
    set_dec_to_zero(result);
  }
  return error;
}