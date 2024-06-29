#include <stdio.h>

int max_prime_divisor(int n);
int is_div(int n, int x);
int is_prime(int n);

int main(void) {
    int x;

    if (scanf("%d", &x) != 1) {
        printf("n/a\n");
        return 1;
    }

    int res = max_prime_divisor(x);
    if (res)
        printf("%d\n", res);
    else
        printf("n/a\n");

    return 0;
}

int max_prime_divisor(int n) {
    int max = 0;

    if (n < 0) n = -n;

    for (int i = 2; i <= n; i++) {
        if (is_div(n, i) && is_prime(i) && i > max) max = i;
    }
    return max;
}

int is_div(int n, int x) {
    while (n > 0) {
        n = n - x;
    }
    return n == 0;
}

int is_prime(int n) {
    if (n < 2) return 0;

    for (int i = 2; i * i <= n; i++) {
        if (is_div(n, i)) return 0;
    }

    return 1;
}