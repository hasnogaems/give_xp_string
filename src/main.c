#include <stdio.h>
#include <string.h>
#include "s21_string.h"
int main(){
    char string[300];
    char word[]="WORD";
    int number=100;
    sprintf(string, "word is %s number is %d\n", word, number);
    printf("printf result is:%s", string);
    s21_sprintf(string, "number is %d, word is %s yo\n", number, word);
    printf("s21_printf result is:%s", string);
}