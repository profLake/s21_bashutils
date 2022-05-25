#include "s21_grep.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int result = 0;
    s21_data setts;

    s21_data_set_defaults(&setts);
    setts.argc = argc;
    setts.argv = argv;
    setts.options = OPTIONS;
    setts.files[0] = ">";
    setts.files_count = 1;
    result = s21_data_set_opts(&setts);
    
    for (int i = 0; i < setts.files_count; i++) {
        FILE *curr_F;
        if (*setts.files[0] == '>') {
            curr_F = stdin;
        } else {
            curr_F = fopen(setts.files[i], "r");
            if (curr_F == NULL) {
                result = 2;
            }
        }
        
        setts.files_i = i;
        setts.files_i_is_printed = 0;
        setts.line_number = 0;

        while (result == 0 && fgets(setts.line, 500, curr_F)) {
            setts.line_number++;

            s21_str_del_newline(setts.line);
            LOG("main():while:current line:\t\t\t%s", setts.line);
            result = s21_data_line_is_match(&setts);
    
            if (result == 0)
                s21_data_print_output(&setts);
    
            memset(setts.line, 0, 500);
        }

        if (curr_F != stdin) {
            fclose(curr_F);
        }
    }

    s21_data_print_output(&setts);

    LOG("main():setts.files_count:\t\t%d", setts.files_count);
    LOG("main():end");
    LOG1("THE_END", &setts);

    s21_data_print_error(&setts, result);

    return result;
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
    printf("setts->opt_only_matching:\t\t%i\n", setts->opt_only_matching);
    puts("");
    printf("setts->patterns[0]:\t\t%s\n", setts->patterns[0]);
    puts("");
    printf("setts->line:\t\t%s\n", setts->line);
    printf("setts->line_is_match:\t\t%i\n", setts->line_is_match);
}
