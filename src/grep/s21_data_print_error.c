#include "s21_grep.h"

int s21_data_print_error(s21_data *setts, int error) {
    int result = 0;

    if (setts->opt_no_messages == 0) {
        if (error == 1) {
        }
        if (error == 2) {
            fprintf(stderr, "grep: %s: No such file or directory\n",
                setts->file_not_found);
        }
    }

    return result;
}
