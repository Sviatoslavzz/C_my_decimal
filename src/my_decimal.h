#ifndef MY_DECIMAL_H
#define MY_DECIMAL_H
#include <math.h>
#include <stdio.h>

#define MY_MAX_FLOAT 79228162514264337593543950335.0f

typedef struct {
  unsigned int bits[4];
} my_decimal;

typedef struct {
  unsigned int bits[8];
} my_big_decimal;

typedef union {
  float fl;
  unsigned int integ;
} my_float_bits;

void my_set_bit(my_decimal *, int, int);
int my_get_bit(my_decimal, int);
int my_get_scale(my_decimal);
void my_set_scale(my_decimal *, int);
int my_get_sign(my_decimal);
void my_set_sign(my_decimal *, int);
void my_left_shift(my_decimal *, int);
void my_right_shift(my_decimal *, int);
void my_sum(my_decimal, my_decimal, my_decimal *);
void my_normalization(my_decimal *, my_decimal *);
void my_multi_ten(my_decimal *);
void my_decimal_add_one(my_decimal *);
void my_get_remainder(const my_decimal *, my_decimal *, my_decimal *);

void my_big_set_bit(my_big_decimal *, int, int);
int my_big_get_bit(my_big_decimal, int);
void my_big_left_shift(my_big_decimal *, int);
void num_to_big_decimal(my_big_decimal *, my_decimal);
void big_decimal_to_num(my_big_decimal, my_decimal *);
void my_big_sum(my_big_decimal, my_big_decimal, my_big_decimal *);
void my_big_sub(my_big_decimal, my_big_decimal, my_big_decimal *);
void my_big_multi_ten(my_big_decimal *);
void my_big_normalization(my_big_decimal *, my_big_decimal *, int, int);
int my_abs(int);

int my_add(my_decimal, my_decimal, my_decimal *);
int my_sub(my_decimal, my_decimal, my_decimal *);
int my_mul(my_decimal, my_decimal, my_decimal *);
int my_div(my_decimal, my_decimal, my_decimal *);
int my_div_ten(my_decimal, my_decimal *);

int my_from_int_to_decimal(int, my_decimal *);
int my_from_decimal_to_int(my_decimal, int *);
int my_from_float_to_decimal(float, my_decimal *);
int my_from_decimal_to_float(my_decimal, float *);
void write_decimal(char *, const char *, int *, my_decimal *);
void align_float(const int *, float *, int *);
void set_dec_to_zero(my_decimal *);
void check_sign(float *, my_decimal *);

int my_floor(my_decimal, my_decimal *);
int my_round(my_decimal, my_decimal *);
int my_truncate(my_decimal, my_decimal *);
int my_negate(my_decimal, my_decimal *);

int my_is_less(my_decimal, my_decimal);
int my_big_is_less(my_big_decimal *, my_big_decimal *, int);
int my_is_less_or_equal(my_decimal, my_decimal);
int my_big_is_less_or_equal(my_big_decimal *, my_big_decimal *, int);
int my_is_equal(my_decimal, my_decimal);
int my_big_is_equal(my_big_decimal *, my_big_decimal *);
int my_is_not_equal(my_decimal, my_decimal);
int my_big_is_not_equal(my_big_decimal *, my_big_decimal *);
int my_is_greater(my_decimal, my_decimal);
int my_big_is_greater(my_big_decimal *, my_big_decimal *, int);
int my_is_greater_or_equal(my_decimal, my_decimal);
int my_big_is_greater_or_equal(my_big_decimal *, my_big_decimal *, int);
int my_big_overflow(my_big_decimal *, my_decimal *);
int my_big_div_ten(my_big_decimal, my_big_decimal *);
void set_big_dec_to_zero(my_big_decimal *);
int big_simple_overflow(const my_big_decimal *);
void my_big_add_one(my_big_decimal *, int *);
void my_big_get_remainder(const my_big_decimal *, my_big_decimal *,
                          my_big_decimal *);

int my_decimal_not_empty(my_decimal *);
int my_big_decimal_not_empty(my_big_decimal *);
int is_last_bits_clear(const my_decimal *);

#endif