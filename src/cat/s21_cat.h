#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>

#define OPTIONS "bvEensTt"
#define STDIN_STR ">"
#define TAB_STR "^I"
#define END_SIGN_STR "$"

typedef struct {
    char *options;

    int argc;
    char *const *argv;

    int opt_number_nonblank;    /* -b, --number-nonblank */
    int opt_show_nonprinting;   /* -v */
    int opt_show_ends;          /* -E */
                                /* -e. The same as -Ev */
    int opt_number;             /* -n, --number. May be excluded by -b */
    int opt_squeeze_blank;      /* -s, squeeze-blank */
    int opt_show_tabs;          /* -T */
                                /* -t. The same as -Tv */

    char *files[500];
    int files_count;
    int files_i;
    char files_i_line[500];
    int files_i_line_count;
    int files_i_linenonemp_count;
    int files_i_line_wasblank;
} s21_data;

void s21_data_set_defaults(s21_data *setts);
int s21_data_set_opts(s21_data *setts);
int s21_data_print_file(s21_data *setts);
int s21_data_files_i_print_line(s21_data *setts);


/* Debug */
#define STDERR stdout

#ifdef DEBUG
#include <stdio.h>
#define LOG(...) { \
    fprintf(STDERR, "========================================LOG:");\
    fprintf(STDERR, __VA_ARGS__); puts(""); \
    fflush(STDERR); \
}
#else
#define LOG(...) {}
#endif  // DEBUG


#endif  // SRC_CAT_S21_CAT_H_
