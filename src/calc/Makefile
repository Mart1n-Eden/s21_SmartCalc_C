CC = gcc
EFLAGS = -std=c11 -Wall -Wextra -Werror 
CFLAGS = -c #$(EFLAGS)
OFLAGS = $(EFLAGS) -o
TEST_FLAGS = -lcheck -lm
# CFLAGS = -c -D_THREAD_SAFE -I/opt/homebrew/Cellar/check/0.15.2/include
# OFLAGS = $(EFLAGS) -D_THREAD_SAFE -I/opt/homebrew/Cellar/check/0.15.2/include -L/opt/homebrew/Cellar/check/0.15.2/lib -o
# TEST_FLAGS = -D_THREAD_SAFE -I/opt/homebrew/Cellar/check/0.15.2/include -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck -lm -lpthread

ifeq ($(shell uname), Linux)
	TEST_FLAGS += -lpthread -lrt -lsubunit
endif

all: install

build:
	mkdir calculator
	cd calculator && cmake -B build "../" && make -C build calc

install: clean build
	mkdir ~/Desktop/calculator/
	cp -rf calculator ~/Desktop/calculator/
	make clean

uninstall:
	rm -rf ~/Desktop/calculator/

test: clean
	$(CC) $(OFLAGS) test main.c smart_calc.c $(TEST_FLAGS)
	./test

gcov_report: clean
	$(CC) $(EFLAGS) --coverage main.c smart_calc.c -o test $(TEST_FLAGS)
	rm -rf *.o *.a
	./test
	gcov *.gcno
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

valgrind:
	$(CC) $(EFLAGS) main.c smart_calc.c -o test $(TEST_FLAGS) -g
	rm -rf *.o *.a
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test

	# CK_FORK=no leaks --atExit -- ./test

dist:
	rm -rf ../Archive/
	mkdir ../Archive/
	cp -r ../calc/ ../Archive/
	# cp ../dvi.html ../Archive/
	tar -C ../ -czvf Archive.tgz Archive/
	mv Archive.tgz ~/Desktop/
	rm -rf ../Archive/

style:
	cp ../../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.h *.cpp
	rm .clang-format

dvi:
	open ../dvi.html

clean:
	rm -rf *.o *.a test tgtests *.gcda *.gcno *.gcov *.html *.css *.ou a.out
	rm -rf *.o functions/*.o functions/specificators/*.o tests/*.o
	rm -rf report/ *.info
	rm -rf calculator
