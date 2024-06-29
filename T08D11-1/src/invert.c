#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double **allocate_matrix(int n, int m);
void free_matrix(double **matr);
int input(double ***matrix, int *n, int *m);
void output(double **matrix, int n, int m);
void swap_rows(double **matr, int m, int i, int j);
int invert_matrix(double ***matrix, int n);

int main(void) {
    int err = 0;
    double **matrix = NULL;
    int n, m;

    if (input(&matrix, &n, &m)) {
        printf("n/a");
        err = 1;
    } else {
        if (invert_matrix(&matrix, n)) {
            printf("n/a");
            err = 1;
            free_matrix(matrix);
        }
    }
    if (!err) {
        output(matrix, n, m);
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

void output(double **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.6lf", matrix[i][j]);
            if (j < m - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }
}

void swap_rows(double **matr, int m, int i, int j) {
    int temp;
    for (int k = 0; k < m; k++) {
        temp = matr[i][k];
        matr[i][k] = matr[j][k];
        matr[j][k] = temp;
    }
}

int invert_matrix(double ***matrix, int n) {
    int err = 0;
    double **temp = allocate_matrix(n, 2 * n);
    if (!temp)
        err = 1;
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = (*matrix)[i][j];
                if (i == j)
                    temp[i][j + n] = 1.0;
                else
                    temp[i][j + n] = 0.0;
            }
        }

        for (int i = 0; i < n; i++) {
            if (fabs(temp[i][i]) < 1e-6) {
                int swap_row = -1;
                for (int j = i + 1; j < n; j++) {
                    if (fabs(temp[j][i]) > 1e-6) {
                        swap_row = j;
                        break;
                    }
                }
                if (swap_row == -1) {
                    free_matrix(temp);
                    err = 1;
                    return err;
                }
                swap_rows(temp, i, swap_row, 2 * n);
            }

            double ii = temp[i][i];
            for (int j = 0; j < 2 * n; j++) temp[i][j] /= ii;

            for (int j = 0; j < n; j++) {
                if (i != j) {
                    double row_factor = temp[j][i];
                    for (int k = 0; k < 2 * n; k++) temp[j][k] -= row_factor * temp[i][k];
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) (*matrix)[i][j] = temp[i][j + n];

        free_matrix(temp);
    }

    return err;
}