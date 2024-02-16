#include <stdio.h>
#include <stdint.h>
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
 char str1[10] = {0};
  char str2[10] = {0};

  char c1 = '0';
  char c2 = '0';

  float f1 = 0.0;
  float f2 = 0.0;

  int x1 = 0x0;
  int x2 = 0x0;
  unsigned int x3 = 0x0;
  unsigned x4 = 0x0;

  void *ptr1 = 0x0;
  void *ptr2 = 0x0;

  int a1 = 5;
  int a2 = 5;
  unsigned int u1 = 0;
  unsigned int u2 = 0;

  int n1 = 0;
  int n2 = 0;
  int n3 = 0;
  int n4 = 0;
  int result1 = 0;
  int result2 = 0;
  result1 = s21_sscanf("strnan -6.1e+1c -20    -0x2024        0x2024 -120 0256",
                       "%6s%7e%n%c%20u%7i%p%d%3o%n", str1, &f1, &n1, &c1, &u1,
                       &x1, &ptr1, &a1, &x3, &n3);
  result2 = sscanf("strnan -6.1e+1c -20    -0x2024        0x2024 -120 0256",
                   "%6s%7e%n%c%20u%7i%p%d%3o%n", str2, &f2, &n2, &c2, &u2, &x2,
                   &ptr2, &a2, &x4, &n4);

printf("Values after s21_sscanf:\n");
printf("str1 = \"%s\", f1 = %f, n1 = %d, c1 = %c, u1 = %u, x1 = %d, ptr1 = %p, a1 = %d, x3 = %u, n3 = %d, result1 = %d\n", str1, f1, n1, c1, u1, x1, ptr1, a1, x3, n3, result1);

printf("\nValues after sscanf:\n");
printf("str2 = \"%s\", f2 = %f, n2 = %d, c2 = %c, u2 = %u, x2 = %d, ptr2 = %p, a2 = %d, x4 = %u, n4 = %d, result2 = %d\n", str2, f2, n2, c2, u2, x2, ptr2, a2, x4, n4, result2);



  

    return 0;
}
//sscanf  проверяется на   %s %d и %e