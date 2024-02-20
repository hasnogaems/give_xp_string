#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_tests.h"
int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  suite = suite_sscanf();
  suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  failed_count += srunner_ntests_failed(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}