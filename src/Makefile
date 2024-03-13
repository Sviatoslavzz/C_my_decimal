CC = gcc
CFLAGS = -Wall -Wextra -Werror -g --std=c11
OBJ_DIR = objects/
SOURCE = $(wildcard *.c) # get list all *.c
OBJECT = $(patsubst %.c, %.o, $(SOURCE))  # replace .c -> .o (making object files)
SOURCE_TEST = $(wildcard tests/*.c)
OBJECT_LIBRARY = $(patsubst %.c, %.o, $(SOURCE))
EXECUTABLE = test
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS += -DLinux
	GFLAGS = -lcheck_pic -lm -lsubunit
	RM_COMMAND = rm -rf test*.gcda test*.gcno
endif

ifeq ($(UNAME), Darwin)
	CFLAGS += -DDarwin
	GFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lcheck -lm
	RM_COMMAND = rm test*.gcda test*.gcno
endif

.PHONY: all my_decimal.a test gcov_report style clang clean rebuild valgrind_test cppcheck_test

all: clean my_decimal.a test gcov_report

my_decimal.a: clean $(OBJECT_LIBRARY)
	@ar rc my_decimal.a $(OBJECT_LIBRARY)
	@ranlib my_decimal.a
	@rm -rf *.o

test: clean my_decimal.a
	@$(CC) $(CFLAGS) $(SOURCE_TEST) my_decimal.a -o $(EXECUTABLE) $(GFLAGS)
	@./$(EXECUTABLE)

gcov_report: clean
	@$(CC) $(CFLAGS) $(SOURCE) $(SOURCE_TEST) -o $(EXECUTABLE) $(GFLAGS) --coverage 
	@./$(EXECUTABLE)
	@lcov -t "tests" -o tests.info -c -d . -rc lcov_branch_coverage=1 --exclude "$(PWD)/tests/*"
	@genhtml -o report tests.info -rc lcov_branch_coverage=1
	@rm -rf *.gcno *.gcda *.gcov

style: clean
	@cp ../materials/linters/.clang-format ./
	@cp ../materials/linters/.clang-format ./tests/
	@clang-format -n *.c tests/*.c
	@clang-format -n *.h tests/*.h
	@rm -rf .clang-format tests/.clang-format

clang: clean
	@cp ../materials/linters/.clang-format ./
	@cp ../materials/linters/.clang-format ./tests/
	@clang-format -i *.c tests/*.c
	@clang-format -i *.h tests/*.h
	@rm -rf .clang-format tests/.clang-format

clean:
	@rm -f *.o *.a *.gcno *.gcda *.info $(EXECUTABLE) valgrind_out.txt main
	@rm -rf report $(OBJ_DIR)

rebuild: clean my_decimal.a test

valgrind_test: rebuild
	valgrind -s -q --tool=memcheck --leak-check=yes --track-origins=yes --show-leak-kinds=all --verbose --log-file=valgrind_out.txt ./$(EXECUTABLE)

cppcheck_test:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h tests/*.c tests/*.h
