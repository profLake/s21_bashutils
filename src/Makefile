#
#   Если хочешь знать, как это работает, загляни в
#       https://habr.com/ru/post/155201/.
#   Если этого мало, отведай https://stackoverflow.com/questions/2734719/
#       how-to-compile-a-static-library-in-linux
#

CC=gcc
CFLAGS=-Wall -Wextra -Werror -D DEBUG_
LDFLAGS=
GREP_SOURCES=$(wildcard ./grep/s21_*.c)
GREP_OBJECTS=$(GREP_SOURCES:.c=.o)
GREP_EXE=./grep/s21_grep
CAT_SOURCES=$(wildcard ./cat/s21_*.c)
CAT_OBJECTS=$(CAT_SOURCES:.c=.o)
CAT_EXE=./cat/s21_cat

##TEST_SOURCES=./test.c
##CLIBS=-lm $(shell pkg-config --cflags --libs check)


all: clean grep cpplint


%.o: %.c ./grep/s21_grep.h
	$(CC) -c $(CFLAGS) $< -o $@


$(GREP_EXE): $(GREP_OBJECTS)
	clear
	$(CC) $^ -o $@


$(CAT_EXE): $(CAT_OBJECTS)
	clear
	$(CC) $^ -o $@


s21_grep: $(GREP_EXE)


s21_cat: $(CAT_EXE)


s21_grep_test: clean s21_grep
	#########################################################MINE:
	$(GREP_EXE) for s21_main.c ./grep/s21_main.c -n; exit 0
	########################################################RIGHT:
	       grep for s21_main.c ./grep/s21_main.c -n; exit 0
	#############################################################:


s21_cat_test: clean $(CAT_EXE)
	########################################################RIGHT:
	       cat -n -b ./sometext.txt > cat.out
	#########################################################MINE:
	$(CAT_EXE) -n -b ./sometext.txt > s21_cat.out


clean:
	find ./ \( -iname "*.gcda" \
		-or -iname "*.gcov" \
		-or -iname "*.gcno" \
		-or -iname "*.out" \
		-or -iname "*.o" \
		-or -iname "*.a" \
		-or -iname "*.html" \
		-or -iname "*.info" \
		-or -iname "*.css" \
		-or -iname "*.png" \
		-or -wholename $(GREP_EXE) \
		-or -type d -name  ".DS_Store" \
	\) -exec mv {} /tmp/ \;

	####	Directories


cpplint:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c \
        ./*.c \
    	./*.h


valgrind: ./unit_tests.out
	valgrind \
		-s \
		--track-origins=yes \
		--show-leak-kinds=all \
		./unit_tests.out; exit 0;
	#valgrind \
    #   -s \
	#	--leak-check=full \
	#	--leak-resolution=med \
	#	--log-file=RESULT_VALGRIND.txt \
	#	./unit_tests.out
	#valgrind \
	#	--show-leak-kinds=all \
	#	--track-origins=no \
	#	--log-file=RESULT_VALGRIND.txt \
	#	-s \
	#	./unit_tests.out
		#--leak-check=full --- "each individual leak will be shown in detail"
		#--show-leak-kinds=all --- Show all of "definite, indirect, possible,
		#   reachable" leak kinds in the "full" report.
		#--track-origins=yes --- Favor useful output over speed. This tracks
		#   the origins of uninitialized values, which could be very useful for
		#   memory errors. Consider turning off if Valgrind is unacceptably
		#   slow.
		#--verbose: Can tell you about unusual behavior of your program. Repeat
		#   for more verbosity.
		#--log-file: Write to a file. Useful when output exceeds terminal space.


cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES)

