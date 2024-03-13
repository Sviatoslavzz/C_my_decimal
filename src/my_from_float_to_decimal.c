#include "my_decimal.h"

/*Converts float to decimal*/
int my_from_float_to_decimal(float src, my_decimal* dst) {
  int error_code = 0;
  if (dst == NULL || isinf(src) || isnan(src) || src > MY_MAX_FLOAT) {
    error_code = 1;
  } else if (src != 0) {
    set_dec_to_zero(dst);
    check_sign(&src, dst);
    int degree = (int)floorf(log10f(fabsf(src))) + 1;
    if (degree > 29 || degree < -27) {
      error_code = 1;
    } else {
      int scale = 0;
      align_float(&degree, &src, &scale);
      float left = 0, right = 0;
      if (degree <= -27)
        left = src;
      else
        right = modff(src, &left);
      char l_str[50] = {'\0'}, r_str[10] = {'\0'};
      sprintf(l_str, "%.0f", left);
      int written_to_dec = 0;
      if (degree < 7 && degree > 0 && right != 0) {
        sprintf(r_str, "%.*f", 7 - degree, right);
        char* p_r_str = r_str;
        while (*(p_r_str + 1) != '\0') p_r_str++;
        while (*p_r_str == '0') p_r_str--;
        scale = p_r_str - r_str - 1;
        write_decimal(p_r_str, r_str, &written_to_dec, dst);
      }
      char* p_l_str = l_str;
      while (*(p_l_str + 1) != '\0') p_l_str++;
      if (degree <= 0) {
        while (*p_l_str == '0') {
          p_l_str--;
          scale--;
        }
      }
      write_decimal(p_l_str, l_str, &written_to_dec, dst);
      if (scale < 0) {
        scale *= -1;
        while (scale) {
          my_multi_ten(dst);
          scale--;
        }
      } else
        my_set_scale(dst, scale);
    }
  }
  return error_code;
}

/*Writes number from string to decimal*/
void write_decimal(char* pointer, const char* string, int* written_to_dec,
                   my_decimal* dst) {
  while (*pointer != '.' && pointer - string != -1) {
    my_decimal tmp = {0};
    my_from_int_to_decimal(*pointer - '0', &tmp);
    for (int i = 0; i < *written_to_dec; i++) {
      my_multi_ten(&tmp);
    }
    my_sum(*dst, tmp, dst);
    *written_to_dec += 1;
    pointer--;
  }
}

/*Aligns float number to 7 significant decimal digits*/
void align_float(const int* degree, float* src, int* scale) {
  if (*degree > 7) {
    int n = *degree - 7;  // 9 - 7 = 2
    *scale = -n;
    while (n) {
      *src /= 10;
      if (n == 1 && floorf(fmodf(*src, 10.0)) >= 5 && *degree < 29) {
        *src += 1;
      }
      n--;
    }
  } else if (*degree <= 0) {
    int n = *degree < -21 ? 28 : -1 * (*degree - 7);
    *scale = n;
    char tmp_str[40] = {'\0'};
    sprintf(tmp_str, "%.*f", n + 1, *src);
    for (int i = 0; i < n; i++) {
      *src *= 10;
    };
    if (*degree > -27) {
      if (floorf(fmodf(*src * 10, 10.0)) >= 5) *src += 1;
    } else {
      char* p_tmp_str = tmp_str;
      while (*(p_tmp_str + 1) != '\0') p_tmp_str++;
      if ((int)(*p_tmp_str - '0') >= 5) *src += 1;
    }
  } else {
    char float_str[100] = {'\0'};
    sprintf(float_str, "%.*f", (7 - *degree), *src);
    sscanf(float_str, "%f", src);
  }
}

/*Checks sign from float and sets to decimal*/
void check_sign(float* src, my_decimal* dst) {
  int sign = *src < 0 ? 1 : 0;
  if (sign) {
    *src = *src * -1;
    my_set_sign(dst, sign);
  }
}