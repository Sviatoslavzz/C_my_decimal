#include "my_decimal.h"

/*Division of two decimal numbers*/
int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int error = 0;
  if (result == NULL || my_get_scale(value_1) > 28 ||
      my_get_scale(value_2) > 28 || !is_last_bits_clear(&value_1) ||
      !is_last_bits_clear(&value_2)) {
    error = 1;
  } else if (!my_decimal_not_empty(&value_2)) {
    error = 3;
  } else {
    my_decimal result_res = *result;
    my_big_decimal big_1 = {0}, big_2 = {0}, big_3 = {0};
    num_to_big_decimal(&big_1, value_1);
    num_to_big_decimal(&big_2, value_2);
    int scale_1 = my_get_scale(value_1), scale_2 = my_get_scale(value_2);
    my_big_normalization(&big_1, &big_2, scale_1, scale_2);
    set_dec_to_zero(&result_res);
    while (my_big_decimal_not_empty(&big_1) && my_get_scale(result_res) <= 30) {
      my_big_decimal big_4 = big_2;
      int tmp = 0;
      my_big_decimal num_3 = {{1, 0, 0, 0, 0, 0, 0, 0}};
      while (!my_big_is_greater_or_equal(&big_1, &big_4, 0)) {
        my_big_multi_ten(&big_1);
        my_big_multi_ten(&big_3);
        my_set_scale(&result_res, my_get_scale(result_res) + 1);
      }
      while (my_big_is_greater_or_equal(&big_1, &big_4, 0)) {
        my_big_left_shift(&big_4, 1);
        tmp++;
      }
      big_4 = big_2;
      for (int i = 0; i < tmp - 1; i++) {
        my_big_left_shift(&big_4, 1);
        my_big_left_shift(&num_3, 1);
      }
      my_big_sub(big_1, big_4, &big_1);
      my_big_sum(big_3, num_3, &big_3);
    }
    error = my_big_overflow(&big_3, &result_res);
    if (error == 1 && (my_get_sign(value_1) ^ my_get_sign(value_2))) error++;
    if (!error) {
      *result = result_res;
      my_set_scale(result, my_get_scale(result_res));
      my_set_sign(result, my_get_sign(value_1) ^ my_get_sign(value_2));
      big_decimal_to_num(big_3, result);
    }
  }
  return error;
}