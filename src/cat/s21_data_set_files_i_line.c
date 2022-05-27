#include "s21_cat.h"
#include <string.h>

int s21_data_set_files_i_line(s21_data *setts) {
    int result;
    const char *p;
    size_t len_nl;

    result = 0;

    p = setts->files_i_line;
    len_nl = strchr(p, '\n') - p;
    LOG("s21_data_files_i_print_line():line:\t\t<%.*s>", (int)len_nl, p);

    setts->files_i_line_i_istoprint = 1;
    setts->files_i_line_i++;
    setts->files_i_line_i_nonblank = 0;
    if (len_nl > 0) {
        setts->files_i_line_i_nonblank = 1;
    }

    if (setts->opt_squeeze_blank
        && setts->files_i_line_wasblank
        && len_nl == 0) {
        setts->files_i_line_i_istoprint = 0;
    }
    
    if (len_nl == 0) {
        setts->files_i_line_wasblank = 1;
        LOG("s21_data_files_i_print_line():line_was_blank");
    } else {
        setts->files_i_line_wasblank = 0;
    }

    if (setts->files_i_line_i_istoprint) {
        if (setts->opt_number
                || (setts->opt_number_nonblank && len_nl)) {
            setts->files_i_line_output_i++;
        }
    }


    return result;
}
