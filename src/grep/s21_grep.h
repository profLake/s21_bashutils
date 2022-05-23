#ifndef SRC_GREP_S21_GREP_H_

//#define OPTIONS "eivclnhsfo"
#define OPTIONS "eivcln"

typedef struct {
    char **patterns;
    char *options;

    int opt_ignore_case;    /* -i */
    int opt_invert_match;   /* -v */
    int opt_count;  /* -c */
    int opt_files_with_matches;     /* -l */
    int opt_line_number;    /* -n */

    int opt_no_filename;    /* -h */
    int opt_no_messages;   /* -s */
    int opt_file;   /* -f */
    int opt_only_matching;  /* -o */

    char *opt_file_FILE;

    char *files[500];
    int files_count;
} s21_data;

int s21_data_set_args(s21_data *setts, char *argv[], int argc);


#endif  // SRC_GREP_S21_GREP_H_
