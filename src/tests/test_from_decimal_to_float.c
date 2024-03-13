#include "test.h"
START_TEST(test_1) {
  my_decimal num1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x00000000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, 79228162514264337593543950335.000000);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_2) {
  my_decimal num1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x001c0000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, 7.9228162514264337593543950335);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_3) {
  my_decimal num1 = {{0, 0, 0, 0x00000000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, 0.000000);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_4) {
  my_decimal num1 = {{0, 0, 0, 0x80000000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, -0.000000);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_5) {
  my_decimal num1 = {{0b111010110111100110100010101, 0, 0, 0x00030000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, 123456.789);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_6) {
  my_decimal num1 = {{199999, 0, 0, 0x80050000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, -1.99999);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_7) {
  my_decimal num1 = {{199999, 0, 0, 0x00140000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, 0.00000000000000199999);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_8) {
  my_decimal num1 = {{0b111010110111100110100010101,
                      0b111010110111100110100010101,
                      0b111010110111100110100010101, 0x80110000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, -22773757913.75203432488750357);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_9) {
  my_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x80000000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, -79228162514264337593543950335.000000);
  ck_assert_int_eq(error_code, 0);
}
END_TEST

START_TEST(test_10) {
  my_decimal num1 = {{123123123, 0, 0, 0x80060000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, -123.123123);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_11) {
  my_decimal num1 = {{1, 1, 1, 0x00090000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, 18446744078.004518913);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_12) {
  my_decimal num1 = {{0b11111111111111111111111111111111, 0, 0, 0x80000000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, -4294967295);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_13) {  // Scale overflow
  my_decimal num1 = {{1, 1, 1, 0x001E0000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_14) {
  my_decimal num1 = {{0b11111111111111111111111111111111, 0, 0, 0x80010001}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, &num2);
  ck_assert_float_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
START_TEST(test_15) {
  my_decimal num1 = {{1000, 0, 0, 0x80010000}};
  float num2 = 0;
  int error_code = my_from_decimal_to_float(num1, NULL);
  ck_assert_float_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST

Suite *suite_from_decimal_to_float() {
  Suite *suite = suite_create("suite_from_decimal_to_float");
  TCase *tcase = tcase_create("tcase_from_decimal_to_float");

  tcase_add_test(tcase, test_1);
  tcase_add_test(tcase, test_2);
  tcase_add_test(tcase, test_3);
  tcase_add_test(tcase, test_4);
  tcase_add_test(tcase, test_5);
  tcase_add_test(tcase, test_6);
  tcase_add_test(tcase, test_7);
  tcase_add_test(tcase, test_8);
  tcase_add_test(tcase, test_9);
  tcase_add_test(tcase, test_10);
  tcase_add_test(tcase, test_11);
  tcase_add_test(tcase, test_12);
  tcase_add_test(tcase, test_13);
  tcase_add_test(tcase, test_14);
  tcase_add_test(tcase, test_15);

  suite_add_tcase(suite, tcase);
  return suite;
}