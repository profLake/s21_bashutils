#include "s21_grep.h"

#include <unistd.h>

int s21_data_set_args(s21_data *setts, char *argv[], int argc) {
    int result = 0;

    int opt;
    while ((opt = getopt(argc, argv, setts->options)) != -1) {
        switch (opt) {
            case 'i':
                setts->opt_ignore_case = 1;
                break;
            case 'v':
                setts->opt_invert_match = 1;
                break;
            case 'c':
                setts->opt_count = 1;
                break;
            case 'l':
                setts->opt_files_with_matches = 1;
                break;
            case 'n':
                setts->opt_line_number = 1;
                break;
            case 'h':
                setts->opt_no_filename = 1;
                break;
            case 's':
                setts->opt_no_messages = 1;
                break;
            case 'f':
                setts->opt_file = 1;
                break;
            case 'o':
                setts->opt_only_matching = 1;
                break;
            default:
                result = 1;
        }
    }

    if (optind >= argc) {
        setts->files_count = argc - optind;
        for (int i = 0; i <= optind; i++) {
            setts->files[i] = argv[i + optind];
        }
    }

    return result;
}
