#include "test.h"

START_TEST(decimal_test_mul_1) {
  my_decimal num1 = {{10, 0, 0, 0}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_2) {
  my_decimal num1 = {{357, 0, 0, 0}};
  my_decimal num2 = {{753, 0, 0, 0}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x00041A15);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_3) {
  my_decimal num1 = {{357, 357, 0, 0}};
  my_decimal num2 = {{753, 753, 0, 0}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x00041A15);
  ck_assert_uint_eq(num3.bits[1], 0x0008342A);
  ck_assert_uint_eq(num3.bits[2], 0x00041A15);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_4) {
  my_decimal num1 = {{0xFF7FF9F7, 0x7FEFEF1F, 0x0037F7FF, 0}};
  my_decimal num2 = {{793, 0, 0, 0}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x736D4E1F);
  ck_assert_uint_eq(num3.bits[1], 0x4E3BBA1E);
  ck_assert_uint_eq(num3.bits[2], 0xAD5F3673);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_5) {
  my_decimal num1 = {{0xFF7FF9F7, 0x7FEFEF1F, 0x0037F7FF, 0x001c0000}};
  my_decimal num2 = {{793, 0, 0, 0x001c0000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x00000005);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x001C0000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_6) {
  my_decimal num1 = {{25, 0, 0, 0x00020000}};
  my_decimal num2 = {{25, 0, 0, 0x00020000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x00000271);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00040000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_7) {
  my_decimal num1 = {{250, 7, 0, 0x80020000}};
  my_decimal num2 = {{25, 0, 0, 0x00020000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x0000186A);
  ck_assert_uint_eq(num3.bits[1], 0x000000AF);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x80040000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_8) {
  my_decimal num1 = {{250, 7, 0, 0x80020000}};
  my_decimal num2 = {{25, 0, 1, 0x80020000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xB33335A4);
  ck_assert_uint_eq(num3.bits[1], 0x33333344);
  ck_assert_uint_eq(num3.bits[2], 0xB333334C);
  ck_assert_uint_eq(num3.bits[3], 0x00030000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
START_TEST(decimal_test_mul_9) {
  my_decimal num1 = {{250, 97, 0, 0x80020000}};
  my_decimal num2 = {{25, 0, 73, 0x80050000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xBB6AE7D6);
  ck_assert_uint_eq(num3.bits[1], 0x1F62B6AE);
  ck_assert_uint_eq(num3.bits[2], 0xB5460AA8);
  ck_assert_uint_eq(num3.bits[3], 0x00030000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_10) {
  my_decimal num1 = {{250, 597, 1, 0x00050000}};
  my_decimal num2 = {{25, 0, 695, 0x80090000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xB4FB4E1A);
  ck_assert_uint_eq(num3.bits[1], 0x53D3B997);
  ck_assert_uint_eq(num3.bits[2], 0x4C6A837B);
  ck_assert_uint_eq(num3.bits[3], 0x80010000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_11) {
  my_decimal num1 = {{7250, 1797, 1, 0x00050000}};
  my_decimal num2 = {{4925, 531, 3695, 0x80090000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xBA14B106);
  ck_assert_uint_eq(num3.bits[1], 0xBA8265EE);
  ck_assert_uint_eq(num3.bits[2], 0x28A08136);
  ck_assert_uint_eq(num3.bits[3], 0x80000000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_12) {
  my_decimal num1 = {{72501935, 17973, 12345, 0x80110000}};
  my_decimal num2 = {{492543, 5315893, 369512, 0x80090000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x8403F9F4);
  ck_assert_uint_eq(num3.bits[1], 0x83EB9FC7);
  ck_assert_uint_eq(num3.bits[2], 0x3227D5B2);
  ck_assert_uint_eq(num3.bits[3], 0x00060000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_13) {
  my_decimal num1 = {{72501935, 17973, 9123745, 0x80110000}};
  my_decimal num2 = {{492543, 5315893, 57369512, 0x80090000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xD376909E);
  ck_assert_uint_eq(num3.bits[1], 0x8F2E6BD1);
  ck_assert_uint_eq(num3.bits[2], 0x398D1929);
  ck_assert_uint_eq(num3.bits[3], 0x00010000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_14) {
  my_decimal num1 = {{72501935, 17973, 9123745, 0x80110000}};
  my_decimal num2 = {{4925433, 53158934, 57369512, 0x80090000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xEC22A01B);
  ck_assert_uint_eq(num3.bits[1], 0xBF2D0553);
  ck_assert_uint_eq(num3.bits[2], 0x398D1929);
  ck_assert_uint_eq(num3.bits[3], 0x00010000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_15) {
  my_decimal num1 = {{72501935, 1797323, 91237451, 0x80110000}};
  my_decimal num2 = {{4925433, 53158934, 57369512, 0x80090000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xBCBC2420);
  ck_assert_uint_eq(num3.bits[1], 0x55651307);
  ck_assert_uint_eq(num3.bits[2], 0x398D1934);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_16) {
  my_decimal num1 = {{1725019353, 1317397329, 392002059, 0x80110000}};
  my_decimal num2 = {{1492543345, 2131589349, 59395259, 0x80090000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xF79A2829);
  ck_assert_uint_eq(num3.bits[1], 0x2A948B48);
  ck_assert_uint_eq(num3.bits[2], 0xFFFFFFC3);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_17) {
  my_decimal num1 = {{1725019353, 1317397329, 392005059, 0x80110000}};
  my_decimal num2 = {{1492543345, 2131589349, 59395259, 0x80090000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_msg(error == 1, "my_add_1 failed");
}
END_TEST

START_TEST(decimal_test_mul_18) {
  my_decimal num1 = {{2, 0, 0, 0x001c0000}};
  my_decimal num2 = {{2, 0, 0, 0x001c0000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_msg(error == 2, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_19) {
  my_decimal num1 = {{1000, 1000, 1000, 0x801E0000}};
  my_decimal num2 = {{1, 1, 1, 0x80090000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_msg(error == 1, "my_add_1 failed");
}
END_TEST

START_TEST(decimal_test_mul_20) {
  my_decimal num1 = {{2, 0, 0, 0x001c0021}};
  my_decimal num2 = {{2, 0, 0, 0x001c0000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_msg(error == 1, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_21) {
  my_decimal num1 = {{1000, 1000, 1000, 0x80000000}};
  my_decimal num2 = {{1, 1, 1, 0x801E0000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_msg(error == 1, "my_add_1 failed");
}
END_TEST

START_TEST(decimal_test_mul_22) {
  my_decimal num1 = {{2, 0, 0, 0x001c0000}};
  my_decimal num2 = {{2, 0, 0, 0x001c0012}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_msg(error == 1, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_23) {
  my_decimal num1 = {{2, 0, 0, 0x001c0000}};
  my_decimal num2 = {{2, 0, 0, 0x001c0012}};
  // my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, NULL);
  ck_assert_msg(error == 1, "my_add_1 failed");
}
END_TEST
START_TEST(decimal_test_mul_24) {
  my_decimal num1 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};
  my_decimal num2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  my_decimal num3 = {{0}};
  int error = my_mul(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0x1);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x1C0000);
  ck_assert_msg(error == 0, "my_add_1 failed");
}
END_TEST

Suite *suite_decimal_mul() {
  Suite *suite = suite_create("suite_decimal_mul");
  TCase *tcase = tcase_create("tcase_decimal_mul");

  tcase_add_test(tcase, decimal_test_mul_1);
  tcase_add_test(tcase, decimal_test_mul_2);
  tcase_add_test(tcase, decimal_test_mul_3);
  tcase_add_test(tcase, decimal_test_mul_4);
  tcase_add_test(tcase, decimal_test_mul_5);
  tcase_add_test(tcase, decimal_test_mul_6);
  tcase_add_test(tcase, decimal_test_mul_7);
  tcase_add_test(tcase, decimal_test_mul_8);
  tcase_add_test(tcase, decimal_test_mul_9);
  tcase_add_test(tcase, decimal_test_mul_10);
  tcase_add_test(tcase, decimal_test_mul_11);
  tcase_add_test(tcase, decimal_test_mul_12);
  tcase_add_test(tcase, decimal_test_mul_13);
  tcase_add_test(tcase, decimal_test_mul_14);
  tcase_add_test(tcase, decimal_test_mul_15);
  tcase_add_test(tcase, decimal_test_mul_16);
  tcase_add_test(tcase, decimal_test_mul_17);
  tcase_add_test(tcase, decimal_test_mul_18);
  tcase_add_test(tcase, decimal_test_mul_19);
  tcase_add_test(tcase, decimal_test_mul_20);
  tcase_add_test(tcase, decimal_test_mul_21);
  tcase_add_test(tcase, decimal_test_mul_22);
  tcase_add_test(tcase, decimal_test_mul_23);
  tcase_add_test(tcase, decimal_test_mul_24);

  suite_add_tcase(suite, tcase);
  return suite;
}