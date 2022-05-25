#include "s21_grep.h"
#include <unistd.h>
#include <stdio.h>

int s21_data_set_opts(s21_data *setts) {
    const int argc = setts->argc;
    char *const *argv = setts->argv;
    const char *options = setts->options;

    int result = 0;

    int opt;
    while ((opt = getopt(argc, argv, options)) != -1) {
        switch (opt) {
            case 'e':
                setts->opt_e = 1;
                setts->patterns[setts->patterns_i] = optarg;
                setts->patterns_i++;
                setts->patterns_count++;
                break;
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
                setts->patterns_file = optarg;
                break;
            case 'o':
                setts->opt_only_matching = 1;
                break;
            default:
                result = 1;
        }
    }

    if (result == 0) {
        if (optind < argc) {
            if (setts->opt_e == 0) {
                setts->patterns[setts->patterns_i] = argv[optind];
                setts->patterns_i++;
                setts->patterns_count++;
                optind++;
            }
        }
        int i = 0;
        while (optind < argc) {
            setts->files[i] = (char *)argv[optind];
            setts->files_count = i + 1;
            optind++;
            i++;
        }
        if (setts->files_count > 1) {
            setts->opt_with_filename = 1;
        }
    }

    return result;
}
