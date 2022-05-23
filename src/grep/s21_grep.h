#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_


#define OPTIONS "e:ivclnhsf:o"
//#define OPTIONS "e:ivcln"

typedef struct {
    char *options;

    int argc;
    char *const *argv;

    int opt_e;                      /* -e PATTERN */
    char *opt_e_PATTERN;
    int opt_ignore_case;            /* -i */
    int opt_invert_match;           /* -v */
    int opt_count;                  /* -c */
    int opt_files_with_matches;     /* -l */
    int opt_line_number;            /* -n */

    int opt_no_filename;            /* -h */
    int opt_no_messages;            /* -s */
    int opt_file;                   /* -f FILE */
    char *opt_file_FILE;
    int opt_only_matching;          /* -o */

    char **patterns;

    int files_count;
    char *files[500];

    char line[500];
    int line_is_match;
} s21_data;

void s21_data_set_defaults(s21_data *setts);
int s21_data_set_opts(s21_data *setts);
int s21_data_line_is_match(s21_data *setts);


/* Debug */
#define DEBUG
#include <stdio.h>
#define LOG(...) { \
    fprintf(stderr, "==================================================LOG:");\
    fprintf(stderr, __VA_ARGS__); puts(""); fflush(stderr); \
}
void s21_data_print_data(const s21_data *setts);
#define LOG1(M, X) { \
    fprintf(stderr,   ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOG1\n"); \
    fprintf(stderr, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>\"%s\"\n", M); \
    s21_data_print_data(X); \
    fprintf(stderr,   "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<LOG1\n"); \
    fflush(stderr); \
}



#endif  // SRC_GREP_S21_GREP_H_
