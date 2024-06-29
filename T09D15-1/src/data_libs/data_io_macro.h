#ifndef DATA_IO_MACRO_H
#define DATA_IO_MACRO_H

#include <stdio.h>

#define INPUT_ARR(arr, n, format)                \
    ({                                           \
        int _input_arr_err = 0;                  \
        for (int i = 0; i < (n); i++) {          \
            if (scanf(format, &(arr)[i]) != 1) { \
                printf("n/a");                   \
                _input_arr_err = 1;              \
                break;                           \
            }                                    \
        }                                        \
        _input_arr_err;                          \
    })

#define PRINT_ARR(arr, n, format)       \
    do {                                \
        for (int i = 0; i < (n); i++) { \
            printf(format, (arr)[i]);   \
            if (i < (n)-1) printf(" "); \
        }                               \
    } while (0)

#endif
