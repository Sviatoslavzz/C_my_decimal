#include "test.h"

START_TEST(test_1) {
  int num1 = 10;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{10, 0, 0, 0x00000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_2) {
  int num1 = -10;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{10, 0, 0, 0x80000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_3) {
  int num1 = 0;
  my_decimal num2 = {{0, 0, 0, 0x00000000}};
  my_decimal test_num = {{0, 0, 0, 0x00000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_4) {
  int num1 = 2147483647;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0b1111111111111111111111111111111, 0, 0, 0x00000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_5) {
  int num1 = -2147483647;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0b1111111111111111111111111111111, 0, 0, 0x80000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_6) {
  int num1 = -0;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{0, 0, 0, 0x80000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_7) {
  int num1 = 10000;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{10000, 0, 0, 0x00000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_8) {
  int num1 = -10000;
  my_decimal num2 = {{0, 0, 0, 0x80000000}};
  my_decimal test_num = {{10000, 0, 0, 0x80000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_9) {
  int num1 = 123456789;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{123456789, 0, 0, 0x00000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_10) {
  int num1 = -1999999;
  my_decimal num2 = {{0, 0, 0, 0x80000000}};
  my_decimal test_num = {{1999999, 0, 0, 0x80000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_11) {
  int num1 = 111111111;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{111111111, 0, 0, 0x00000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_12) {
  int num1 = -111111111;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{111111111, 0, 0, 0x80000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_13) {
  int num1 = 100500;
  my_decimal num2 = {{0, 0, 0, 0x00000000}};
  my_decimal test_num = {{100500, 0, 0, 0x00000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_14) {
  int num1 = 1;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{1, 0, 0, 0x00000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_15) {
  int num1 = -1;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{1, 0, 0, 0x80000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_16) {
  int num1 = -800;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{800, 0, 0, 0x80000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_17) {
  int num1 = 10101;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{10101, 0, 0, 0x00000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_18) {
  int num1 = -10001;
  my_decimal num2 = {{0, 0, 0, 0x80000000}};
  my_decimal test_num = {{10001, 0, 0, 0x80000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_19) {
  int num1 = 2586461;
  my_decimal num2 = {{0, 0, 0, 0}};
  my_decimal test_num = {{2586461, 0, 0, 0x00000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_20) {
  int num1 = -70000;
  my_decimal num2 = {{0, 0, 0, 0x00000000}};
  my_decimal test_num = {{70000, 0, 0, 0x80000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST

START_TEST(test_21) {
  float num1 = -51124128412497.0;
  my_decimal num2 = {{0, 0, 0, 0x00000000}};
  my_decimal test_num = {{2147483648, 0, 0, 0x80000000}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1,
                "decimal written incorrectly");
  ck_assert_int_eq(error_code, 0);
}
END_TEST

START_TEST(test_22) {
  int num1 = INT32_MAX;
  my_decimal num2 = {{0, 0, 0, 0x00000000}};
  my_decimal test_num = {{2147483647, 0, 0, 0}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST
START_TEST(test_23) {
  int num1 = 123;
  int error_code = my_from_int_to_decimal(num1, NULL);
  ck_assert_int_eq(error_code, 1);
}
END_TEST
START_TEST(test_24) {
  int num1 = 12;
  my_decimal num2;
  my_decimal test_num = {{12, 0, 0, 0}};
  int error_code = my_from_int_to_decimal(num1, &num2);
  ck_assert_msg(my_is_equal(num2, test_num) == 1, "my_is_equal failed");
  ck_assert_int_eq(error_code, 0);
}
END_TEST

Suite *suite_from_int_to_decimal() {
  Suite *suite = suite_create("suite_from_int_to_decimal");
  TCase *tcase = tcase_create("tcase_from_int_to_decimal");

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

  suite_add_tcase(suite, tcase);
  return suite;
}