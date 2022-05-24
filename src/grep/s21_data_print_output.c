#include "s21_grep.h"
#include <stdio.h>

int s21_data_print_output(s21_data *setts) {
    int result = 0;

    if (setts->line[0]) {
        if (setts->opt_count == 0) {
            if (setts->opt_only_matching == 0) {
                printf("%s\n", setts->line);
            } else {
                regmatch_t *match_p = setts->regex_matches;
                char *s = setts->line;
                int len;

                for (int i = 0; match_p[i].rm_so != -1; i++) {
                    len = match_p[i].rm_eo - match_p[i].rm_so;
                    printf("%.*s\n", len, s + match_p[i].rm_so);
                }
            }
        }
    } else {
        if (setts->opt_count) {
            printf("%d\n", setts->opt_count_n);
        }
    }

    return result;
}
