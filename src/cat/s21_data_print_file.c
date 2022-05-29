#include "s21_cat.h"
#include <stdio.h>

int s21_data_print_file(s21_data *setts) {
    int result;
    int i;
    char *curr;
    FILE *curr_F;

    result = 0;
    //  setts->files_i_line_output_i = 0;
    /*      ... = 0 --- on NixOS you should not do it */
    setts->files_i_line_i = 0;
    i = setts->files_i;
    curr = setts->files[i];

    if (result == 0) {
        if (*curr == *STDIN_STR) {
            curr_F = stdin;
        } else {
            LOG("s21_data_print_file():fopen:\t\t%s", curr);
            curr_F = fopen(curr, "r");
        }
        if (curr_F == NULL) {
            result = 2;
        }

        LOG("s21_data_print_file():files_i_line_before_write:\t\t<%s>",
            setts->files_i_line);
        while (result == 0 && fgets(setts->files_i_line, BUFF_SIZE, curr_F)) {
            result = s21_data_files_i_print_line(setts);
        }

        if (curr_F && curr_F != stdin) {
            LOG("s21_data_print_file():fclose:\t\t%s", curr);
            fclose(curr_F);
            curr_F = NULL;
        }
    }


    return result;
}
