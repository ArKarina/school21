#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "data_process.h"

int main(void) {
    int err = 0;
    double *data = NULL;
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("ERROR");
        err = 1;
    } else
        data = malloc(n * sizeof(double));

    if (!err && data && input(data, n)) {
        err = 1;
        printf("ERROR");
    }

    if (!err && data) {
        if (normalization(data, n))
            output(data, n);
        else
            printf("ERROR");
    }
    free(data);
    return err;
}
