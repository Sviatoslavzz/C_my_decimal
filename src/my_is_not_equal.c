#include "my_decimal.h"

/*Returns 1 if two decimals are not equal*/
int my_is_not_equal(my_decimal val_1, my_decimal val_2) {
  return !my_is_equal(val_1, val_2);
}