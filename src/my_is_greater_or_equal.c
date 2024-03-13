#include "my_decimal.h"

/*Returns 1 if decimal val_1 is greater or equal than val_2*/
int my_is_greater_or_equal(my_decimal val_1, my_decimal val_2) {
  return !my_is_less(val_1, val_2);
}