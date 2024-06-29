/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
double mean(int *a, int n);
int find_num(int *a, int n);

int main(void) {
    int n, arr[NMAX];

    if (!input(arr, &n)) {
        printf("n/a\n");
        return 1;
    }
    printf("%d\n", find_num(arr, n));

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n > NMAX || *n <= 0) return 0;

    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) return 0;
    }
    return (getchar() == '\n');
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

int find_num(int *a, int n) {
    double mean_a = mean(a, n);
    double variance_a = variance(a, n);

    for (int *p = a; p - a < n; p++) {
        if (*p && *p % 2 == 0 && *p >= mean_a && *p <= mean_a + 3 * sqrt(variance_a)) return *p;
    }
    return 0;
}