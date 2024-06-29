#include <stdio.h>

int max(int a, int b);

int main() {
    int x, y;

    if (scanf("%d %d", &x, &y) != 2) {
        printf("n/a");
        return 1;
    }

    printf("%d", max(x, y));

    return 0;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
