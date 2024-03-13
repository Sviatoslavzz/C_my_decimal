#include "test.h"

START_TEST(test_1) {
  my_decimal res = {{0, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_2) {
  my_decimal res = {{0, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = -0.0;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_3) {
  my_decimal res = {{1, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 1;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_4) {
  my_decimal res = {{1, 0, 0, 0x80000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = -1;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_5) {
  my_decimal res = {{199999, 0, 0, 0x00050000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 1.99999;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_6) {
  my_decimal res = {{199999, 0, 0, 0x80050000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = -1.99999;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_7) {
  my_decimal res = {{2, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 1.9999999;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_8) {
  my_decimal res = {{123456, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 123456.0;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_9) {
  my_decimal res = {{1234561, 0, 0, 0x00010000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 123456.1234;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_10) {
  my_decimal res = {{1234562, 0, 0, 0x00010000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 123456.1534;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_11) {
  my_decimal res = {{1234562, 0, 0, 0x80010000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = -123456.1534;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_12) {
  my_decimal res = {{123456800, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 123456789;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_13) {
  my_decimal res = {{123456800, 0, 0, 0x80000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = -123456789;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_14) {
  my_decimal res = {{0b01010100000010111110010000000000,
                     0b00000000000000000000000000000010, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};
  float f = 9999999999;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_15) {
  my_decimal res = {{0b00100000000000000000000000000000,
                     0b10110011100100101011001000011010,
                     0b11111111111111111111111101110111, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = MY_MAX_FLOAT;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_16) {
  my_decimal res = {{0, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = MY_MAX_FLOAT * 2;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 1, "func return value failed");
}
END_TEST

START_TEST(test_17) {
  my_decimal res = {{1, 0, 0, 0x00010000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.1;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_18) {
  my_decimal res = {{1, 0, 0, 0x00020000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.01;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_19) {
  my_decimal res = {{1, 0, 0, 0x00030000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.001;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_20) {
  my_decimal res = {{1, 0, 0, 0x00040000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.0001;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_21) {
  my_decimal res = {{1, 0, 0, 0x00050000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.00001;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_22) {
  my_decimal res = {{1, 0, 0, 0x00060000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.000001;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_23) {
  my_decimal res = {{1, 0, 0, 0x00070000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.0000001;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_24) {
  my_decimal res = {{1, 0, 0, 0x00090000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.000000001;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_25) {
  my_decimal res = {{1, 0, 0, 0x80090000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = -0.000000001;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_26) {
  my_decimal res = {{19, 0, 0, 0x001C0000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.0000000000000000000000000019;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_27) {
  my_decimal res = {{11, 0, 0, 0x801C0000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = -0.0000000000000000000000000011;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_28) {
  my_decimal res = {{123, 0, 0, 0x00030000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.123;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_29) {
  my_decimal res = {{1234567, 0, 0, 0x00070000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.1234567;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_30) {
  my_decimal res = {{1234568, 0, 0, 0x00070000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.12345678;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_31) {
  my_decimal res = {{1234568, 0, 0, 0x80070000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = -0.12345678;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_32) {
  my_decimal res = {{1234568, 0, 0, 0x80070000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = -0.12345678;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_33) {
  my_decimal res = {{1234568, 0, 0, 0x80090000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = -0.0012345678;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_34) {
  my_decimal res = {{1234568, 0, 0, 0x00090000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.0012345678;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_35) {
  my_decimal res = {{2, 0, 0, 0x001C0000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.00000000000000000000000000015;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_36) {
  my_decimal res = {{1, 0, 0, 0x001C0000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.0000000000000000000000000001234567;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_37) {
  my_decimal res = {{500001, 0, 0, 0x00080000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.00500001;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_38) {
  my_decimal res = {{0, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.00000000000000000000000000005;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 1, "func return value failed");
}
END_TEST

START_TEST(test_39) {
  my_decimal res = {{0, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = NAN;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 1, "func return value failed");
}
END_TEST

START_TEST(test_40) {
  my_decimal res = {{0, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = INFINITY;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 1, "func return value failed");
}
END_TEST

START_TEST(test_41) {
  my_decimal res = {{5000016, 0, 0, 0x00090000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 0.0050000159;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

START_TEST(test_42) {
  my_decimal res = {{10, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 9.9999999;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST
START_TEST(test_43) {
  my_decimal res = {{0, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};
  float f = 199999999999999999999999999900.0;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 1, "func return value failed");
}
END_TEST
START_TEST(test_44) {
  my_decimal res = {{0, 0, 0, 0x00000000}};
  my_decimal dst = {{0, 0, 0, 0x00000000}};

  float f = 9.999999999999999999999999999999;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 0, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST
START_TEST(test_45) {
  my_decimal res = {{12, 0, 0, 0x00000000}};
  my_decimal dst;
  float f = 12.0;
  int error = my_from_float_to_decimal(f, &dst);
  ck_assert_msg(my_is_equal(res, dst) == 1, "float written incorrectly");
  ck_assert_msg(error == 0, "func return value failed");
}
END_TEST

Suite *suite_float_to_decimal() {
  Suite *suite = suite_create("suite_float_to_decimal");
  TCase *tcase = tcase_create("tcase_float_to_decimal");

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
  tcase_add_test(tcase, test_36);
  tcase_add_test(tcase, test_37);
  tcase_add_test(tcase, test_38);
  tcase_add_test(tcase, test_39);
  tcase_add_test(tcase, test_40);
  tcase_add_test(tcase, test_41);
  tcase_add_test(tcase, test_42);
  tcase_add_test(tcase, test_43);
  tcase_add_test(tcase, test_44);
  tcase_add_test(tcase, test_45);

  suite_add_tcase(suite, tcase);

  return suite;
}