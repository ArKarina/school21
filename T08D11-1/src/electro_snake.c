#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

int **allocate_matrix(int n, int m);
void free_matrix(int **matr);
int input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
void sort(int *a, int n);

int main(void) {
    int err = 0;
    int **matrix = NULL, **result = NULL;
    int n, m;

    if (input(&matrix, &n, &m)) {
        printf("n/a");
        err = 1;
    } else
        result = allocate_matrix(n, m);

    if (!err && result) {
        sort_vertical(matrix, n, m, result);
        output(result, n, m);

        sort_horizontal(matrix, n, m, result);
        printf("\n\n");
        output(result, n, m);
        free_matrix(matrix);
        free_matrix(result);
    }

    return err;
}

int **allocate_matrix(int n, int m) {
    int **matr = malloc(n * sizeof(int *));
    int *data;
    if (matr) {
        data = malloc(n * m * sizeof(int));
        if (!data) free(matr);
    }

    if (matr) {
        for (int i = 0; i < n; i++) matr[i] = data + i * m;
    }

    return matr;
}

void free_matrix(int **matr) {
    free(matr[0]);
    free(matr);
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

    if (err && *matrix) free_matrix(*matrix);
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

void sort(int *a, int n) {
    int temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int *arr = (int *)malloc(n * m * sizeof(int));
    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[x++] = matrix[i][j];
        }
    }

    sort(arr, x);

    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) result_matrix[i][j] = arr[y++];
        } else {
            for (int i = n - 1; i >= 0; i--) result_matrix[i][j] = arr[y++];
        }
    }
    free(arr);
    arr = NULL;
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int *arr = (int *)malloc(n * m * sizeof(int));
    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[x++] = matrix[i][j];
        }
    }

    sort(arr, x);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) result_matrix[i][j] = arr[y++];
        } else {
            for (int j = m - 1; j >= 0; j--) result_matrix[i][j] = arr[y++];
        }
    }
    free(arr);
    arr = NULL;
}
