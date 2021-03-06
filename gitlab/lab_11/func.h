#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

#define N 15
#define MAX_BUF_LEN 100
#define K -199
#define OK 0
#define FAIL 1

char *print(char *format_buffer, size_t *size, const char cur_sym, int *global_counter);
char *get_alphabet(char sym);
void get_hex_num(int tmp, int size, char *hexDigits, char result[size]);
void get_hex_num_unsigned(unsigned int tmp, int size, const char *hexDigits, char result[size]);
int check_for_zero(int size_mas, char result[size_mas], char **format_buffer, size_t *size, int *global_counter);
char *print_short_hex(char *format_buffer, size_t *size, const unsigned short toconvert, int *global_counter, char sym);
char *print_full_hex(char *format_buffer, size_t *size, const unsigned int toconvert, int *global_counter, char sym);
int digit_len(int num);
char get_n_char(int num, int k);
char *print_int(char *format_buffer, size_t *size, const int toprint, int *global_counter);
char *print_char_sym(char *format_buffer, size_t *size, const int toprint, int *global_counter);
size_t my_vsnprintf(char *buffer, size_t buff_size, const char *format, va_list ap);
int my_snprintf(char *buffer, size_t size, const char *format, ...);

#endif
