#include <check.h>
#include <float.h>
#include <stdio.h>

#include "../my_decimal.h"

#define MY_MAX_FLOAT 79228162514264337593543950335.0f

Suite *suite_decimal_1();
Suite *suite_decimal_div();
Suite *suite_from_decimal_to_int();
Suite *suite_from_decimal_to_float();
Suite *suite_comparators();
Suite *suite_from_int_to_decimal();
Suite *suite_truncate();
Suite *suite_negate();
Suite *suite_round();
Suite *suite_floor();
Suite *suite_float_to_decimal();
Suite *suite_decimal_sub();
Suite *suite_decimal_mul();