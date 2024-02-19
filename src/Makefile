.PHONY: all s21_string.a s21_string.o
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
CCOVTEST= -fprofile-arcs -ftest-coverage
LIBS = -lm


all: s21_string.a

s21_string.a: s21_string.o
	ar rcs $@ $^

browntod:
	gcc s21_string.c s21_sscanf.c test_sscanf.c -lm -lcheck -lpthread -lsubunit	

s21_string.o: s21_string.c s21_sscanf.c s21_string.h
	$(CC) $(CFLAGS) -c s21_string.c s21_sscanf.c

test: test_s21_string.o s21_string.o
	$(CC) $(CFLAGS) $(CCOVTEST) $^ $(LIBS) -o $@ -lcheck -lm -lpthread -lsubunit
	./test

test_s21_string.o: s21_string_tests.c s21_string.h
	$(CC) $(CFLAGS) $(CCOVTEST) -I. -c $< -o $@

gcov_report: test s21_string.a
	$(CC) $(CFLAGS) -pedantic   $(CCOVTEST) s21_string_tests.c s21_string.c s21_string.a -o  $@ -lcheck -fprofile-arcs -ftest-coverage -lm -lpthread -lsubunit
	./gcov_report
	lcov -t gcov_report -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.h

clean:
	rm -f *.a
	rm -f *.o
	rm -f test
	rm -f *.gc*
	rm -f gcov_report.html
	rm -f gcov_report
	rm -f test.info
	rm -f -R report

rebuild: clean all