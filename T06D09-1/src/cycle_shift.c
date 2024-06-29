#include <stdio.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void cycle_shift(int *a, int n, int n_shift);

int main(void) {
    int err = 0;
    int n;
    int arr[NMAX];

    if (!input(arr, &n)) {
        printf("n/a\n");
        err = 1;
    }

    int n_shift;
    if (!err) {
        if (scanf("%d", &n_shift) != 1 || getchar() != '\n') {
            printf("n/a\n");
            err = 1;
        }
    }

    if (!err) {
        cycle_shift(arr, n, n_shift);
        output(arr, n);
    }

    return err;
}

int input(int *a, int *n) {
    int err = 1;
    if (scanf("%d", n) != 1 || *n > NMAX || *n <= 0) err = 0;

    if (err) {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) err = 0;
        }
    }
    return err;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
}

void cycle_shift(int *a, int n, int n_shift) {
    n_shift = n_shift % n;
    if (n_shift < 0) n_shift = n + n_shift;
    int temp;

    for (int i = 0; i < n_shift; i++) {
        temp = a[0];
        for (int j = 0; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        a[n - 1] = temp;
    }
}
