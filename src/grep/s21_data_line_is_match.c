#include "s21_grep.h"
#include <regex.h>

int s21_data_line_is_match(s21_data *setts) {
    const char *line = setts->line;
    const char *e_PATTERN = setts->opt_e_PATTERN;
    int* line_is_match = &setts->line_is_match;

    int result = 0;


    regex_t regex;
    regmatch_t pmatch[1];

    if (regcomp(&regex, e_PATTERN, REG_NEWLINE)) {
        result = -1;
    }

    if (result == 0) {
        if (regexec(&regex, line, 1, pmatch, 0)) {
            LOG1("NO (line, e_PATTERN, *line_is_match)", setts);
            result = -2;
        }
    }
    
    if (result == 0) {
        *line_is_match = 1;
    } else {
        *line_is_match = 0;
    }

    return result;
}
