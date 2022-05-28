#include "s21_cat.h"

int main(int argc, char *argv[]) {
    int result;
    s21_data setts;

    result = 0;

    s21_data_set_defaults(&setts);
    setts.options = OPTIONS;
    setts.argc = argc;
    setts.argv = argv;
    setts.files[0] = STDIN_STR;
    setts.files_count = 1;
    result = s21_data_set_opts(&setts);
    /*  s21_data_set_opts() --- overrides stdin if at least 1 file is present */


    if (result == 0) {
        while (result == 0 && setts.files_i < setts.files_count) {
            LOG("main():cycle:start")
            result = s21_data_print_file(&setts);
            setts.files_i++;
            LOG("main():cycle:end_of_body")
        }
    }

    return result;
}
