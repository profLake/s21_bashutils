#include "s21_grep.h"
#include <stdio.h>

int s21_data_print_output(s21_data *setts) {
    int result = 0;

    if (setts->line[0]) {
        if (setts->line_is_match) {
            if (setts->opt_with_filename) {
                printf("%s:", setts->files[setts->files_i]);
            }
            if (setts->opt_count == 0) {
                if (setts->opt_only_matching == 0) {
                    printf("%s\n", setts->line);
                } else {
                    int i = 0;
                    int start;
                    int end;
                    int len;
                    LOG("s21_data_print_output():line_inner_matches_count:\t\t%d",
                        setts->line_inner_matches_count)
                    while (i < setts->line_inner_matches_count) {
                        start = setts->line_inner_matches[i][0];
                        end = setts->line_inner_matches[i][1];
                        len = end - start;
                        printf("%.*s\n", len, setts->line + start);
                        i++;
                        LOG("s21_data_print_output():start:\t\t%d", start);
                        LOG("s21_data_print_output():end:\t\t%d", end);
                    }
                }
            }
        }
    } else {
        if (setts->opt_count) {
            printf("%d\n", setts->line_is_match_count);
        }
    }

    return result;
}
