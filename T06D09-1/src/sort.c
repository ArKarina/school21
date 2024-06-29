#include <stdio.h>

#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void sort(int *a, int n);

int main(void) {
    int err = 0;
    int n = NMAX;
    int arr[NMAX];

    if (!input(arr, n)) {
        printf("n/a\n");
        err = 1;
    }

    if (!err) {
        sort(arr, n);
        output(arr, n);
    }

    return err;
}

int input(int *a, int n) {
    int err = 1;
    for (int *p = a; p - a < n; p++)
        if (scanf("%d", p) != 1) err = 0;

    return err;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
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
