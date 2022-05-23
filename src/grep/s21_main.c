#include "s21_grep.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    s21_data setts;
    s21_data_set_args(&setts, argv, argc);
    printf("setts.opt_ignore_case: %d\n", setts.opt_ignore_case);

    return 0;
}
