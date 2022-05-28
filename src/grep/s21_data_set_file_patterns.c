#include "s21_grep.h"
#include <stdlib.h>
#include <string.h>

int s21_data_set_file_patterns(s21_data *setts) {
    int result;
    FILE *patts_F;
    int i;

    LOG("s21_data_set_file_patterns():patternsfile_handling:\t\t%s", setts->patterns_file);
    result = 0;
    patts_F = fopen(setts->patterns_file, "r");
    if (patts_F == NULL) {
        setts->file_not_found = setts->patterns_file;
        result = 2;
    }

    if (result == 0) {
        i = setts->patterns_i;

        if (setts->patterns[i] == NULL) {
            setts->patterns[i] = calloc(BUFF_SIZE, sizeof(char));
        }
        while (fgets(setts->patterns[i], BUFF_SIZE, patts_F)) {
            s21_str_del_newline(setts->patterns[i]);
            LOG("s21_data_set_file_patterns():file_pattern_written:\t\t%i,%s",
                i, setts->patterns[i]);
            i++;
            setts->patterns_count++;
            setts->patterns[i] = calloc(BUFF_SIZE, sizeof(char));
        }

        setts->patterns_i = i;
    }

    if (patts_F) {
        fclose(patts_F);
    }
    LOG("s21_data_set_file_patterns():patterns_count:\t\t%d", setts->patterns_count)

    return result;
}
