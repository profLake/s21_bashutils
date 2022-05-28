#include "s21_cat.h"
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>

int s21_data_set_opts(s21_data *setts) {
    const int argc = setts->argc;
    char *const *argv = setts->argv;
    const char *options = setts->options;
    int result;
    int opt;
    static struct option long_options[] = {
        {"number-nonblank", no_argument,   0,  'b' },
        {"number",          no_argument,   0,  'n' },
        {"squeeze-blank",   no_argument,   0,  's' },
        {0,                 no_argument,   0,  0 }
    };

    result = 0;

    while (1) {
        opt = getopt_long(argc, argv, options, long_options, NULL);
        if (opt == -1) {
            break;
        }
        switch (opt) {
            case 'b':
                setts->opt_number = 0;
                setts->opt_number_nonblank = 1;
                break;
            case 'v':
                setts->opt_show_nonprinting = 1;
                break;
            case 'E':
                setts->opt_show_ends = 1;
                break;
            case 'e':
                setts->opt_show_ends = 1;
                setts->opt_show_nonprinting = 1;
                break;
            case 'n':
                if (setts->opt_number_nonblank == 0) {
                    setts->opt_number = 1;
                }
                break;
            case 's':
                setts->opt_squeeze_blank = 1;
                break;
            case 'T':
                setts->opt_show_tabs = 1;
                break;
            case 't':
                setts->opt_show_tabs = 1;
                setts->opt_show_nonprinting = 1;
                break;
            default:
                LOG("s21_data_set_opts():invalid_arg:\t\t%c", opt)
                result = 1;
        }
    }


    if (result == 0) {
        int i;

        i = 0;
        while (optind < argc) {
            setts->files[i] = (char *)argv[optind];
            optind++;
            i++;
            setts->files_count = i;
        }
    }

    return result;
}
