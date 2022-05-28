#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>

#define OPTIONS "bvEensTt"
#define STDIN_STR ">"
#define TAB_STR "^I"
#define END_SIGN_STR "$"
#define N_WIDTH 6
#define BUFF_SIZE 500

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

    char *files[BUFF_SIZE];
    int files_count;
    int files_i;
    char files_i_line[BUFF_SIZE];
    int files_i_line_count;
    int files_i_linenonemp_count;
    int files_i_line_wasblank;
    int files_i_line_output_i;
    int files_i_line_i;
    int files_i_line_i_nonblank;
    int files_i_line_i_istoprint;
} s21_data;

void s21_data_set_defaults(s21_data *setts);
int s21_data_set_opts(s21_data *setts);
int s21_data_print_file(s21_data *setts);
int s21_data_files_i_print_line(s21_data *setts);
int s21_data_set_files_i_line(s21_data *setts);


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
