#include <stdio.h>
//#include <string.h>
#include "s21_string.h"
int main(){
    char str[80]="HEEHEEHEE";
    char str21[]="HEYHEYHEY";//ставим сюда значение массива оно отрабатывает нормально, указываем просто размер и оно пишет не то, с размером работает 6 работает 7 не работает а на убунте работает не взирая на это
    
    int y=44,z, i=5;
    y=5;
    int ii, zz=77, zz1=88;
    char input[]="test-11";
    
    //sscanf("777 test 1111 2 3 4 5", "%s%d%d", str, &i, &ii);
    sscanf(input, "test%o%s%d", &i, str, &zz);
   // s21sscanf("777  test  1111 2 3 4 5", "%s%d%d", str21, &y, &z);
    s21_sscanf(input, "test%o%s%d", &y, str21, &zz1);
    //             source                           va_list arg
    //s21sscanf("hello 1111 2 3 4 5", "%d",&y);
     //s21sscanf("hello 1111 2 3 4 5", "%+d%s", &y, str21);
    printf("\nmain printf string:%o %s %d\n", y, str21, zz1);
    printf("orig:%o %s %d\n", i, str, zz);
    // printf("s21 : %s %d\n", str21, y);
    return 0;
}
//sscanf  проверяется на   %s %d и %e