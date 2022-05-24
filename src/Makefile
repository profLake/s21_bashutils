#
#   Если хочешь знать, как это работает, загляни в
#       https://habr.com/ru/post/155201/.
#   Если этого мало, отведай https://stackoverflow.com/questions/2734719/
#       how-to-compile-a-static-library-in-linux
#

CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=
GREP_SOURCES=$(wildcard ./grep/s21_*.c)
GREP_OBJECTS=$(GREP_SOURCES:.c=.o)
GREP_EXE=./grep/grep

##TEST_SOURCES=./test.c
##CLIBS=-lm $(shell pkg-config --cflags --libs check)


all: clean grep cpplint


%.o: %.c ./grep/s21_grep.h
	$(CC) -c $(CFLAGS) $< -o $@


$(GREP_EXE): $(GREP_OBJECTS)
	clear
	$(CC) $^ -o $(GREP_EXE)


s21_grep: $(GREP_EXE)


test: s21_grep
	clear
	echo "hello\nYES\nyes\nheYlo\nyye\nHEILO" \
		| $(GREP_EXE) -i -e he.lo -s E the_File
	######################################################################
	######################################################################
	######################################################################
	echo "yes" | $(GREP_EXE) -i e
	######################################################################
	######################################################################
	######################################################################
	$(GREP_EXE) "reg....()" ./sometext.txt
	######################################################################
	######################################################################
	######################################################################
	$(GREP_EXE) -c "reg....()" ./sometext.txt


clean:
#	find ./ \( -iname "*.gcda" \
#		-or -iname "*.gcov" \
#		-or -iname "*.gcno" \
#		-or -iname "*.out" \
#		-or -iname "*.o" \
#		-or -iname "*.a" \
#		-or -iname "*.html" \
#		-or -iname "*.info" \
#		-or -iname "*.css" \
#		-or -iname "*.png" \
#	\) -delete
#
	####	Directories
	mv -t /tmp/ ./tests/src/ \
		./.DS_Store/ \
		./src/ \
		./usr/ \
		./unit_tests.out.dSYM/ \
        ./gcc_extra_test_logs.txt \
		$(GREP_EXE) \


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

