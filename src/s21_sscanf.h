#ifndef S21_SSCANF_H
#define S21_SSCANF_H
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct flags {
  int integer;
  int string;
  int decimal_octal_hex;
  int move_format;
  int e;
  int p;
  int octal;
  int o;
  int is_unsigned;
  int is_ptr;
  int c;
  int n;
  int x;
  int format_received;

} flags;

typedef struct flagscanf {
  flags base;
  int fspace, fminus, fplus, fsharp, fzero;
  int failed;
  // flags* name; если сделать так, то создастся ли структура name или только
  // указатель на несуществующую структуру
  // char* regular;
  int l, ll, h, L;
  int width;
  int asterisk;
  const char* start_of_str;

} flagscanf;
typedef struct {
  int is_int;
  int is_hex;
  int is_octal;
  int is_scientific;
} number_type;

int s21_sscanf(const char* source, const char* format, ...);
flagscanf scanfparser_flags(const char** format);
void scanfparser_spec(const char** format, flagscanf* Flags);
void scanf_concat_type(flagscanf* Flags, va_list arg, const char** source);
flags parser(const char** format, flags Flags);
void scanf_write_int(flagscanf* Flags, const char** source,
                     long long int* result, va_list arg);
void scanf_write_string(flagscanf* Flags, va_list arg, const char** source);
void scanf_write_decimal_octal_hex(const char** source, flagscanf*,
                                   long long int* result, va_list arg);
void data_type_for_i(long long int* result, va_list, flagscanf* Flags);
int is_int_f(char c);
int dec_convert(int input, int base);
long double scientific_to_float(char* string);
long double char_to_dec(int* i, char str[]);
long double exponent_f(char exp[], long double pre_plus_post);
void sscanf_write_e(va_list arg, const char** source, flagscanf*);
long long int hex_to_dex(char str[], int base, int minus, const char**);
int convert_to_dec(int input, int base, int minus);
void sscanf_write_o(va_list arg, const char** source, flagscanf* Flags);
long double a_to_float(char* string);
long int set_sign(char** str);
void set_params(flagscanf* Flags, const char** format);
void width_function(const char** format, int* width);
unsigned long long s21_pow(int base, int exp);
int width_check(flagscanf Flags);
int hex_check(const char** str);
int complex_while_check(const char** source);
void sscanf_write_c(const char** str, va_list arg, flagscanf* Flags);
#endif