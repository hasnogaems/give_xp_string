#include "s21_string.h"
#include <stdio.h>
#include <math.h>

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *line = S21_NULL;
  for (int i = 0; i < (int)n; i++) {
    if (((char *)str)[i] == c) {
      line = ((char *)str) + i;
      break;
    }
  }
  return line;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int cmp = 0;
  for (int i = 0; i < (int)n; i++) {
    if (((char *)str1)[i] != ((char *)str2)[i]) {
      cmp = ((char *)str1)[i] - ((char *)str2)[i];
      break;
    }
  }
  return cmp;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (int i = 0; i < (int)n; i++) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  for (int i = 0; i < (int)n; i++) {
    ((char *)str)[i] = c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_len = s21_strlen(dest);
  for (int i = 0; i < (int)n && src[i] != '\0'; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[s21_strlen(dest)] = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *line = S21_NULL;
  for (int i = 0; i <= (int)s21_strlen(str); i++) {
    if (str[i] == c) {
      line = (char *)&str[i];
      break;
    }
  }
  return line;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int cmp = 0;
  for (int i = 0; i < (int)n; i++) {
    if (str1[i] != str2[i]) {
      cmp = str1[i] - str2[i];
      break;
    }
  }
  return cmp;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  for (; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }

  for (; i < n; i++) {
    dest[i] = '\0';
  }

  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;

  for (int i = 0; i < (int)s21_strlen(str1); i++) {
    int check = 0;
    for (int j = 0; j < (int)s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        check = 1;
        break;
      }
    }
    if (!check) {
      len++;
    } else {
      break;
    }
  }
  return len;
}

char *s21_strerror(int errnum) {
  errors list = {{S21EPERM_STR,
                  S21ENOENT_STR,
                  S21ESRCH_STR,
                  S21EINTR_STR,
                  S21EIO_STR,
                  S21ENXIO_STR,
                  S21E2BIG_STR,
                  S21ENOEXEC_STR,
                  S21EBADF_STR,
                  S21ECHILD_STR,
                  S21EDEADLK_STR,
                  S21ENOMEM_STR,
                  S21EACCES_STR,
                  S21EFAULT_STR,
                  S21ENOTBLK_STR,
                  S21EBUSY_STR,
                  S21EEXIST_STR,
                  S21EXDEV_STR,
                  S21ENODEV_STR,
                  S21ENOTDIR_STR,
                  S21EISDIR_STR,
                  S21EINVAL_STR,
                  S21ENFILE_STR,
                  S21EMFILE_STR,
                  S21ENOTTY_STR,
                  S21ETXTBSY_STR,
                  S21EFBIG_STR,
                  S21ENOSPC_STR,
                  S21ESPIPE_STR,
                  S21EROFS_STR,
                  S21EMLINK_STR,
                  S21EPIPE_STR,
                  S21EDOM_STR,
                  S21ERANGE_STR,
                  S21EAGAIN_STR,
                  S21EINPROGRESS_STR,
                  S21EALREADY_STR,
                  S21ENOTSOCK_STR,
                  S21EDESTADDRREQ_STR,
                  S21EMSGSIZE_STR,
                  S21EPROTOTYPE_STR,
                  S21ENOPROTOOPT_STR,
                  S21EPROTONOSUPPORT_STR,
                  S21ESOCKTNOSUPPORT_STR,
                  S21ENOTSUP_STR,
                  S21EPFNOSUPPORT_STR,
                  S21EAFNOSUPPORT_STR,
                  S21EADDRINUSE_STR,
                  S21EADDRNOTAVAIL_STR,
                  S21ENETDOWN_STR,
                  S21ENETUNREACH_STR,
                  S21ENETRESET_STR,
                  S21ECONNABORTED_STR,
                  S21ECONNRESET_STR,
                  S21ENOBUFS_STR,
                  S21EISCONN_STR,
                  S21ENOTCONN_STR,
                  S21ESHUTDOWN_STR,
                  S21ETOOMANYREFS_STR,
                  S21ETIMEDOUT_STR,
                  S21ECONNREFUSED_STR,
                  S21ELOOP_STR,
                  S21ENAMETOOLONG_STR,
                  S21EHOSTDOWN_STR,
                  S21ENOROUTE_STR,
                  S21ENOTEMPTY_STR,
                  S21EPROCLIM_STR,
                  S21EUSERS_STR,
                  S21EDQUOT_STR,
                  S21ESTALE_STR,
                  S21EREMOTE_STR,
                  S21EBADRPC_STR,
                  S21ERPCMISMATCH_STR,
                  S21EPROGUNAVAIL_STR,
                  S21EPROGMISMATCH_STR,
                  S21EPROCUNAVAIL_STR,
                  S21ENOLCK_STR,
                  S21ENOSYS_STR,
                  S21EFTYPE_STR,
                  S21EAUTH_STR,
                  S21ENEEDAUTH_STR,
                  S21EPWROFF_STR,
                  S21EDEVERR_STR,
                  S21EOVERFLOW_STR,
                  S21EBADEXEC_STR,
                  S21EBADARCH_STR,
                  S21ESHLIBVERS_STR,
                  S21EBADMACHO_STR,
                  S21ECANCELED_STR,
                  S21EIDRM_STR,
                  S21ENOMSG_STR,
                  S21EILSEQ_STR,
                  S21ENOATTR_STR,
                  S21EBADMSG_STR,
                  S21EMULTIHOP_STR,
                  S21ENODATA_STR,
                  S21ENOLINK_STR,
                  S21ENOSR_STR,
                  S21ENOSTR_STR,
                  S21EPROTO_STR,
                  S21ETIME_STR,
                  S21EOPNOTSUPP_STR,
                  S21ENOPOLICY_STR,
                  S21ENOTRECOVERABLE_STR,
                  S21EOWNERDEAD_STR,
                  S21EQFULL_STR}};
  static char str[100];
  if (errnum == 0) {
    s21_sprintf(str, "Undefined error: %d", errnum);
  } else if (errnum >= 1 && errnum <= ERRORS_COUNT) {
    s21_sprintf(str, "%s", list.stringErrors[errnum - 1]);
  } else {
    s21_sprintf(str, "Unknown error: %d", errnum);
  }
  return str;
}

