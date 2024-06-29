#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double **allocate_matrix(int n, int m);
void free_matrix(double **matr);
double det(double **matrix, int n, int m);
void swap_rows(double **matr, int m, int i, int j);
int input(double ***matrix, int *n, int *m);
void output(double det);

int main(void) {
    int err = 0;
    double **matrix = NULL, d;
    int n, m;

    if (input(&matrix, &n, &m)) {
        printf("n/a");
        err = 1;
    } else {
        d = det(matrix, n, m);
        output(d);
        free_matrix(matrix);
    }

    return err;
}

double **allocate_matrix(int n, int m) {
    double **matr = malloc(n * sizeof(double *));
    double *data;
    if (matr) {
        data = malloc(n * m * sizeof(double));
        if (!data) free(matr);
    }

    if (matr) {
        for (int i = 0; i < n; i++) matr[i] = data + i * m;
    }

    return matr;
}

void free_matrix(double **matr) {
    free(matr[0]);
    free(matr);
}

int input(double ***matrix, int *n, int *m) {
    int err = 0;
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0 || *n != *m) err = 1;

    if (!err) {
        *matrix = allocate_matrix(*n, *m);
    }
    if (!err && *matrix) {
        for (int i = 0; i < *n; i++)
            for (int j = 0; j < *m; j++)
                if (scanf("%lf", &(*matrix)[i][j]) != 1) err = 1;
    }

    if (err && *matrix) free_matrix(*matrix);
    return err;
}

void output(double det) { printf("%.6lf", det); }

void swap_rows(double **matr, int m, int i, int j) {
    int temp;
    for (int k = 0; k < m; k++) {
        temp = matr[i][k];
        matr[i][k] = matr[j][k];
        matr[j][k] = temp;
    }
}

double det(double **matrix, int n, int m) {
    double det = 1.0, x;
    int swap_row;

    for (int i = 0; i < n; i++) {
        if (fabs(matrix[i][i]) < 1e-6) {
            swap_row = -1;
            for (int j = 0; j < m; j++) {
                if (j != i && fabs(matrix[i][j]) > 1e-6) {
                    swap_row = j;
                    break;
                }
            }
            if (swap_row != -1) {
                swap_rows(matrix, m, i, swap_row);
                det = -det;
            } else
                det = 0.0;
        }
        det *= matrix[i][i];
        for (int j = i + 1; j < n; j++) {
            x = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++) matrix[j][k] -= x * matrix[i][k];
        }
    }

    return det;
}
