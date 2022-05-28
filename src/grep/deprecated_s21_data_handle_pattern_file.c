#include "s21_grep.h"
#include <stdio.h>
#include <stdlib.h>

/*
int s21_data_handle_pattern_file(s21_data *setts) {
    int result = 0;

    FILE *file_F;
    int i;

    file_F = fopen(setts->patterns_file, "r");
    if (file_F == NULL) {
        result = 1;
    }

    i = setts->patterns_count;
    setts->patterns[i] = calloc(BUFF_SIZE, 1);
    while (result == 0 && fgets(setts->patterns[i], BUFF_SIZE, file_F)) {
        i++;
        setts->patterns[i] = calloc(BUFF_SIZE, 1);
    }
    setts->patterns_count = i;

    if (file_F) {
        fclose (file_F);
    }

    return result;
}
*/
