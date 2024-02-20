#include "s21_sscanf.h"
#include "s21_tests.h"



void run_tests(void) {
  Suite *list_cases[] = {
      suite_sscanf(), s21_string_suite(), NULL};
  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}
void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;
  if (counter_testcase > 1) putchar('\n');
  printf("CURRENT TEST: %d\n", counter_testcase);
  counter_testcase++;
SRunner *sr=calloc(counter_testcase, sizeof(SRunner *));
   sr = srunner_create(testcase);

  //srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}
int main(void) {
  run_tests();
  return 0;
}

