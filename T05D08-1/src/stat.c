#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];

    if (!input(data, &n)) {
        printf("n/a\n");
        return 1;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n > NMAX || *n <= 0) return 0;

    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) return 0;
    }
    return (getchar() == '\n');
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

int max(int *a, int n) {
    int max = a[0];

    for (int *p = a + 1; p - a < n; p++) {
        if (*p > max) max = *p;
    }

    return max;
}

int min(int *a, int n) {
    int min = a[0];

    for (int *p = a + 1; p - a < n; p++) {
        if (*p < min) min = *p;
    }

    return min;
}

double mean(int *a, int n) {
    double sum = 0.0;

    for (int *p = a; p - a < n; p++) {
        sum += *p;
    }

    return sum / n;
}

double variance(int *a, int n) {
    double sum = 0.0;
    double mean_a = mean(a, n);

    for (int *p = a; p - a < n; p++) {
        sum += ((*p - mean_a) * (*p - mean_a));
    }

    return sum / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf\n", max_v, min_v, mean_v, variance_v);
}