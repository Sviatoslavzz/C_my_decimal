#include "test.h"

int main() {
  Suite* cases[] = {suite_decimal_1(),
                    suite_from_decimal_to_int(),
                    suite_from_decimal_to_float(),
                    suite_comparators(),
                    suite_decimal_div(),
                    suite_from_int_to_decimal(),
                    suite_truncate(),
                    suite_negate(),
                    suite_round(),
                    suite_floor(),
                    suite_float_to_decimal(),
                    suite_decimal_sub(),
                    suite_decimal_mul()};

  for (int i = 0; i < 13; i++) {
    printf("\n");
    SRunner* sr = srunner_create(cases[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }
  return 0;
}
