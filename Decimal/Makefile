CFLAGS = -Werror -Wextra -Wall -std=c11
CC = gcc

EXCLUDE_FILES = s21_test_functions.c
SRC_DECIMAL_LIB = $(filter-out $(EXCLUDE_FILES), $(wildcard *.c))
OBJ_DECIMAL_LIB = $(SRC_DECIMAL_LIB:.c=.o)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	OPEN_CMD = xdg-open
	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif
ifeq ($(UNAME_S),Darwin)
	OPEN_CMD = open
	ADD_LIB =
endif

all: clean s21_decimal.a gcov_report

clean: 
	@rm -rf *.o *.a *.gcno *.out *.gcda s21_test_functions report *.info

test: clean
	@$(CC) $(CFLAGS) $(SRC_DECIMAL_LIB) s21_test_functions.c -o s21_test_functions $(ADD_LIB)
	@./s21_test_functions
	@rm -rf *.gcno *.gcda	

s21_decimal.a: $(OBJ_DECIMAL_LIB)
	ar rcs $@ $^

gcov_report: clean
	@$(CC) $(CFLAGS) --coverage $(SRC_DECIMAL_LIB) s21_test_functions.c -o s21_test $(ADD_LIB)
	@./s21_test
	@lcov -t "s21_test" -o s21_test.info -c -d .
	@lcov -r s21_test.info "/usr/*" "*/test/*" -o s21_test_filtered.info --ignore-errors unused
	@genhtml -o report --function-coverage s21_test_filtered.info
	@$(OPEN_CMD) report/index.html
	@rm -rf *.gcda *.gcno s21_test *.info

fmt:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c *.h
	rm .clang-format

memory_check: s21_decimal.a
	@gcc -g -O0 -Wall -Werror -Wextra -o s21_test_functions s21_test_functions.c -L. s21_decimal.a $(ADD_LIB)
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_test_functions	
