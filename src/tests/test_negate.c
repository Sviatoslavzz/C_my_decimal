#include "test.h"

START_TEST(test_1) {
  my_decimal num1 = {{12345, 0, 0, 0x00030000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{12345, 0, 0, 0x80030000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_2) {
  my_decimal num1 = {{54321, 0, 0, 0x80040000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{54321, 0, 0, 0x00040000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_3) {
  my_decimal num1 = {{1, 0, 0, 0x001c0000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{1, 0, 0, 0x801c0000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_4) {
  my_decimal num1 = {{0, 0, 0, 0}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_5) {
  my_decimal num1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x801c0000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0xffffffff, 0xffffffff, 0xffffffff, 0x001c0000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_6) {
  my_decimal num1 = {{0xfffffffe, 0xfffffffe, 0xfffffffe, 0x001c0000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0xfffffffe, 0xfffffffe, 0xfffffffe, 0x801c0000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_7) {
  my_decimal num1 = {{1, 1, 1, 0x80020000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{1, 1, 1, 0x00020000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_8) {
  my_decimal num1 = {{0b111010110111111000000111101, 0, 0, 0x80050000}};
  my_decimal num2 = {{0, 0, 0, 0x00000000}};
  my_decimal test_num = {{0b111010110111111000000111101, 0, 0, 0x00050000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_9) {
  my_decimal num1 = {{1, 1, 0, 0x80020000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{1, 1, 0, 0x00020000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_10) {
  my_decimal num1 = {{19999, 0, 0, 0x00020000}};
  my_decimal num2 = {{0, 0, 0, 0x00000000}};
  my_decimal test_num = {{19999, 0, 0, 0x80020000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_11) {
  my_decimal num1 = {{123, 123, 123, 0x00030000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{123, 123, 123, 0x80030000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_12) {
  my_decimal num1 = {{123456789, 0, 0, 0x80060000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{123456789, 0, 0, 0x00060000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_13) {
  my_decimal num1 = {{0xFFFFFFFF, 0, 0, 0x00070000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0xFFFFFFFF, 0, 0, 0x80070000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_14) {
  my_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0x800f0000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0x000f0000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_15) {
  my_decimal num1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x00100000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0xffffffff, 0xffffffff, 0xffffffff, 0x80100000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_16) {
  my_decimal num1 = {{0b11111111111111111111111111111111,
                      0b11111111111111111111111111111111,
                      0b11111111111111111111111111111111, 0x001c0000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0x801c0000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_17) {
  my_decimal num1 = {{0b11111111111111111111111111111111,
                      0b11111111111111111111111111111111,
                      0b11111111111111111111111111111111, 0x801c0000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111,
                          0b11111111111111111111111111111111, 0x001c0000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_18) {
  my_decimal num1 = {{21, 31, 41, 0x80090000}};
  my_decimal num2 = {{0, 0, 0, 0x00000000}};
  my_decimal test_num = {{21, 31, 41, 0x00090000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_19) {
  my_decimal num1 = {{11112222, 0, 0, 0x00070000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{11112222, 0, 0, 0x80070000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_20) {
  my_decimal num1 = {{0, 1, 0, 0x00020000}};
  my_decimal num2 = {{0, 0, 0, 0x00000000}};
  my_decimal test_num = {{0, 1, 0, 0x80020000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_21) {
  my_decimal num1 = {{1000000, 0, 0, 0x00060000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{1000000, 0, 0, 0x80060000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_22) {
  my_decimal num1 = {{1234565, 0, 0, 0x80040000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{1234565, 0, 0, 0x00040000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_23) {
  my_decimal num1 = {{999999, 0, 0, 0x001c0000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{999999, 0, 0, 0x801c0000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_24) {
  my_decimal num1 = {{100, 100, 1000, 0x000f0000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{100, 100, 1000, 0x800f0000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_25) {
  my_decimal num1 = {{0xffffffff, 0, 0xffffffff, 0x801a0000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0xffffffff, 0, 0xffffffff, 0x001a0000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_26) {
  my_decimal num1 = {{0xfffffffe, 0xfffffffe, 0xfffffffe, 0x00140000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0xfffffffe, 0xfffffffe, 0xfffffffe, 0x80140000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_27) {
  my_decimal num1 = {{1, 1, 0xfffffffe, 0x80020000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{1, 1, 0xfffffffe, 0x00020000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_28) {
  my_decimal num1 = {{0b111010110111111000000111101, 0, 0, 0x80090000}};
  my_decimal num2 = {{0, 0, 0, 0x00000000}};
  my_decimal test_num = {{0b111010110111111000000111101, 0, 0, 0x00090000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_29) {
  my_decimal num1 = {{1, 0, 1, 0x80040000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{1, 0, 1, 0x00040000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_30) {
  my_decimal num1 = {{12983476, 0, 0, 0x00070000}};
  my_decimal num2 = {{0, 0, 0, 0x00000000}};
  my_decimal test_num = {{12983476, 0, 0, 0x80070000}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_31) {
  my_decimal num1 = {{1, 0, 0, 0x001E0000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0, 0, 0, 0}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_32) {
  my_decimal num1 = {{12983476, 0, 0, 0x01000001}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0, 0, 0, 0}};
  int error_code = my_negate(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_33) {
  my_decimal num1 = {{12983476, 0, 0, 0x00000000}};
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0, 0, 0, 0}};
  int error_code = my_negate(num1, NULL);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 1);
}
END_TEST

Suite *suite_negate() {
  Suite *suite = suite_create("suite_negate");
  TCase *tcase = tcase_create("tcase_negate");

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

  suite_add_tcase(suite, tcase);
  return suite;
}