#include "my_decimal.h"

/*Returns 1 if decimal val_1 is less or equal than val_2*/
int my_is_less_or_equal(my_decimal val_1, my_decimal val_2) {
  return my_is_equal(val_1, val_2) || my_is_less(val_1, val_2);
}