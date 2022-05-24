#include "s21_grep.h"
#include <regex.h>
#include <string.h>
#include <ctype.h>

int s21_data_line_is_match(s21_data *setts) {
    const char *line = setts->line;
    const int opt_ignore_case = setts->opt_ignore_case;
    const char *e_PATTERN = setts->opt_e_PATTERN;
    const char *pattern = setts->pattern;
    int* line_is_match_p = &setts->line_is_match;
    regmatch_t *regex_matches = setts->regex_matches;
    int *opt_count_n_p = &setts->opt_count_n;


    int result = 0;
    *line_is_match_p = 0;


    regex_t regex;
    int eflags;
    eflags = REG_NEWLINE;
    if (opt_ignore_case) {
        eflags |= REG_ICASE;
    }
    if (e_PATTERN) {
        if (regcomp(&regex, e_PATTERN, eflags)) {
            result = -1;
        }
        if (result == 0) {
            if (regexec(&regex, line, 1, regex_matches, 0)) {
            } else {
                *line_is_match_p = 1;
                *opt_count_n_p += 1;
            }
        }
    }
    if (pattern) {
        LOG("s21_data_line_is_match():pattern:\t\t\t%s", pattern);
        if (regcomp(&regex, pattern, eflags)) {
            result = -1;
        }
        if (result == 0) {
            if (regexec(&regex, line, 1, regex_matches, 0)) {
            } else {
                *line_is_match_p = 1;
                *opt_count_n_p += 1;
            }
        }
    }

    return result;
}
