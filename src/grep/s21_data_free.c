#include "s21_grep.h"
#include <stdlib.h>

int s21_data_free(s21_data *setts) {
    int result;
    int i;

    result = 0;
    i = 0;

    while (i < setts->patterns_count + 1) {
        LOG("s21_data_free():trying_to_free:\t\t%i<%s>", i, setts->patterns[i]);
        free(setts->patterns[i]);
        i++;
    }

    return result;
}
