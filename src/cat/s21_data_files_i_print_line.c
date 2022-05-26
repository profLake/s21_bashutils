#include "s21_cat.h"
#include <ctype.h>
#include <string.h>

int s21_data_files_i_print_line(s21_data *setts) {
    int result;
    const char *p;
    size_t len_nl;
    int is_to_print;

    result = 0;

    p = setts->files_i_line;
    len_nl = strchr(p, '\n') - p;
    LOG("s21_data_files_i_print_line():line:\t\t<%.*s>", (int)len_nl, p);

    if (setts->opt_squeeze_blank
        && setts->files_i_line_wasblank
        && len_nl == 0) {
    } else {
        while (*p) {
            is_to_print = 1;
    
            if (setts->opt_show_nonprinting == 0) {
                if (isprint(*p) == 0) {
                    is_to_print = 1;
                }
            }
    
            if (is_to_print) {
                if (setts->opt_show_tabs) {
                    if (*p == '\t') {
                        printf(TAB_STR);
                        is_to_print = 0;
                    }
                }
                if (setts->opt_show_ends) {
                    if (*p == '\n') {
                        printf(END_SIGN_STR);
                    }
                }
                printf("%c", *p);
            }
            p++;
        }
    }

    if (len_nl == 0) {
        LOG("s21_data_files_i_print_line():line_was_blank");
        setts->files_i_line_wasblank = 1;
    } else {
        setts->files_i_line_wasblank = 0;
    }

    return result;
}
