#include "data_stat.h"

double max(double *data, int n) {
    double max = data[0];

    for (double *p = data + 1; p - data < n; p++) {
        if (*p > max) max = *p;
    }

    return max;
}

double min(double *data, int n) {
    double min = data[0];

    for (double *p = data + 1; p - data < n; p++) {
        if (*p < min) min = *p;
    }

    return min;
}

double mean(double *data, int n) {
    double sum = 0.0;

    for (double *p = data; p - data < n; p++) {
        sum += *p;
    }

    return sum / n;
}

double variance(double *data, int n) {
    double sum = 0.0;
    double mean_a = mean(data, n);

    for (double *p = data; p - data < n; p++) {
        sum += ((*p - mean_a) * (*p - mean_a));
    }

    return sum / n;
}
