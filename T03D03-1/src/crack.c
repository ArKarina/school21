#include <stdio.h>

double check_lock(double x, double y);

int main() {
    double x, y;

    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("n/a");
        return 1;
    }

    if (check_lock(x, y))
        printf("GOTCHA");
    else
        printf("MISS");

    return 0;
}

double check_lock(double x, double y) {
    return x * x + y * y < 25;
}