s21_size_t s21_strlen(const char *str) {
  const char *ptr = str;
  while (*ptr != '\0') {
    ptr++;
  }
  return (s21_size_t)(ptr - str);
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *line = S21_NULL;
  for (int i = 0; i < (int)s21_strlen(str1); i++) {
    for (int j = 0; j < (int)s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        line = (char *)&str1[i];
        break;
      }
    }
    if (line == (char *)&str1[i]) {
      break;
    }
  }
  return line;
}

char *s21_strrchr(const char *str, int c) {
  char *line = S21_NULL;
  for (int i = 0; i <= (int)s21_strlen(str); i++) {
    if (str[i] == c) {
      line = (char *)&str[i];
    }
  }
  return line;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;

  if (needle[0] == '\0') {
    result = (char *)haystack;
  } else {
    int i = 0, j = 0;
    for (; haystack[i] != '\0'; i++) {
      if (haystack[i] == needle[j]) {
        int index = i;
        while (haystack[i] == needle[j] && needle[j] != '\0') {
          i++;
          j++;
        }
        if (needle[j] == '\0') {
          result = (char *)&haystack[index];
          break;
        } else {
          i = index + 1;
          j = 0;
        }
      }
    }
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *current_position = S21_NULL;
  int flag = 1;
  char *start_position = S21_NULL;

  if (!(str == S21_NULL)) {
    current_position = str;
  } else if (current_position == S21_NULL || *current_position == '\0') {
    start_position = S21_NULL;
    flag = 0;
  }

  if (flag) {
    int check = 1;
    while (current_position != S21_NULL && *current_position != '\0') {
      int isDelim = 0;
      for (int j = 0; delim[j] != '\0'; j++) {
        if (*current_position == delim[j]) {
          isDelim = 1;
          break;
        }
      }
      if (!isDelim) {
        start_position = current_position;
        break;
      }
      current_position++;
    }

    while (current_position != S21_NULL && *current_position != '\0' && check) {
      for (int j = 0; delim[j] != '\0'; j++) {
        if (*current_position == delim[j]) {
          *current_position = '\0';
          check = 0;
          break;
        }
      }
      current_position++;
    }
  }

  return start_position;
}

void reset_flags(flag_t *flags) {
  flags->plus = 0;
  flags->minus = 0;
  flags->space = 0;
  flags->is_short = 0;
  flags->is_long = 0;
  flags->precision = -1;
  flags->width = 0;
}

char *print_char(char *str, flag_t *flags, char type, va_list *input) {
  if (flags->minus == 0) {
    for (int i = 0; i < flags->width - 1; i++) {
      *str = ' ';
      str++;
    }
  }

  if (type == '%') {
    *str = '%';
  } else {
    *str = (char)va_arg(*input, int);
  }

  if (flags->minus == 1) {
    str++;
    for (int i = 0; i < flags->width - 1; i++) {
      *str = ' ';
      str++;
    }
    str--;
  }
  return str;
}

char *print_string(char *str, flag_t *flags, va_list *input) {
  char *symbol = va_arg(*input, char *);
  if (symbol == NULL) {
    char *null_message = "(null)";
    symbol = null_message;
  }
  int width_difference = 0;
  if ((unsigned long long)flags->precision < s21_strlen(symbol)) {
    width_difference = flags->width - flags->precision;
  } else {
    width_difference = flags->width - s21_strlen(symbol);
  }
  if (flags->minus == 0) {
    for (int i = 0; i < width_difference; i++) {
      *str = ' ';
      str++;
    }
  }
  for (unsigned int i = 0;
       (i < (unsigned)flags->precision) && (symbol[i] != '\0'); i++) {
    *str = symbol[i];
    str++;
  }
  if (flags->minus == 1) {
    for (int i = 0; i < width_difference; i++) {
      *str = ' ';
      str++;
    }
  }
  str--;
  return str;
}

char *print_number(char *str, flag_t *flags, char type, va_list *input) {
  char buffer[256];

  if (type == 'f') {
    s21_ftos(buffer, va_arg(*input, double), flags);
  } else if (type == 'u') {
    unsigned long input_data;
    if (flags->is_long == 1)
      input_data = (unsigned long)va_arg(*input, unsigned long);
    else if (flags->is_short == 1)
      input_data = (unsigned short)va_arg(*input, int);
    else
      input_data = (unsigned int)va_arg(*input, unsigned int);
    s21_uitos(buffer, input_data, flags);
  } else {
    long long int input_data;
    if (flags->is_long == 1)
      input_data = (long long)va_arg(*input, long);
    else if (flags->is_short == 1)
      input_data = (short)va_arg(*input, int);
    else
      input_data = (int)va_arg(*input, int);
    s21_itos(buffer, input_data, flags);
  }

  for (int i = 0; buffer[i] != '\0'; i++) {
    *str = buffer[i];
    str++;
  }

  str--;
  return str;
}

unsigned long long s21_pow(int base, int exp) {
  unsigned long long result = 1;
  for (int i = 0; i < exp; i++) {
    result *= base;
  }
  return result;
}

void s21_itos(char *str, long long int num, flag_t *flags) {
  if (flags->precision == -1) {
    flags->precision = 1;
  }

  if ((flags->precision != 0) || (num != 0)) {
    int sign = 0;
    if (num < 0) {
      sign = -1;
      flags->width--;
    } else if (flags->plus == 1) {
      sign = 1;
      flags->width--;
    } else if (flags->space == 1) {
      *str = ' ';
      str++;
      flags->width--;
    }

    int num_of_digits = 0;
    long long int complete_part = num;

    while (complete_part != 0) {
      num_of_digits++;
      complete_part = complete_part / 10;
    }
    complete_part = num;

    if (num_of_digits < flags->precision) {
      num_of_digits = flags->precision;
    }
    int width_difference = flags->width - num_of_digits;

    if (flags->minus == 0) {
      if (width_difference > 0) {
        for (int i = 0; i < width_difference; i++) {
          *str = ' ';
          str++;
        }
      }
    }

    if (sign < 0) {
      *str = '-';
      str++;
    } else if (sign > 0) {
      *str = '+';
      str++;
    }

    do {
      long long int c = s21_pow(10, num_of_digits - 1);
      long long int b = complete_part / c;
      complete_part = complete_part % c;
      if (b < 0) {
        b = -b;
      }
      *str = '0' + b;
      str++;
      num_of_digits--;
    } while (num_of_digits > 0);

    if (flags->minus == 1) {
      if (width_difference > 0) {
        for (int i = 0; i < width_difference; i++) {
          *str = ' ';
          str++;
        }
      }
    }
  } else {
    if (flags->width > 0) {
      for (int i = 0; i < flags->width; i++) {
        *str = ' ';
        str++;
      }
    }
  }
  *str = '\0';
}

void s21_uitos(char *str, unsigned long num, flag_t *flags) {
  if (flags->precision == -1) {
    flags->precision = 1;
  }

  if ((flags->precision != 0) || (num != 0)) {
    int num_of_digits = 0;
    unsigned long complete_part = num;

    while (complete_part > 0) {
      num_of_digits++;
      complete_part = complete_part / 10;
    }
    complete_part = num;

    if (num_of_digits < flags->precision) {
      num_of_digits = flags->precision;
    }
    int width_difference = flags->width - num_of_digits;

    if (flags->minus == 0) {
      if (width_difference > 0) {
        for (int i = 0; i < width_difference; i++) {
          *str = ' ';
          str++;
        }
      }
    }

    do {
      unsigned long int c = s21_pow(10, num_of_digits - 1);
      int b = complete_part / c;
      complete_part = complete_part % c;
      *str = '0' + b;
      str++;
      num_of_digits--;
    } while (num_of_digits > 0);

    if (flags->minus == 1) {
      if (width_difference > 0) {
        for (int i = 0; i < width_difference; i++) {
          *str = ' ';
          str++;
        }
      }
    }
  } else {
    if (flags->width > 0) {
      for (int i = 0; i < flags->width; i++) {
        *str = ' ';
        str++;
      }
    }
  }
  *str = '\0';
}

void s21_ftos(char *str, double num, flag_t *flags) {
  if (flags->precision == -1) {
    flags->precision = 6;
  }

  if (num < 0.0) {
    num -= 5.0 / s21_pow(10, flags->precision + 1);
  } else {
    num += 5.0 / s21_pow(10, flags->precision + 1);
  }

  int sign = 0;
  if (num < 0) {
    sign = -1;
    flags->width--;
  } else if (flags->plus == 1) {
    sign = 1;
    flags->width--;
  } else if (flags->space == 1) {
    flags->width--;
  }

  long int complete_part = num;
  double fractional_part = num - complete_part;
  int num_of_digits = 0;
  if (complete_part == 0) {
    num_of_digits = 1;
  }

  while (complete_part != 0) {
    num_of_digits++;
    complete_part = complete_part / 10;
  }
  complete_part = num;
  int width_difference = flags->width - (num_of_digits + flags->precision);

  if (flags->precision != 0) {
    width_difference--;
  }

  if (flags->minus == 0) {
    if (width_difference > 0) {
      for (int i = 0; i < width_difference; i++) {
        *str = ' ';
        str++;
      }
    }
  }

  if (sign < 0) {
    *str = '-';
    str++;
  } else if (sign > 0) {
    *str = '+';
    str++;
  } else if (flags->space == 1) {
    *str = ' ';
    str++;
  }

  do {
    long int c = s21_pow(10, num_of_digits - 1);
    int b = complete_part / c;
    complete_part = complete_part % c;
    if (b < 0) {
      b = -b;
    }
    *str = '0' + b;
    str++;
    num_of_digits--;
  } while (num_of_digits > 0);

  if (flags->precision > 0) {
    *str = '.';
    str++;
  }

  for (int i = 0; i < flags->precision; i++) {
    fractional_part = fractional_part * 10.0;
    int b = fractional_part;
    fractional_part -= b;
    b = b % 10;
    if (b < 0) {
      b = -b;
    }
    *str = '0' + b;
    str++;
  }

  if (flags->minus == 1) {
    if (width_difference > 0) {
      for (int i = 0; i < width_difference; i++) {
        *str = ' ';
        str++;
      }
    }
  }

  *str = '\0';
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list(input);
  va_start(input, format);
  char *start_str = str;

  flag_t flags;
  reset_flags(&flags);

  int spec_state = 0;
  int spec_found = 0;

  while (*format) {
    if (spec_state == 0) {
      if (*format == '%') {
        spec_state = 1;
      } else {
        *str = *format;
        str++;
      }
      format++;
    } else {
      if (*format == 'c' || *format == '%') {
        str = print_char(str, &flags, *format, &input);
        spec_found = 1;
      }
      if (*format == 's') {
        str = print_string(str, &flags, &input);
        spec_found = 1;
      }
      if (*format == 'd' || *format == 'i' || *format == 'u' ||
          *format == 'f') {
        str = print_number(str, &flags, *format, &input);
        spec_found = 1;
      }
      if (*format == '+') {
        flags.plus = 1;
      }
      if (*format == '-') {
        flags.minus = 1;
      }
      if (*format == ' ') {
        flags.space = 1;
      }
      if (*format == 'h') {
        flags.is_short = 1;
      }
      if (*format == 'l') {
        flags.is_long = 1;
      }
      if ((*format >= '0') && (*format <= '9')) {
        while ((*format >= '0') && (*format <= '9')) {
          flags.width = flags.width * 10 + (*format - 48);
          format++;
        }
        format--;
      }
      if (*format == '.') {
        flags.precision = 0;
        format++;
        while ((*format >= '0') && (*format <= '9')) {
          flags.precision = flags.precision * 10 + (*format - 48);
          format++;
        }
        format--;
      }
      if (spec_found == 1) {
        spec_state = 0;
        spec_found = 0;
        reset_flags(&flags);
        str++;
      }
      format++;
    }
  }
  *str = '\0';
  va_end(input);
  int result = str - start_str;
  return result;
}

int s21_sscanf(const char* source, const char *format, ...){
va_list args;

flagscanf sscan_Flags={{0}, 0};

va_start(args, format);
// char* s=va_arg(args, char*);
// printf("STRING FROM MAIN=%s\n", s);
// int* x=va_arg(args, int*);
// printf("INT X IN MAIN=%d\n", *x);
char* tmp;
flagscanf Flagscanf={{0}, 0};
while(*format!='\0'&&*source!='\0'){
    printf("here?\n");
    while(*format==*source&&*format!='%'){
      format++; source++;
    }
    if(*format=='%'&&Flagscanf.failed==0){
        format++;
        Flagscanf.width=0;
        set_params(&Flagscanf, &format);
        printf("test");
        //Flagscanf=scanfparser_flags(&format); // заполняем от ' ' до 0 почему не растет указатель я разименовываю 1 раз, значит должен расти формат
        scanfparser_spec(format, &Flagscanf); // заполняем спецификаторы например d или s
        //Flagscanf=scanfparser(format);
        scanf_concat_type(&Flagscanf, args, &source); //возвращаем то, что мы пишем в переменную,
        //va_arg(args,char*);
        printf("tmp=%s\n", tmp);
        //как вообще подставить в функцию имя переменной когда оно само переменная?
        //strcat(, tmp);
        //move_str=strlen(tmp);

        
    }
    format++;


}
printf("Flagscanf:\nbase.integer=%d\nbase.string=%d\nfplus=%d\n", Flagscanf.base.integer, Flagscanf.base.string, Flagscanf.fplus);
//printf("Flagscanf:\nbase->integer=%d\n", Flagscanf.base.integer);
}

flagscanf scanfparser_flags(const char** format){
    //(*format)++;
    flagscanf Flags={0};
    
    while(**format==' '||**format=='-'||**format=='+'||**format=='#'||**format=='0'){
        switch(**format){
            case' ':
            Flags.fspace=1;
            break;
            case'-':
            Flags.fminus=1;
            break;
            case'+':
            Flags.fplus=1;
            break;
            case'#':
            Flags.fsharp=1;
            break;
            case'0':
            Flags.fzero=1;
            break;
        }
        (*format)++;
    }
    return Flags;

}

 void scanfparser_spec(const char *format, flagscanf* Flags){
        
        //format++;
        while(*format!='\0'&&*format!='%'&&*format!=' '){
            printf("here?:82");
        switch(*format){
           // case'[':
                // logic parsing regular
                //Flags->regular == NULL;
               // break;
            case 'h':
            Flags->h=1;
            format++;
            break;   
            case 'l':
            if(Flags->l==1){
                Flags->ll=1;
            }
            else{
            Flags->l=1;}
                
            format++;//странно что здесь отрабатывает нормально сдвиг
            break;
            case 'L':
            Flags->L=1;
            format++;
            break;
            default:
                Flags->base = parser(&format, Flags->base); 
        }
    //format++;


    }
       }    

 
   void scanf_concat_type(flagscanf* Flags, va_list arg, const char** source){
    void* add_this=malloc(10000);
    
    long double* result=calloc(1, sizeof(long double));
    if(Flags->base.integer==1){
       add_this=(void*)scanf_write_int(Flags, arg, source, result);
    }
    if(Flags->base.string==1){
        add_this=scanf_write_string(Flags, arg, source);
    }
    if(Flags->base.decimal_octal_hex==1||Flags->base.p){
        add_this=(void*)scanf_write_decimal_octal_hex(arg, source, Flags, result);
        // printf("ADDTHIS=%d\n", *((int*)add_this)); interesting segfault 
    }
    if(Flags->base.e==1){
        sscanf_write_e(arg, source, Flags, result);
    }
    if(Flags->base.o==1){
        sscanf_write_o(arg, source, Flags, result);
    }
    if(!Flags->base.string&&!Flags->base.e&&!Flags->base.o){
     if(Flags->ll){ 
        *(va_arg(arg, long long int *)) = (long long int)*result;}
        else if(Flags->l){*(va_arg(arg, long int *)) = (long int)*result;}
        else if(Flags->h){*(va_arg(arg, short int *))= (short int)*result;}
        else{*(va_arg(arg, int*))=(int)*result;}}
    //     else{
    //       int* x=va_arg(arg, int*);
    //       printf("test");}
    //       }
    // // if(Flags->base.e)
    // {*(va_arg(arg, float*))=(float)*result;}    

   
    //return (void*)add_this; //мы допишем это в str вместо %d
   } 

   flags    parser(const char **format, flags Flags){
        //flags Flags={0};
        //(*format)++;
        while(**format=='d'||**format=='s'||**format=='i'||**format=='e'||**format=='o'||**format=='E'||**format=='g'||**format=='G'||**format=='f'){
           printf("here?:parser163");
    //           case 'e':
    // case 'E':
    // case 'g':
    // case 'G':
    // case 'f':
        switch(**format){
            
        case 'd':
            Flags.integer=1;
            Flags.move_format=2;
            break;
        case 's':
            Flags.string=1;
            Flags.move_format=2;
            break;  
        case 'i':
            Flags.decimal_octal_hex=1;
            break;   
        case 'e':
        case 'E':
        case 'g':
        case 'G':
        case 'f':
            Flags.e=1;
            break; 
        case 'o':
            Flags.o=1;        
        default:
            break;  }
            
            (*format)++;
    }
    return Flags;


    }

int* scanf_write_int(flagscanf* Flags, va_list arg, const char** source, long double* result ){
    Flags->failed=1;
   // int* i=va_arg(arg, int*);// какое будет поведение у  va_arg  если тип аргумента не соответствует, например мы указываем int* а там лежит  char*
   // printf("VALUE OF INT I FROM MAIN=%d\n", *i);
    while(**source==' '||**source=='0')(*source)++;
    int i_i;
    char buffer[1000];
    int count=0;
    char* pbuffer=buffer;
    int is_int=0;//вырастет только если была запись в int
    if(**source=='\0'||**source==' '||(**source>=0&&**source<=57&&**source!=32)){ //это нужно чтобы не двигало курсор если мы пытаемся прочитать строку как d
    while(**source!='\0'&&**source!=' '){
        if(**source>=0&&**source<=57&&**source!=32){
            is_int=1; Flags->failed=0;
            while(**source!=' '&&**source!='\0'&&Flags->width>0){
                *pbuffer=**source;
                pbuffer++;
                (*source)++;
               count++;
               Flags->width--;
            }
            //if(Flags->width>0)buffer[Flags->width]='\0';
            
        i_i=atoi(buffer); //buffer почему-то остается в памяти, поэтому заводим счетчик count и зануляем buffer после atoi
        while(count>0){
            buffer[count]='\0';
            count--;
        }
        printf("WRITTEN INT=%d\n", i_i);
        
        break;}
        
       (*source)++;
        
    }
    }

    if(is_int)*result=i_i;
    
    //printf("INT WRITTEN TO MAIN VAR=%d\n", *i);

    
    //x=itoa(va_arg(arg, int), x, 10);
    
    
//return i;

}

char* scanf_write_string(flagscanf* Flags, va_list arg, const char** source){

    while(**source==' '){
        (*source)++;
    }
    char* variable=va_arg(arg, char*);
    char buffer[300]="11";
    int wcount=0;//счетчик сколько раз мы записали, чтобы отмотать
    while(**source!=' '&&**source!='\0'&&(Flags->width>0||Flags->width==-1)){ //пишем из source в буфер, а почему нельзя сразу писать в variable?
        variable[wcount]=**source;
        wcount++;
        (*source)++;
        if(Flags->width!=-1)Flags->width--;


    }

    variable[wcount]='\0';
    // while(wcount>=0){
    // variable[wcount]=buffer[wcount];//segfault
    //     wcount--;

    // }
   
    
        printf("\nBUFFER=%s\n", buffer);
        printf("VARIABLE=%s\n", variable);

    
    
return variable;

}

int* scanf_write_decimal_octal_hex(va_list arg, const char** source, flagscanf* Flags, long double* result){
    Flags->failed=1;
    //int* variable_adress=va_arg(arg, int*);
    int buffer_integer;
    while(**source==' ')(*source)++;
    char buffer[1000];
    
    
    char* pbuffer=buffer;
    int is_int=0;
    int is_hex=0;
    int is_octal=0;
    int minus=0;
    int count_reverse=0;
    if(**source=='-'){
        minus=1;(*source)++;
    }
    if(**source==' '||(**source>=0&&**source<=57&&**source!=32)){
        Flags->failed=0;
        while(**source!='\0'&&**source!=' '&&(is_octal ? **source<'8':1)){ //вообще ведь нельзя вставить if в while условие? только через ?
            if(**source>=0&&**source<=57&&is_int_f(**source)){
                if(**source=='0'&&*(*source+1)=='x'){ //priority of * highter than + but not highter than ++ seems like
                is_hex=1;(*source)=(*source)+2;}
                if(**source=='0'&&is_int_f(*(*source)+1)&&!is_hex){
                   // if(**source=='0'&&is_int_f(&((*source)+1))){ почему так нельзя хотел передавать функции указатель на указатель, переделал функцию чтобы брала чар
                is_octal=1;(*source)++;
                }
             if(!is_hex&&!is_octal)is_int=1;//пишем в variable только если флаг поднят, если я сделаю int is_int прямо сдесь это плохо, это значит будет переинициализация каждый цикл или норм и оно не будет нагружать программу и инициализирует только 1 раз?
             while(**source!=' '&&**source!='\0'&&(is_octal ? **source<'8':1)){ //если не поставить последнее условие в скобки то оно считает все до ? условием, и оно никогда не выполняется, следовательно всегда 1
                *pbuffer=**source;
               //cannot do that? (&buffer)++;
               //cannot do that? buffer++;
               //must make char* pbuffer=buffer ?
                (*source)++;
                pbuffer++;
                count_reverse++;

             }
            *pbuffer='\0';
             
            }
        }
 while(count_reverse>0){ //отматываем source назад
(*source)--;
count_reverse--;
pbuffer--;
}
    }
    buffer_integer=atoi(buffer);
    printf("buffer_integer=%d", buffer_integer);
//long long result;
    if(is_hex){
        // char* endptr;
        
        *result = hex_to_dex(buffer, 16, Flags, minus, source);
        // *variable_adress=result;
       
        //*variable_adress=hex_to_dex(buffer, 16, Flags, minus);
    }
    if(is_octal){
       *result=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    if(is_int){
       *result=minus ? -1.0*buffer_integer:1*buffer_integer;
    }
    //  if(Flags->ll){ *(va_arg(arg, long long int *)) = (long long int)result;}
    //     else if(Flags->l){*(va_arg(arg, long int *)) = (long int)result;}
    //     else if(Flags->h){*(va_arg(arg, short int *))= (short int)result;}
    //     else{*(va_arg(arg, int*))=(int)result;}
       

}

int is_int_f(char c){
    int x=0;
    if(c>=0&&c<=57&&c!=32)
    x=1;
    return x;
}

int dec_convert(int input, int base){
    int power=0;
    int dec=0;

    while(input>0){
    dec=dec+(input%10)*s21_pow(base, power);
    input=input/10;
    power++;}
    return dec;
}

void sscanf_write_e(va_list arg, const char** source, flagscanf* Flags, long double* result){
    Flags->failed=1;
    float* variable_address=va_arg(arg, float*);
    float buffer_float;
    
    while(**source==' ')(*source)++;
    char buffer[10000];
    char* pbuffer=buffer;
    number_type type={0};
    // int minus=0;
    if(**source>=0&&**source<=57&&**source!=32){
        Flags->failed=0;
        // if(**source=='-')minus=1;
        while(**source!='\0'&&**source!=' '){
            if(**source=='0'&&*(*source+1)=='x'){
                type.is_hex=1; (*source)=(*source)+2;}//skip 0x to number
            
            if(**source=='0'&&is_int_f(*(*source)+1)){
                type.is_octal=1;(*source)++;
            }
            for(int i=1;*(*source+i)!=32;i++){ //тут если вместо 32 поставить ' ' почему то выкидывает из цикла на одну итерацию позже
                if(*(*source+i)=='e'||*(*source+i)=='E'){
                type.is_scientific=1;printf("is scientific\n");
                
                }
            }
            if(!type.is_hex&&!type.is_octal&&!type.is_scientific)type.is_int=1;
            while(**source!=32){
                *pbuffer=**source;
                (*source)++;
                pbuffer++;
            }
            *pbuffer='\0';
    }
        }
        int integer_from_string=atoi(buffer);
    if(type.is_scientific)
    *variable_address=scientific_to_float(buffer); 
    else{
    *variable_address=a_to_float(buffer);}
    if(Flags->failed==1){
        if((s21_strncmp(*source, "inf", 3)==0) ||
        (s21_strncmp(*source, "INF", 3)==0) ||
        (s21_strncmp(*source, "Inf", 3)==0) ||
        (s21_strncmp(*source, "inF", 3)==0) ||
        (s21_strncmp(*source, "InF", 3)==0) ||
        (s21_strncmp(*source, "iNF", 3)==0))
        {
            *variable_address=INFINITY;
            Flags->failed=0;
            *source += 3;
        }
    if((s21_strncmp(*source, "nan", 3)==0) ||
        (s21_strncmp(*source, "NAN", 3)==0) ||
        (s21_strncmp(*source, "NaN", 3)==0) ||
        (s21_strncmp(*source, "Nan", 3)==0) ||
        (s21_strncmp(*source, "naN", 3)==0) ||
        (s21_strncmp(*source, "nAN", 3)==0) )
        {
            *variable_address=NAN;
            Flags->failed=0;
            *source += 3;
        }    

    } 
    
            
    }

    float scientific_to_float(char* string){
    char pre_dot[1000000];//тут был stack smashing если маленькие размеры массивов
    float pre_dot_float;
    char post_dot[1000000]="000000";
    float post_dot_float;
    char exponent[1000000];
    int count=0;
    while(*string!='.'){
        pre_dot[count]=*(string);
        string++;
        count++;

    }
    pre_dot[count]='\0';
    count=0;
    string++;
    while(*string!='e'&&*string!='E'){
        post_dot[count]=*string;
        string++;count++;
    }
    post_dot[count]='\0';
    count=0;
    while(*string!='+'&&*string!='-'){
        *(string++);
    }

    while(*string!=' '){
        exponent[count]=*(string);
        count++;string++;
    }
    exponent[count]='\0';
 int i=0; //количество знаков, заводим для знака после точки
 pre_dot_float=(float)char_to_dec(&i, pre_dot);
 i=0;
 post_dot_float=(float)char_to_dec(&i, post_dot);
 while(i>0){
    post_dot_float /=10;
    i--;

 }
 float return_this=pre_dot_float+post_dot_float;
 return_this=exponent_f(exponent, return_this);


    

    // printf("\n\n post_dot_float=%f", pre_dot_float);
    // printf("\n\n post_dot_float=%f", post_dot_float);
    // printf("\n\npredot=%s\n\n", pre_dot);
    // printf("\n\npostdot=%s\n\n", post_dot);
    // printf("\n\nexponent=%s\n\n", exponent);
    return return_this;

   }

   long double char_to_dec(int* i, char str[]){
    long double result = 0.0;
    while(*str>=48&&*str<=57) {//0 to 9
    (*i)++;
    result *= 10;
    result += *str-'0';
    str++;
      }
       return result;
  }

  long double exponent_f(char exp[], float pre_plus_post){
    int is_negative=0; 
    float return_this;
    if(*exp=='-'){
            is_negative=1; }  
            exp++;
    
if(!is_negative){
    printf("AAAAA%lf", (((float)atoi(exp))*10));
return_this=pre_plus_post*s21_pow(10, (float)atoi(exp));

};
printf("\n\nEXPONENTED=%f\n\n", return_this);
return return_this;
  }

 long long int hex_to_dex(char str[], int base, flagscanf *param, int minus, const char** source) {
  long long int result = 0x0;
 // param->failed = 1;
  char *start_str = str;
  long long int sign = minus ? -1.0:1;
  
    //  base = 16;
  
  


    
  
int break_=0;
  while (((*str >= 48 && *str <= 57) || (*str >= 65 && *str <= 70) ||
          (*str >= 97 && *str <= 102))&&break_==0 ) {
    if (*str >= 48 && *str <= 55) {
      result = (*str - '0') + result * base;
      str++;
      (*source)++;
      
    } else if ((*str >= 56 && *str <= 57) && (base != 8)) {
      result = (*str - '0') + result * base;
      str++;
      (*source)++;
     
    } else if ((*str >= 65 && *str <= 70) && (base != 8) && (base != 10)) {
      result = (*str - 55) + result * base;
      str++;
      (*source)++;
    } else if ((*str >= 97 && *str <= 102) && (base != 8) && (base != 10)) {
      result = (*str - 87) + result * base;
      str++;
      (*source)++;
    }
    else{break_=1;}
    
   // param->failed = 0;
  }
//   if (param->failed == 1) *str = *start_str;
  return result * sign;
} 

int convert_to_dec(int input, int base, int minus){
    int power=0;
    int dec=0;
    
    while(input>0){
    dec=dec+(input%10)*pow(base, power);
    input=input/10;
    power++;}
    return minus ? dec*-1.0:dec;
}

void sscanf_write_o(va_list arg, const char** source, flagscanf* Flags, long double* result){
     Flags->failed=1;
    int* variable_adress=va_arg(arg, int*);
    int buffer_integer;
    while(**source==' ')(*source)++;
    char buffer[1000];
    
    
    char* pbuffer=buffer;
    int is_int=0;
    int is_hex=0;
    int is_octal=0;
    int minus=0;
    int count_reverse=0;
    if(**source=='-'){
        minus=1;(*source)++;
    }
    if(**source==' '||(**source>=0&&**source<=57&&**source!=32)){
        Flags->failed=0;
        while(**source!='\0'&&**source!=' '&&is_int_f(**source)){
            if(**source>=0&&**source<=57&&is_int_f(**source)){
               
                if(**source=='0'&&is_int_f(*(*source)+1)&&!is_hex){
                   // if(**source=='0'&&is_int_f(&((*source)+1))){ почему так нельзя хотел передавать функции указатель на указатель, переделал функцию чтобы брала чар
                is_octal=1;(*source)++;
                }
             if(!is_hex&&!is_octal)is_int=1;//пишем в variable только если флаг поднят, если я сделаю int is_int прямо сдесь это плохо, это значит будет переинициализация каждый цикл или норм и оно не будет нагружать программу и инициализирует только 1 раз?
             
             while(**source!=' '&&**source!='\0'&&is_int_f(**source)){
                *pbuffer=**source;
               //cannot do that? (&buffer)++;
               //cannot do that? buffer++;
               //must make char* pbuffer=buffer ?
                (*source)++;
                pbuffer++;
                count_reverse++;
                //count++;

             }
            *pbuffer='\0';
//тут была сега если вставить отмотку сюда, то идет бесконечный цикл и pbuffer растет вплоть до segfault
             
            }
      
        }
              while(count_reverse>0){ //отматываем source назад
(*source)--;
count_reverse--;
pbuffer--;
}

    }
    buffer_integer=atoi(buffer);
    printf("buffer_integer=%d", buffer_integer);

    if(is_hex){
        // char* endptr;
        
        // long int result = strtol(buffer, &endptr, 16);
        // *variable_adress=result;
        *variable_adress=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    if(is_octal){
        *variable_adress=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    if(is_int){
       *variable_adress=hex_to_dex(buffer, 8, Flags, minus, source);
    }
    

}

float a_to_float(char* string){
    char pre_dot[10000];
    float pre_dot_float;
    char post_dot[10000]="000000";
    float post_dot_float;
    char exponent[10000];
    long long int sign=set_sign(string);
    int count=0;
    while(*string!='.'){
        pre_dot[count]=*(string);
        string++;
        count++;

    }
    pre_dot[count]='\0';
    count=0;
    string++;
    while(*string!=' '&&*string!='\0'&&is_int_f(*string)){
        post_dot[count]=*string;
        string++;count++;
    }
    post_dot[count]='\0';
    count=0;
    

    
    
 int i=0; //количество знаков, заводим для знака после точки
 pre_dot_float=(float)char_to_dec(&i, pre_dot);
 i=0;
 post_dot_float=(float)char_to_dec(&i, post_dot);
 while(i>0){
    post_dot_float /=10;
    i--;

 }
 float return_this=pre_dot_float+post_dot_float;
 
    return return_this*sign;

   }

 long int set_sign(char *str) {
  long int sign = 1;
  if (*str == '+') {
    str++;
  } else if (*str == '-') {
    sign = -1.0;
    str++;
    
  }
  return sign;
}
  