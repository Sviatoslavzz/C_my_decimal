#include "test.h"
START_TEST(test_1) {
  my_decimal num1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x001c0000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 7);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_2) {
  my_decimal num1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x801c0000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, -7);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_3) {
  my_decimal num1 = {{0, 0, 0, 0x00000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_4) {
  my_decimal num1 = {{INT32_MAX, INT32_MAX, INT32_MAX, 0x00000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_5) {
  my_decimal num1 = {{0, 10, 0, 0x00120000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_6) {
  my_decimal num1 = {{0, 10, 0, 0x80120000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_7) {
  my_decimal num1 = {{0, 1, 0, 0x80050000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, -42949);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_8) {
  my_decimal num1 = {{2147483648, 0, 0, 0x00000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_9) {
  my_decimal num1 = {{2147483648, 0, 0, 0x80000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, -2147483648);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_10) {
  my_decimal num1 = {{101, 0, 0, 0x0020000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 1);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_11) {
  my_decimal num1 = {{0b111010110111100110100010101, 0, 0, 0x00020000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 1234567);
  ck_assert_int_eq(error_code, 0);
}
START_TEST(test_12) {
  my_decimal num1 = {{0b111010110111100110100010101, 0, 0, 0x00020001}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_13) {
  my_decimal num1 = {{0, 0, 10, 0x001c0000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_14) {
  my_decimal num1 = {{0, 0, 100, 0x801c0000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_15) {
  my_decimal num1 = {{1, 0, 0, 0x001E0000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_16) {
  my_decimal num1 = {{0, INT32_MAX, INT32_MAX, 0x001f0000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_17) {
  my_decimal num1 = {{1, 10, 1, 0x000f0000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 18446);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_18) {
  my_decimal num1 = {{1, 0, 0, 0x81030000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_19) {
  my_decimal num1 = {{1, 0, 0, 0x88050000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_20) {
  my_decimal num1 = {{0, 0, 0, 0x00000001}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_21) {
  my_decimal num1 = {{0, 0, 0, 0x01000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_22) {
  my_decimal num1 = {{1999999999, 0, 0, 0x0000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 1999999999);
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_23) {
  my_decimal num1 = {{UINT32_MAX, 0, 0, 0x00020000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 42949672);
  ck_assert_int_eq(error_code, 0);
}
START_TEST(test_24) {
  my_decimal num1 = {{0b111010110111100110100010101, 0, 0, 0x84000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_25) {
  my_decimal num1 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, -2147483648);
  ck_assert_int_eq(error_code, 0);
}
START_TEST(test_26) {
  my_decimal num1 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, -2147483648);
  ck_assert_int_eq(error_code, 0);
}
START_TEST(test_27) {
  my_decimal num1 = {{0x0, 0x32, 0x0, 0x80020000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, -2147483648);
  ck_assert_int_eq(error_code, 0);
}
START_TEST(test_28) {
  my_decimal num1 = {{0x63, 0x32, 0x0, 0x80020000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, -2147483648);
  ck_assert_int_eq(error_code, 0);
}
START_TEST(test_29) {
  my_decimal num1 = {{0xA763FFFF, 0xE192B6B3, 0x6F05B59, 0x80120000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, -2147483648);
  ck_assert_int_eq(error_code, 0);
}
START_TEST(test_30) {
  my_decimal num1 = {{0xA763FFFF, 0xE192B6B3, 0x6F05B59, 0x80120000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, NULL);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
START_TEST(test_31) {
  my_decimal num1 = {{1, UINT32_MAX, 0, 0x00000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
START_TEST(test_32) {
  my_decimal num1 = {{1, 0, UINT32_MAX, 0x00000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
START_TEST(test_33) {
  my_decimal num1 = {{4294967295, 4294967295, 429496729, 0x00020000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
START_TEST(test_34) {
  my_decimal num1 = {{4294967295, 0, 0, 0x80000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
START_TEST(test_35) {
  my_decimal num1 = {{4294967295, 0, 0, 0x80000000}};
  int num2 = 0;
  int error_code = my_from_decimal_to_int(num1, &num2);
  ck_assert_int_eq(num2, 0);
  ck_assert_int_eq(error_code, 1);
}
Suite *suite_from_decimal_to_int() {
  Suite *suite = suite_create("suite_from_decimal_to_int");
  TCase *tcase = tcase_create("tcase_from_decimal_to_int");

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
  tcase_add_test(tcase, test_16);
  tcase_add_test(tcase, test_17);
  tcase_add_test(tcase, test_18);
  tcase_add_test(tcase, test_19);
  tcase_add_test(tcase, test_20);
  tcase_add_test(tcase, test_21);
  tcase_add_test(tcase, test_22);
  tcase_add_test(tcase, test_23);
  tcase_add_test(tcase, test_24);
  tcase_add_test(tcase, test_25);
  tcase_add_test(tcase, test_26);
  tcase_add_test(tcase, test_27);
  tcase_add_test(tcase, test_28);
  tcase_add_test(tcase, test_29);
  tcase_add_test(tcase, test_30);
  tcase_add_test(tcase, test_31);
  tcase_add_test(tcase, test_32);
  tcase_add_test(tcase, test_33);
  tcase_add_test(tcase, test_34);
  tcase_add_test(tcase, test_35);

  suite_add_tcase(suite, tcase);
  return suite;
}