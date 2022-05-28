#include "s21_cat.h"
#include <ctype.h>

int s21_data_files_i_print_line(s21_data *setts) {
    int result;
    int istoprint;
    const char *p;

    result = s21_data_set_files_i_line(setts);
    istoprint = setts->files_i_line_i_istoprint;
    p = setts->files_i_line;


    if (result == 0 && istoprint) {
        if (setts->opt_number_nonblank) {
            if (setts->files_i_line_i_nonblank) {
                printf("%*d\t", N_WIDTH, setts->files_i_line_output_i);
            }
        }
        if (setts->opt_number) {
            printf("%*d\t", N_WIDTH, setts->files_i_line_output_i);
        }

        while (*p) {
            if (setts->opt_show_nonprinting) {
                if (*p == 0) {
                    printf("^@");
                }
                if (*p < 32 && *p != '\n' && *p != '\t') {
                    printf("^%c", 'A' + *p);
                }
                if (*p == 127) {
                    printf("^?");
                }
            }
            if (setts->opt_show_ends) {
                if (*p == '\n') {
                    printf(END_SIGN_STR);
                }
            }
            if (*p >= 32 && *p != 127) {
                printf("%c", *p);
            }
            p++;
        }
    }

    return result;
}
