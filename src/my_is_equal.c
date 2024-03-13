#include "my_decimal.h"

/*Returns 1 if two decimals are equal*/
int my_is_equal(my_decimal val_1, my_decimal val_2) {
  int is_equal = 0;
  if (!my_decimal_not_empty(&val_1) && !my_decimal_not_empty(&val_2))
    is_equal++;
  if (my_get_sign(val_1) == my_get_sign(val_2) && !is_equal) {
    int scale_1 = my_get_scale(val_1);
    int scale_2 = my_get_scale(val_2);
    my_big_decimal big_val_1 = {0}, big_val_2 = {0};
    num_to_big_decimal(&big_val_1, val_1);
    num_to_big_decimal(&big_val_2, val_2);
    my_big_normalization(&big_val_1, &big_val_2, scale_1, scale_2);
    is_equal += my_big_is_equal(&big_val_1, &big_val_2);
  }

  return is_equal;
}