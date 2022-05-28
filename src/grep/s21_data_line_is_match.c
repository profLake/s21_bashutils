#include "s21_grep.h"
#include <regex.h>
#include <string.h>
#include <ctype.h>

int s21_data_line_is_match(s21_data *setts) {
    const char *line = setts->line;
    const int opt_ignore_case = setts->opt_ignore_case;
    const char **patterns = (const char **)setts->patterns;
    const int patterns_count = setts->patterns_count;
    const int opt_invert_match = setts->opt_invert_match;
    int* line_is_match_p = &setts->line_is_match;
    int *line_is_match_count_p = &setts->line_is_match_count;
    int *line_inner_matches_pp = (int *)setts->line_inner_matches;
    int *line_inner_matches_count_p = &setts->line_inner_matches_count;


    int result;
    int eflags;
    regex_t regex;
    int offset;
    int i;
    regmatch_t regex_matches[1];

    *line_is_match_p = 0;
    memset(line_inner_matches_pp, 0, BUFF_SIZE*2);
    *line_inner_matches_count_p = 0;
    result = 0;
    i = 0;

    eflags = REG_NEWLINE;
    if (opt_ignore_case)
        eflags |= REG_ICASE;

    for (int p = 0; p < patterns_count; p++) {
        LOG("s21_data_line_is_match():startcycle:pattern:\t\t%s", patterns[p]);
        if (regcomp(&regex, patterns[p], eflags)) {
            result = -1;
            LOG("s21_data_line_is_match():ERROR:regcomp_with:\t\t%s", patterns[p]);
        }
        if (result == 0) {
            offset = 0;
            while (regexec(&regex, line + offset, 1, regex_matches, 0) == 0) {
                line_inner_matches_pp[i*2 + 0] = offset
                        + regex_matches[0].rm_so;
                line_inner_matches_pp[i*2 + 1] = offset
                        + regex_matches[0].rm_eo;
                *line_inner_matches_count_p += 1;
                offset += regex_matches[0].rm_eo;
                i++;
                LOG("s21_data_line_is_match():found")
            }
        }
        LOG("s21_data_line_is_match():endcycle")
    }
    if ((i > 0 && opt_invert_match == 0)
        || (i == 0 && opt_invert_match)) {
        *line_is_match_p = 1;
        *line_is_match_count_p += 1;
        LOG("s21_data_line_is_match():issuit:i:\t\t%d", i)
        LOG("s21_data_line_is_match():issuit:opt_invert_match:\t\t%d",
            opt_invert_match)
    }

    return result;
}
