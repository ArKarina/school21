#include "data_process.h"

#include <math.h>

#include "../data_libs/data_stat.h"

int normalization(double *data, int n) {
    int result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = max_value - min_value;

    if (fabs(size) < EPS) {
        result = 0;
    } else {
        for (int i = 0; i < n; i++) {
            data[i] = data[i] / size - min_value / size;
        }
    }

    return result;
}

void sort(double *data, int n) {
    int temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
}
