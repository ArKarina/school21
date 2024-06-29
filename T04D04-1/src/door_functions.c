#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846
#define N 42
#define Y 21

double verziera_agnesey(double x);
double lemniscata_bernoulli(double x);
double quadratic_hyperbole(double x);
void print_graph(double (*func)(double));

int main(void) {
    double x, y1, y2, y3;
    double step = (2.0 * PI) / (N - 1);

    for (int i = 0; i < N; i++) {
        x = -PI + i * step;
        y1 = verziera_agnesey(x);
        y2 = lemniscata_bernoulli(x);
        y3 = quadratic_hyperbole(x);

        if (isnan(y2))
            printf("%.7lf | %.7lf | - | %.7lf\n", x, y1, y3);
        else
            printf("%.7lf | %.7lf | %.7lf | %.7lf\n", x, y1, y2, y3);
    }

    printf("verziera_agnesey:\n");
    print_graph(verziera_agnesey);
    printf("\nlemniscata_bernoulli:\n");
    print_graph(lemniscata_bernoulli);
    printf("\nquadratic_hyperbole:\n");
    print_graph(quadratic_hyperbole);

    return 0;
}

double verziera_agnesey(double x) { return 1.0 / (1.0 + x * x); }

double lemniscata_bernoulli(double x) {
    double res = sqrt(sqrt(1.0 + 4.0 * x * x) - x * x - 1.0);

    if (isnan(res) || res < 0)
        return NAN;
    else
        return res;
}

double quadratic_hyperbole(double x) { return 1.0 / (x * x); }

void print_graph(double (*func)(double)) {
    double x, y;
    double max_y = 0;
    double step = (2.0 * PI) / (N - 1);

    for (int i = 0; i < N; i++) {
        x = -PI + i * step;
        y = func(x);
        if (!isnan(y) && fabs(y) > max_y) max_y = fabs(y);
    }

    for (int i = Y; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            x = -PI + j * step;
            y = func(x);
            if (!isnan(y)) {
                if (max_y * i / Y <= y && y < max_y * (i + 1) / Y)
                    printf("*");
                else
                    printf(" ");
            } else
                printf(" ");
        }
        printf("\n");
    }
}