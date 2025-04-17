CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++20
TST_LIBS=-lgtest -lm -g
GCOV_LIBS=--coverage
SOURCES=s21_matrix_oop.cpp
GCOVFLAGS=-fprofile-arcs -ftest-coverage
HTML_CREATE=lcov --no-external -t a.out -o rep.info -c -d .; genhtml -o report rep.info
LTEST=-lgtest
BUILD_PATH=./
LIBO=s21_matrix_oop.o
LIBA=s21_matrix_oop.a
EXE=s21_matrix_tests

all: s21_matrix_oop.a test

clean:
	rm -rf *.o *.g* *.info *.out report *.a s21_matrix_tests *.log

test: s21_matrix_oop.a
	$(CC) s21_matrix_tests.cpp s21_matrix_oop.a $(LTEST) -o s21_matrix_tests
	./s21_matrix_tests

gcov_report: s21_matrix_oop.a
	$(CC) $(CFLAGS) $(GCOV_LIBS) s21_matrix_tests.cpp $(SOURCES) $(LIBA) -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)
	lcov --ignore-errors mismatch -t $(EXE) -c -d $(BUILD_PATH) --output-file $(BUILD_PATH)coverage.info
	lcov --extract $(BUILD_PATH)coverage.info "*/src/s21_matrix_oop.cpp" --output-file $(BUILD_PATH)coverage_filtered.info
	genhtml $(BUILD_PATH)coverage_filtered.info --output-directory $(BUILD_PATH)report/
	xdg-open report/index.html


s21_matrix_oop.a:
	$(CC) $(CFLAGS) -c $(SOURCES) -o $(BUILD_PATH)$(LIBO)
	ar rcs $(LIBA) $(LIBO)
	ranlib $(LIBA)

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i *.cpp *.h
	rm .clang-format

clang_check:
	cp ../materials/linters/.clang-format .
	clang-format -n *.cpp *.h
	rm .clang-format

leaks_check: s21_matrix_oop.a
	valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./s21_matrix_tests