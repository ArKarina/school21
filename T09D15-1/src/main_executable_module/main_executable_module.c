#include <stdio.h>
#include <stdlib.h>

#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

#ifdef MACRO_IO
#include "../data_libs/data_io_macro.h"
#else
#include "../data_libs/data_io.h"
#endif

int main(void) {
    int err = 0;
    double *data = NULL;
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("ERROR");
        err = 1;
    } else
        data = malloc(n * sizeof(double));

    if (!err && data) printf("LOAD DATA...\n");

#ifdef MACRO_IO
    if (!err && data && INPUT_ARR(data, n, "%lf")) {
        err = 1;
        printf("ERROR");
    }
    if (!err && data) {
        printf("RAW DATA:\n\t");
        PRINT_ARR(data, n, "%lf");

        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        PRINT_ARR(data, n, "%lf");

        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, n);
        PRINT_ARR(data, n, "%lf");

        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    }
#else
    if (!err && data && input(data, n)) {
        err = 1;
        printf("ERROR");
    }
    if (!err && data) {
        printf("RAW DATA:\n\t");
        output(data, n);

        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        output(data, n);

        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, n);
        output(data, n);

        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    }
#endif

    free(data);
    return err;
}
