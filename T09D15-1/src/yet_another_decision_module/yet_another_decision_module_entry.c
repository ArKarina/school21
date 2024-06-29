#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main(void) {
    int err = 0;
    double *data = NULL;
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
        err = 1;
    } else
        data = malloc(n * sizeof(double));

    if (!err && data && input(data, n)) {
        err = 1;
        printf("n/a");
    }

    if (!err && data) {
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    }

    free(data);
    return err;
}
