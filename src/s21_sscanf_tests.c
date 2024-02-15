#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"



START_TEST(sscanf_str) {
  char str[] = "Hello, world! 111 0x34ab";
  char str1[100], str2[100];
  int a, b;
  void* p1, *p2;


  s21_size_t len = strlen(str);
  sscanf(str, "%s%d%p", str1, &a, &p1);
  s21_sscanf(str, "%s%d%p", str2, &b, &p2);
  
  
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(a, b);
  // ck_assert_pstr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_int) {
  char str[] = "Hello, world! 111 0x34ab";
  char str1[100], str2[100];
  int a, b;
  void* p1, *p2;


  s21_size_t len = strlen(str);
  sscanf(str, "%d%p", &a, &p1);
  s21_sscanf(str, "%d%p", &b, &p2);
  
  
  
  ck_assert_int_eq(a, b);
  // ck_assert_pstr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_ptr) {
  char str[] = "Hello, world! 111 0x34ab";
  char str1[100], str2[100];
  int a, b;
  void* p1, *p2;


  s21_size_t len = strlen(str);
  sscanf(str, "%d%p", &a, &p1);
  s21_sscanf(str, "%d%p", &b, &p2);
  
  
  
  
  ck_assert_ptr_eq(p1, p2);
}
END_TEST




Suite *s21_string_suite(void) {
  Suite *suite;

  suite = suite_create("s21_string");
  TCase *tcase_core = tcase_create("Core");

 

  tcase_add_test(tcase_core, sscanf_str);
  tcase_add_test(tcase_core, sscanf_int);
  tcase_add_test(tcase_core, sscanf_ptr);
  

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}