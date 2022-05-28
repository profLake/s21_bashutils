#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <stdio.h>
#include <regex.h>

#define OPTIONS "e:ivclnhsf:o"

typedef struct {
    char *options;

    int argc;
    char *const *argv;

    int opt_e;                      /* -e PATTERN */
    int opt_ignore_case;            /* -i */
    int opt_invert_match;           /* -v */
    int opt_count;                  /* -c */
    int opt_files_with_matches;     /* -l */
    int opt_line_number;            /* -n */

    int opt_no_filename;            /* -h */
    int opt_no_messages;            /* -s */
    int opt_file;                   /* -f FILE */
    int opt_only_matching;          /* -o. May be exluded by -v */

    int opt_with_filename;          /* -H (optional). May be exluded by -l */

    char *patterns[500];
    int patterns_count;
    int patterns_i;
    char *patterns_file;

    char *files[500];
    int files_count;
    int files_i;
    int files_i_is_printed;

    char *file_not_found;

    char line[500];
    int line_is_match;
    int line_is_match_count;
    int line_inner_matches[500][2];
    int line_inner_matches_count;
    int line_number;
} s21_data;

void s21_data_set_defaults(s21_data *setts);
int s21_data_set_opts(s21_data *setts);
int s21_data_line_is_match(s21_data *setts);
int s21_data_print_output(s21_data *setts);
int s21_data_set_file_patterns(s21_data *setts);
int s21_data_free(s21_data *setts);
int s21_data_print_error(s21_data *setts, int error);
#define s21_str_del_newline(str) \
    str[strlen(str) - 1] = strchr(str, '\n') \
        ? '\0' : str[strlen(str) - 1];
#define s21_str_alloc_same(str) \
    calloc(strlen(str), sizeof(*str));

/* Debug */
#define STDERR stderr

#ifdef DEBUG
#include <stdio.h>
#define LOG(...) { \
    fprintf(STDERR, "========================================LOG:");\
    fprintf(STDERR, __VA_ARGS__); puts(""); \
    fflush(STDERR); \
}
void s21_data_print_data(const s21_data *setts);
#define LOG1(M, X) { \
    fprintf(STDERR, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOG1\n"); \
    fprintf(STDERR, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>\"%s\"\n", M); \
    s21_data_print_data(X); \
    fprintf(STDERR, "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<LOG1\n"); \
    fflush(STDERR); \
}
/*
#define LOG2(M, FS) { \
    fprintf(stderr, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOG1\n"); \
    fprintf(stderr, ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>\"%s\"\n", M); \
    fprintf(stderr, "FS:\t", 
    fprintf(stderr, "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<LOG1\n"); \
    fflush(stderr); \
} */

#else

#define LOG(...) {}
#define LOG1(M, X) {}
#define LOG2(M, FS) {}

#endif  // Debug


#endif  // SRC_GREP_S21_GREP_H_
