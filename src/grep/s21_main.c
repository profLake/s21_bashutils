#include "s21_grep.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    int result = 0;
    s21_data setts;

    s21_data_set_defaults(&setts);
    setts.argc = argc;
    setts.argv = argv;
    setts.options = OPTIONS;
    result = s21_data_set_opts(&setts);
    
    while (result == 0 && scanf("%499s", setts.line) != EOF) {
        result = s21_data_line_is_match(&setts);

        if (setts.line_is_match) {
            printf("line:%s\n", setts.line);
        }
    }

    LOG1("THE_END", &setts);
    return 0;
}












void s21_data_print_data(const s21_data *setts) {
    printf("setts->options: %s\n", setts->options);
    puts("");
    printf("setts->argc:\t\t%i\n", setts->argc);
    printf("setts->argv:\t\t%p\n", setts->argv);
    for (int i = 0; i < setts->argc; i++) {
        printf("\tsetts->argv[%i]:\t\t<%s>\n", i, setts->argv[i]);
    }
    puts("");
    printf("setts->opt_e:\t\t%i\n", setts->opt_e);
    printf("setts->opt_e_PATTERN:\t\t%s\n", setts->opt_e_PATTERN);
    printf("setts->opt_ignore_case:\t\t%i\n", setts->opt_ignore_case);
    printf("setts->opt_invert_match:\t\t%i\n", setts->opt_invert_match);
    printf("setts->opt_count:\t\t%i\n", setts->opt_count);
    printf("setts->opt_files_with_matches:\t\t%i\n",
            setts->opt_files_with_matches);
    printf("setts->opt_line_number:\t\t%i\n", setts->opt_files_with_matches);
    puts("");
    printf("setts->opt_no_filename:\t\t%i\n", setts->opt_no_filename);
    printf("setts->opt_no_messages:\t\t%i\n", setts->opt_no_messages);
    printf("setts->opt_file:\t\t%i\n", setts->opt_file);
    printf("setts->opt_file_FILE:\t\t%p\n", setts->opt_file_FILE);
    printf("setts->opt_only_matching:\t\t%i\n", setts->opt_only_matching);
    puts("");
    printf("setts->patterns:\t\t%p\n", setts->patterns);
    puts("");
    printf("setts->files_count:\t\t%i\n", setts->files_count);
    printf("setts->files:\t\t%p\n", setts->files);
    for (int i = 0; i < setts->files_count; i++) {
        printf("\tsetts->files[%i]:\t\t<%s>\n", i, setts->files[i]);
    }
    puts("");
    printf("setts->line:\t\t%s\n", setts->line);
    printf("setts->line_is_match:\t\t%i\n", setts->line_is_match);
}
