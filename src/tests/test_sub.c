#include "test.h"

START_TEST(decimal_test_sub_1) {
  my_decimal num1 = {{1, 0, 0, 0}};
  my_decimal num2 = {{1, 0, 0, 0}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_2) {
  my_decimal num1 = {{0xfffffffe, 0xfffffffe, 0xfffffffe, 0}};
  my_decimal num2 = {{1, 1, 1, 0}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0xfffffffd, 0xfffffffd, 0xfffffffd, 0}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xfffffffd);
  ck_assert_uint_eq(num3.bits[1], 0xfffffffd);
  ck_assert_uint_eq(num3.bits[2], 0xfffffffd);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_3) {
  my_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  my_decimal num2 = {{1, 0, 0, 0}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{4294967294, 4294967295, 4294967295, 0}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 4294967294);
  ck_assert_uint_eq(num3.bits[1], 4294967295);
  ck_assert_uint_eq(num3.bits[2], 4294967295);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_4) {
  my_decimal num1 = {{0, 0, 0, 0}};
  my_decimal num2 = {{1, 0, 0, 0}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{1, 0, 0, 0x80000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 1);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x80000000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_5) {
  my_decimal num1 = {{0, 0, 0, 0}};
  my_decimal num2 = {{0, 0, 1, 0}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 1, 0x80000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 1);
  ck_assert_uint_eq(num3.bits[3], 0x80000000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_6) {
  my_decimal num1 = {{0xffffffff, 0xffffffff, 0, 0x00030000}};
  my_decimal num2 = {{1, 0, 0, 0}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{4294966295, 4294967295, 0, 0x00030000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 4294966295);
  ck_assert_uint_eq(num3.bits[1], 4294967295);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00030000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
  ;
}
END_TEST
START_TEST(decimal_test_sub_7) {
  my_decimal num1 = {{0xfffffffe, 0xffffffff, 0xffffffff, 0x00030000}};
  my_decimal num2 = {{1, 0, 0, 0x00030000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{4294967293, 4294967295, 4294967295, 0x00030000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0xFFFFFFFD);
  ck_assert_uint_eq(num3.bits[1], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[2], 0xFFFFFFFF);
  ck_assert_uint_eq(num3.bits[3], 0x00030000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
  ;
}
END_TEST
START_TEST(decimal_test_sub_8) {
  my_decimal num1 = {{1000, 1000, 0, 0x00030000}};
  my_decimal num2 = {{1, 1, 1, 0x80000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{2000, 2000, 1000, 0x00030000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 2000);
  ck_assert_uint_eq(num3.bits[1], 2000);
  ck_assert_uint_eq(num3.bits[2], 1000);
  ck_assert_uint_eq(num3.bits[3], 0x00030000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_9) {
  my_decimal num1 = {{1000, 1000, 0, 0x00000000}};
  my_decimal num2 = {{1000, 1000, 1000, 0x80000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{2000, 2000, 1000, 0x00000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 2000);
  ck_assert_uint_eq(num3.bits[1], 2000);
  ck_assert_uint_eq(num3.bits[2], 1000);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_10) {  // Overflow
  my_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x00000000}};
  my_decimal num2 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0x80000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 1);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST

START_TEST(decimal_test_sub_11) {
  my_decimal num1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  my_decimal num2 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_12) {
  my_decimal num1 = {{0, 0, 0, 0x001c0000}};
  my_decimal num2 = {{0, 0, 0, 0x80000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 0, 0x001c0000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x001c0000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_13) {
  my_decimal num1 = {{1, 1, 0, 0x00000000}};
  my_decimal num2 = {{1, 1, 1, 0x80000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{2, 2, 1, 0x00000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 2);
  ck_assert_uint_eq(num3.bits[1], 2);
  ck_assert_uint_eq(num3.bits[2], 1);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_14) {
  my_decimal num1 = {{1, 1, 0, 0x80000000}};
  my_decimal num2 = {{1, 1, 1, 0x00000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{2, 2, 1, 0x80000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 2);
  ck_assert_uint_eq(num3.bits[1], 2);
  ck_assert_uint_eq(num3.bits[2], 1);
  ck_assert_uint_eq(num3.bits[3], 0x80000000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_15) {
  my_decimal num1 = {{1, 1, 1, 0x00000000}};
  my_decimal num2 = {{1, 1, 0, 0x80000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{2, 2, 1, 0x00000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 2);
  ck_assert_uint_eq(num3.bits[1], 2);
  ck_assert_uint_eq(num3.bits[2], 1);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_16) {
  my_decimal num1 = {{1, 1, 1, 0x80000000}};
  my_decimal num2 = {{1, 1, 0, 0x00000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{2, 2, 1, 0x80000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 2);
  ck_assert_uint_eq(num3.bits[1], 2);
  ck_assert_uint_eq(num3.bits[2], 1);
  ck_assert_uint_eq(num3.bits[3], 0x80000000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_17) {
  my_decimal num1 = {{1, 1, 0, 0x00000000}};
  my_decimal num2 = {{1, 1, 1, 0x00000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 1, 0x80000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 1);
  ck_assert_uint_eq(num3.bits[3], 0x80000000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_18) {
  my_decimal num1 = {{1, 1, 1, 0x00000000}};
  my_decimal num2 = {{1, 1, 0, 0x00000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 1, 0x00000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 1);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_19) {
  my_decimal num1 = {{1, 1, 1, 0x80000000}};
  my_decimal num2 = {{1, 1, 0, 0x80000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 1, 0x80000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 1);
  ck_assert_uint_eq(num3.bits[3], 0x80000000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_20) {
  my_decimal num1 = {{1, 1, 0, 0x80000000}};
  my_decimal num2 = {{1, 1, 1, 0x80000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 1, 0x00000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 1);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 0);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_21) {
  my_decimal num1 = {{1, 1, 1, 0x801E0000}};
  my_decimal num2 = {{1, 1, 0, 0x80000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 1);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_22) {
  my_decimal num1 = {{1, 1, 0, 0x80000000}};
  my_decimal num2 = {{1, 1, 1, 0x801E0000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 1);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_23) {
  my_decimal num1 = {{1, 1, 1, 0x80000011}};
  my_decimal num2 = {{1, 1, 0, 0x80000000}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 1);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST
START_TEST(decimal_test_sub_24) {
  my_decimal num1 = {{1, 1, 0, 0x80000000}};
  my_decimal num2 = {{1, 1, 1, 0x80000011}};
  my_decimal num3 = {{0}};
  my_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error = my_sub(num1, num2, &num3);
  ck_assert_uint_eq(num3.bits[0], 0);
  ck_assert_uint_eq(num3.bits[1], 0);
  ck_assert_uint_eq(num3.bits[2], 0);
  ck_assert_uint_eq(num3.bits[3], 0x00000000);
  ck_assert_int_eq(error, 1);
  ck_assert_msg(my_is_equal(num3, test_num) == 1, "my_is_equal failed");
}
END_TEST

Suite *suite_decimal_sub() {
  Suite *suite = suite_create("suite_decimal_sub");
  TCase *tcase = tcase_create("tcase_decimal_sub");

  tcase_add_test(tcase, decimal_test_sub_1);
  tcase_add_test(tcase, decimal_test_sub_2);
  tcase_add_test(tcase, decimal_test_sub_3);
  tcase_add_test(tcase, decimal_test_sub_4);
  tcase_add_test(tcase, decimal_test_sub_5);
  tcase_add_test(tcase, decimal_test_sub_6);
  tcase_add_test(tcase, decimal_test_sub_7);
  tcase_add_test(tcase, decimal_test_sub_8);
  tcase_add_test(tcase, decimal_test_sub_9);
  tcase_add_test(tcase, decimal_test_sub_10);
  tcase_add_test(tcase, decimal_test_sub_11);
  tcase_add_test(tcase, decimal_test_sub_12);
  tcase_add_test(tcase, decimal_test_sub_13);
  tcase_add_test(tcase, decimal_test_sub_14);
  tcase_add_test(tcase, decimal_test_sub_15);
  tcase_add_test(tcase, decimal_test_sub_16);
  tcase_add_test(tcase, decimal_test_sub_17);
  tcase_add_test(tcase, decimal_test_sub_18);
  tcase_add_test(tcase, decimal_test_sub_19);
  tcase_add_test(tcase, decimal_test_sub_20);
  tcase_add_test(tcase, decimal_test_sub_21);
  tcase_add_test(tcase, decimal_test_sub_22);
  tcase_add_test(tcase, decimal_test_sub_23);
  tcase_add_test(tcase, decimal_test_sub_24);

  suite_add_tcase(suite, tcase);
  return suite;
}