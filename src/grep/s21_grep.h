#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <stdio.h>
#include <regex.h>

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
    int opt_count_n;
    int opt_files_with_matches;     /* -l */
    int opt_line_number;            /* -n */

    int opt_no_filename;            /* -h */
    int opt_no_messages;            /* -s */
    int opt_file;                   /* -f FILE */
    char *opt_file_FILE;
    int opt_only_matching;          /* -o */

    char *pattern;
    char *file;
    FILE *file_F;

    FILE *src;

    //int last_result;

    char line[500];
    int line_is_match;

    //int regex_flags;
    regmatch_t regex_matches[500];
} s21_data;

void s21_data_set_defaults(s21_data *setts);
int s21_data_set_opts(s21_data *setts);
int s21_data_line_is_match(s21_data *setts);
int s21_data_print_output(s21_data *setts);


/* Debug */
#include <string.h>
#define str_del_newline(str) \
    str[strlen(str) - 1] = strchr(str, '\n') ? '\0' : str[strlen(str) - 1];
#define DEBUG
#include <stdio.h>
#define LOG(...) { \
    fprintf(stdout, "========================================LOG:");\
    fprintf(stdout, __VA_ARGS__); puts(""); \
    fflush(stdout); \
}
void s21_data_print_data(const s21_data *setts);
#define LOG1(M, X) { \
    fprintf(stdout, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOG1\n"); \
    fprintf(stdout, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>\"%s\"\n", M); \
    s21_data_print_data(X); \
    fprintf(stdout, "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<LOG1\n"); \
    fflush(stdout); \
}
/*
#define LOG2(M, FS) { \
    fprintf(stderr, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOG1\n"); \
    fprintf(stderr, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>\"%s\"\n", M); \
    fprintf(stderr, "FS:\t", 
    fprintf(stderr, "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<LOG1\n"); \
    fflush(stderr); \
} */



#endif  // SRC_GREP_S21_GREP_H_
