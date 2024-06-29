#include <stdio.h>

int fibonacci(int n);

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        printf("n/a\n");
        return 1;
    }

    int res = fibonacci(n);
    if (res)
        printf("%d\n", res);
    else
        printf("n/a\n");

    return 0;
}

int fibonacci(int n) {
    if (n < 1) return 0;
    if (n == 1 || n == 2) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}