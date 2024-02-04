#include "s21_string.h"
void set_params(flagscanf *Flags, const char **format) {
  width_function(format,  &(Flags->width));
  if (Flags->width == 0) {
    Flags->width = -1;
    Flags->failed = 0;
  }

  
}

void width_function(const char **format, int *width) {
   while (**format <= 57 && **format >= 48) {
    *width = *width * 10 + (**format - '0');
    (*format)++;

    
  }

  }