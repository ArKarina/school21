#include <stdio.h>
#include <stdlib.h>

int input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
int transpose(int ***matrix, int *n, int *m);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
int **allocate_matrix(int n, int m);
void free_matrix(int **matr);

int main(void) {
    int err = 0, mode;
    int n1, m1, **matr1 = NULL;
    int n2, m2, **matr2 = NULL;
    int n3, m3, **matr3 = NULL;

    if (scanf("%d", &mode) != 1 || mode < 1 || mode > 3) {
        printf("n/a");
        err = 1;
    }
    if (!err && input(&matr1, &n1, &m1)) {
        printf("n/a");
        err = 1;
    }
    if (!err && (mode == 1 || mode == 2)) {
        if (input(&matr2, &n2, &m2)) {
            printf("n/a");
            err = 1;
        } else {
            matr3 = allocate_matrix(n1, m1);
            if (!matr3) {
                printf("n/a");
                err = 1;
            }
        }
    }
    if (!err && mode == 1) {
        if (sum(matr1, n1, m1, matr2, n2, m2, matr3, &n3, &m3)) {
            printf("n/a");
            err = 1;
        }
    } else if (!err && mode == 2) {
        if (mul(matr1, n1, m1, matr2, n2, m2, matr3, &n3, &m3)) {
            printf("n/a");
            err = 1;
        }
    } else if (!err && mode == 3) {
        if (transpose(&matr1, &n1, &m1)) {
            printf("n/a");
            err = 1;
        }
    }

    if (!err && (mode == 1 || mode == 2))
        output(matr3, n3, m3);
    else if (!err)
        output(matr1, n1, m1);

    free_matrix(matr1);
    free_matrix(matr2);
    free_matrix(matr3);

    return err;
}

int input(int ***matrix, int *n, int *m) {
    int err = 0;
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0) err = 1;

    if (!err) {
        *matrix = allocate_matrix(*n, *m);
    }
    if (!err && *matrix) {
        for (int i = 0; i < *n; i++)
            for (int j = 0; j < *m; j++)
                if (scanf("%d", &(*matrix)[i][j]) != 1) err = 1;
    }

    if (err) free_matrix(*matrix);
    return err;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j < m - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }
}

int **allocate_matrix(int n, int m) {
    int **matr = malloc(n * sizeof(int *) + n * m * sizeof(int));
    int *data;

    if (matr) {
        data = (int *)(matr + n);
        for (int i = 0; i < n; i++) matr[i] = data + i * m;
    }

    return matr;
}

void free_matrix(int **matr) { free(matr); }

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    int err = 0;
    if (n_first != n_second || m_first != m_second) err = 1;

    if (!err) {
        *n_result = n_first;
        *m_result = m_first;

        for (int i = 0; i < n_first; i++)
            for (int j = 0; j < m_first; j++) matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
    }
    return err;
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    int err = 0;
    if (m_first != n_second)
        err = 1;
    else {
        *n_result = n_first;
        *m_result = m_second;

        for (int i = 0; i < *n_result; i++) {
            for (int j = 0; j < *m_result; j++) {
                matrix_result[i][j] = 0;
                for (int k = 0; k < m_first; k++) {
                    matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
                }
            }
        }
    }
    return err;
}

int transpose(int ***matrix, int *n, int *m) {
    int err = 0;
    int **temp = allocate_matrix(*m, *n);
    if (!temp)
        err = 1;
    else {
        for (int i = 0; i < *n; i++) {
            for (int j = 0; j < *m; j++) {
                temp[j][i] = (*matrix)[i][j];
            }
        }
        free_matrix(*matrix);
        *matrix = temp;

        int tmp = *n;
        *n = *m;
        *m = tmp;
    }

    return err;
}
