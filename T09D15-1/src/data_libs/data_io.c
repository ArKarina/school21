#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

int input(double *data, int n) {
    int err = 0;
    for (int i = 0; i < n; i++)
        if (scanf("%lf", &data[i]) != 1) err = 1;

    return err;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i < n - 1) printf(" ");
    }
}
