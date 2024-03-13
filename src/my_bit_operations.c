#include "my_decimal.h"

/*Write bit to decimal by specified position*/
void my_set_bit(my_decimal *decimal, int position, int bit) {
  int mask = 1 << (position % 32);
  if (bit)
    decimal->bits[position / 32] |= mask;
  else
    decimal->bits[position / 32] &= ~mask;
}

/*Get bit from decimal by specified position*/
int my_get_bit(my_decimal decimal, int position) {
  int mask = 1 << (position % 32);
  return !!(decimal.bits[position / 32] & mask);
}

/*Get decimal scale*/
int my_get_scale(my_decimal decimal) {
  return (decimal.bits[3] & 0x00FF0000) >> 16;
}

/*Set decimal scale*/
void my_set_scale(my_decimal *decimal, int scale) {
  decimal->bits[3] = ((decimal->bits[3] & 0x80000000) | (scale << 16));
}

/*Get decimal sign*/
int my_get_sign(my_decimal decimal) { return my_get_bit(decimal, 127); }

/*Set decimal scale*/
void my_set_sign(my_decimal *decimal, int bit) {
  my_set_bit(decimal, 127, bit);
}

/*Binary left shift of decimal, shifts from 1 to 30*/
void my_left_shift(my_decimal *decimal, int shift) {
  unsigned int tmp = 0;
  for (int i = 0; i < 3; i++) {
    unsigned temp = decimal->bits[i];
    decimal->bits[i] <<= shift;
    decimal->bits[i] |= tmp;
    tmp = temp >> (32 - shift);
  }
}

/*Binary addition of two decimals, not taking sign and scale*/
void my_sum(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int tmp = 0;
  for (int i = 0; i < 96; i++) {
    int bits = my_get_bit(value_1, i) + my_get_bit(value_2, i) + tmp;
    my_set_bit(result, i, bits % 2);
    tmp = bits / 2;
  }
}

/*Multiplication decimal by 10*/
void my_multi_ten(my_decimal *value) {
  my_decimal num = *value;
  my_left_shift(&num, 3);
  my_left_shift(value, 1);
  my_sum(num, *value, value);
}

/*If decimal is not empty returns 1, else 0*/
int my_decimal_not_empty(my_decimal *value) {
  return !!value->bits[0] + !!value->bits[1] + !!value->bits[2];
}

/*Check if the last bit of decimal is clean in 96-111 and 120-126 bits */
int is_last_bits_clear(const my_decimal *value) {
  int count = 0;
  for (int i = 96; i < 112; i++) count += my_get_bit(*value, i);
  for (int i = 120; i < 127; i++) count += my_get_bit(*value, i);
  return count == 0 ? 1 : 0;
}

/*Set decimal to zero*/
void set_dec_to_zero(my_decimal *dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }
}

/*Division decimal by 10*/
int my_div_ten(my_decimal value_1, my_decimal *result) {
  my_decimal result_res = *result;
  my_big_decimal big_1 = {0}, big_2 = {{10, 0, 0, 0, 0, 0, 0, 0}}, big_3 = {0};
  num_to_big_decimal(&big_1, value_1);
  set_dec_to_zero(&result_res);
  while (my_big_is_greater_or_equal(&big_1, &big_2, 0)) {
    my_big_decimal big_4 = big_2;
    int tmp = 0;
    my_big_decimal num_3 = {{1, 0, 0, 0, 0, 0, 0, 0}};
    while (my_big_is_greater_or_equal(&big_1, &big_4, 0)) {
      my_big_left_shift(&big_4, 1);
      tmp++;
    }
    big_4 = big_2;
    for (int i = 0; i < tmp - 1; i++) {
      my_big_left_shift(&big_4, 1);
      my_big_left_shift(&num_3, 1);
    }
    my_big_sub(big_1, big_4, &big_1);
    my_big_sum(big_3, num_3, &big_3);
  }
  big_decimal_to_num(big_3, result);
  return 0;
}

/*Adds 1 to decimal number*/
void my_decimal_add_one(my_decimal *src) {
  my_decimal one = {{1, 0, 0, 0}};
  my_add(*src, one, src);
}

/*Gets remainder from decimal res*/
void my_get_remainder(const my_decimal *res, my_decimal *tmp,
                      my_decimal *dec_remainder) {
  my_div_ten(*res, tmp);
  my_decimal tmp2 = *tmp;
  my_multi_ten(&tmp2);
  my_sub(*res, tmp2, dec_remainder);
}