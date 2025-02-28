CFLAGS = -Werror -Wall -Wextra -std=c11
CC = gcc

EXCLUDE_FILES = tests/*.c
SRC_MATRIX_LIB = $(filter-out $(EXCLUDE_FILES), $(wildcard *.c))
OBJ_MATRIX_LIB = $(SRC_MATRIX_LIB:.c=.o)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  OPEN_CMD = xdg-open
  ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif
ifeq ($(UNAME_S),Darwin)
  OPEN_CMD = open
  ADD_LIB =
endif


all: clean s21_matrix.a gcov_report

gcov_report: clean
	@$(CC) $(CFLAGS) --coverage $(SRC_MATRIX_LIB) $(EXCLUDE_FILES) -o s21_test -lcheck -lm -lsubunit
	@./s21_test
	@lcov -t "s21_test" -o s21_test.info -c -d .
	@lcov -remove s21_test.info -o s21_test.info
	@genhtml -o report --function-coverage s21_test.info
	@$(OPEN_CMD) report/index.html
	@rm -rf *.gcda *.gcno s21_test *.info


clean: 
	@rm -rf *.o *.a *.gcno *.out *.gcda s21_test_matrix report *.info

s21_matrix.a: $(OBJ_MATRIX_LIB)
	ar rsc $@ $^

test: clean
	@$(CC) $(SRC_MATRIX_LIB) $(EXCLUDE_FILES) -o s21_test_matrix -lcheck -lsubunit -lm
	@./s21_test_matrix
	@rm -rf *.gcno *.gcda  

memory_check: s21_matrix.a
	@gcc -g -O0 -Wall -Werror -Wextra -o s21_test_matrix $(EXCLUDE_FILES) -L. s21_matrix.a -lcheck -lsubunit -lm
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_test_matrix

fmt:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c *.h
	rm .clang-format
