#include <stdio.h>
#include <stdlib.h>

int allocate_arr(int **a, int n);
void free_arr(int *a);
int input(int **a, int *n);
void output(int *a, int n);
void sort(int *a, int n);

int main(void) {
    int err = 0;
    int n;
    int *arr = NULL;

    if (input(&arr, &n)) {
        printf("n/a");
        err = 1;
    }

    if (!err) {
        sort(arr, n);
        output(arr, n);
        free_arr(arr);
    }

    return err;
}

int allocate_arr(int **a, int n) {
    int err = 0;
    *a = (int *)calloc(n, sizeof(int));

    if (*a == NULL) err = 1;

    return err;
}

void free_arr(int *a) {
    if (a) {
        free(a);
        a = NULL;
    }
}

int input(int **a, int *n) {
    int err = 0;
    if (scanf("%d", n) != 1 || *n <= 0) err = 1;
    if (!err && allocate_arr(a, *n)) err = 1;

    if (!err) {
        for (int *p = *a; p - *a < *n; p++)
            if (scanf("%d", p) != 1) {
                err = 1;
            }
    }
    if (err) {
        free_arr(*a);
    }
    return err;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
}

void sort(int *a, int n) {
    int temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
}
