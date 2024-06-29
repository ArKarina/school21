#include <stdio.h>

int sum(int a, int b);
int dif(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main() {
    int x, y;

    if (scanf("%d %d", &x, &y) != 2) {
        printf("n/a");
        return 1;
    }

    if (y)
        printf("%d %d %d %d", sum(x, y), dif(x, y), mul(x, y), div(x, y));
    else
        printf("%d %d %d n/a", sum(x, y), dif(x, y), mul(x, y));

    return 0;
}

int sum(int a, int b) {
    return a + b;
}

int dif(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}