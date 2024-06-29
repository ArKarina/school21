#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];

    if (!input(data, &n)) {
        printf("n/a\n");
        return 1;
    }
    squaring(data, n);
    output(data, n);

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

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = *p * *p;
    }
}
