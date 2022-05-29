#include "s21_grep.h"
#include <stdlib.h>

int s21_data_free(s21_data *setts) {
    int result;
    int i;

    LOG("s21_data_free():start");
    result = 0;
    i = 0;

    while (setts->patterns[i]) {
        LOG("s21_data_free():trying_to_free:\t\t%i<%p>", i, setts->patterns[i]);
        free(setts->patterns[i]);
        i++;
    }

    return result;
}
