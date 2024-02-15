#include <stdio.h>

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_string.h"
#define BUFF_SIZE 100
int main(){
    char strrr[80]="HEEHEEHEE";
    char str21[]="HEY";//ставим сюда значение массива оно отрабатывает нормально, указываем просто размер и оно пишет не то, с размером работает 6 работает 7 не работает а на убунте работает не взирая на это
    
    float y=44,z, i=5;
    y=5;
    int ii, bb, zz=55, zz1=88, pp;
    char input[]="test11.22e10hhh777";
    
    
//     sscanf("777 test 1111 2 3 4 5", "%s%d%d", str, &pp, &ii);
//     sscanf(input, "test%e%4s%1d", &i, str, &zz);
//    // s21sscanf("777  test  1111 2 3 4 5", "%s%d%d", str21, &y, &z);
//     s21_sscanf(input, "test%e%4s%1d", &y, str21, &zz1);
//     //             source                           va_list arg
//     //s21sscanf("hello 1111 2 3 4 5", "%d",&y);
//      //s21sscanf("hello 1111 2 3 4 5", "%+d%s", &y, str21);
//     printf("\nmain printf string:%f %s %d\n", y, str21, zz1);
//     printf("orig:%f %s %d\n", i, str, zz);
   // int inty=13, iinty=14;
 //    ii=sscanf("6666 666", "%*u %d", &zz1);
//    // s2my_tests1sscanf("777  test  1111 2 3 4 5", "%s%d%d", str21, &y, &z);
 //    bb=s21_sscanf("66666 6666", "%*u %d", &zz);
     printf("\nmain printf string:%d\n", zz);

//       void* pointer21, *pointer;
   
     printf("orig:%d\n", zz1);\
//     // printf("s21 : %s %d\n", str21, y);
//     printf("orig count=%d\n s21 count=%d\n", ii, bb);
// void* pointer21, *pointer;
//      ii=sscanf("0x11ab", "%p", &pointer);
//    // s21sscanf("777  test  1111 2 3 4 5", "%s%d%d", str21, &y, &z);
//     bb=s21_sscanf("0x11ab", "%p", &pointer21);
//      printf("\nmain printf string:%p\n", pointer21);
//     printf("orig:%p\n", pointer);\
//      char str[] = "Hello, world! 111 0x34ab";
//   char str1[100], str2[100];
//   int a, b;
//   void* p1, *p2;


 
//   sscanf(str, "%s%d%p", str1, &a, &p1);
//   s21_sscanf(str, "%s%d%p", str2, &b, &p2);
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%150s%1s%1s\t%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);
  

    return 0;
}
//sscanf  проверяется на   %s %d и %e