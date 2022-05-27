#include "s21_cat.h"
#include <ctype.h>

int s21_data_files_i_print_line(s21_data *setts) {
    int result;
    int istoprint;
    int c_istoprint;
    const char *p;

    result = s21_data_set_files_i_line(setts);
    istoprint = setts->files_i_line_i_istoprint;
    p = setts->files_i_line;


    if (result == 0 && istoprint) {
        if (setts->opt_number_nonblank) {
            if (setts->files_i_line_i_nonblank) {
                printf("%*d  ", N_WIDTH, setts->files_i_line_output_i);
            }
        }
        if (setts->opt_number) {
            printf("%*d  ", N_WIDTH, setts->files_i_line_output_i);
        }
    
        while (*p) {
            c_istoprint = 1;
    
            if (setts->opt_show_nonprinting == 0) {
                if (isprint(*p) == 0) {
                    c_istoprint = 1;
                    /*  **** You should to set 0 here */
                }
            }
    
            if (c_istoprint) {
                if (setts->opt_show_tabs) {
                    if (*p == '\t') {
                        printf(TAB_STR);
                        c_istoprint = 0;
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

    return result;
}
