#include "my_decimal.h"

/*Subtraction of two decimal numbers*/
int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int error = 0;
  if (result == NULL || my_get_scale(value_1) > 28 ||
      my_get_scale(value_2) > 28 || !is_last_bits_clear(&value_1) ||
      !is_last_bits_clear(&value_2)) {
    error = 1;
  } else {
    my_big_decimal big_1 = {0}, big_2 = {0}, big_3 = {0};
    my_decimal num_1 = value_1, num_2 = value_2, tmp = {0};
    my_set_sign(&num_1, 0), my_set_sign(&num_2, 0);

    num_to_big_decimal(&big_1, value_1);
    num_to_big_decimal(&big_2, value_2);
    int scale_1 = my_get_scale(value_1), scale_2 = my_get_scale(value_2);
    int sign_1 = my_get_sign(value_1), sign_2 = my_get_sign(value_2);
    int diff = my_is_less(num_1, num_2);

    my_big_normalization(&big_1, &big_2, scale_1, scale_2);
    if (sign_1 ^ sign_2) {
      my_big_sum(big_1, big_2, &big_3);
      my_set_sign(&tmp, (!diff && sign_1) || (diff && !sign_2) ? 1 : 0);
    } else {
      my_big_sub(diff ? big_2 : big_1, diff ? big_1 : big_2, &big_3);
      my_set_sign(&tmp, (diff && !sign_1) || (!diff && sign_1) ? 1 : 0);
    }
    my_set_scale(&tmp, scale_1 > scale_2 ? scale_1 : scale_2);
    error = my_big_overflow(&big_3, &tmp);
    if (error == 1 && my_get_sign(tmp)) error++;
    if (!error) {
      *result = tmp;
      big_decimal_to_num(big_3, result);
    }
  }

  return error;
}