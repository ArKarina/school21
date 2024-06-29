#include <stdio.h>
#include <stdlib.h>

#define N 100

int input_menu(int *choice);
int input_size(int *n, int *m);
int input1(int matr[N][N], int *n, int *m);
void output1(int matr[N][N], int n, int m);
int **allocate_matrix2(int n, int m);
void free_matrix2(int **matr, int n);
int **allocate_matrix3(int n, int m);
void free_matrix3(int **matr);
int **allocate_matrix4(int n, int m);
void free_matrix4(int **matr);
int input(int **matr, int n, int m);
void output(int **matr, int n, int m);
int input2(int ***matr, int *n, int *m);
int input3(int ***matr, int *n, int *m);
int input4(int ***matr, int *n, int *m);

void find_mins1(int matr[N][N], int n, int m, int *arr_min);
void find_maxs1(int matr[N][N], int n, int m, int *arr_max);
void find_maxs(int **matr, int n, int m, int *arr_max);
void find_mins(int **matr, int n, int m, int *arr_min);
void output_arr(int *a, int n);

int main(void) {
    int err = 0;
    int ch;
    if (input_menu(&ch)) err = 1;
    int n, m, matr1[N][N];
    int **matr;
    int arr_max[100];
    int arr_min[100];

    if (!err) {
        if (ch == 1) {
            if (input1(matr1, &n, &m)) {
                printf("n/a");
                err = 1;
            } else {
                output1(matr1, n, m);
                find_maxs1(matr1, n, m, arr_max);
                find_mins1(matr1, n, m, arr_min);
                printf("\n");
                output_arr(arr_max, m);
                printf("\n");
                output_arr(arr_min, n);
            }
        } else if (ch == 2) {
            if (input2(&matr, &n, &m)) {
                printf("n/a");
                err = 1;
            } else {
                output(matr, n, m);
                find_maxs(matr, n, m, arr_max);
                find_mins(matr, n, m, arr_min);
                printf("\n");
                output_arr(arr_max, m);
                printf("\n");
                output_arr(arr_min, n);
                free_matrix2(matr, n);
            }
        } else if (ch == 3) {
            if (input3(&matr, &n, &m)) {
                printf("n/a");
                err = 1;
            } else {
                output(matr, n, m);
                find_maxs(matr, n, m, arr_max);
                find_mins(matr, n, m, arr_min);
                printf("\n");
                output_arr(arr_max, m);
                printf("\n");
                output_arr(arr_min, n);
                free_matrix3(matr);
            }
        } else if (ch == 4) {
            if (input4(&matr, &n, &m)) {
                printf("n/a");
                err = 1;
            } else {
                output(matr, n, m);
                find_maxs(matr, n, m, arr_max);
                find_mins(matr, n, m, arr_min);
                printf("\n");
                output_arr(arr_max, m);
                printf("\n");
                output_arr(arr_min, n);
                free_matrix4(matr);
            }
        }
    }

    return err;
}

int input_menu(int *choice) {
    int err = 0;
    printf("Выберите метод выделения памяти:\n");
    printf("1. Статическое выделение памяти\n");
    printf("2. Динамическое выделение памяти с массивом указателей на строки\n");
    printf("3. Динамическое выделение памяти с массивом указателей и одним массивом для всех строк\n");
    printf("4. Динамическое выделение памяти с единым массивом\n");
    if (scanf("%d", choice) != 1 || *choice < 1 || *choice > 4) {
        err = 1;
    }
    return err;
}

int input_size(int *n, int *m) {
    int err = 0;
    if (scanf("%d", n) != 1 || *n <= 0) err = 1;
    if (scanf("%d", m) != 1 || *m <= 0) err = 1;

    return err;
}

int input1(int matr[N][N], int *n, int *m) {
    int err = 0;
    if (input_size(n, m) || *n > 100 || *m > 100) err = 1;

    if (!err) {
        for (int i = 0; i < *n; i++)
            for (int j = 0; j < *m; j++)
                if (scanf("%d", &matr[i][j]) != 1) err = 1;
    }

    return err;
}

void output1(int matr[N][N], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matr[i][j]);
            if (j < m - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }
}

int **allocate_matrix2(int n, int m) {
    int **matr = calloc(n, sizeof(int *));
    if (matr) {
        for (int i = 0; i < n; i++) {
            matr[i] = malloc(m * sizeof(int));
            if (!matr[i]) free_matrix2(matr, n);
        }
    }

    return matr;
}

void free_matrix2(int **matr, int n) {
    for (int i = 0; i < n; i++) {
        free(matr[i]);
    }
    free(matr);
}

int **allocate_matrix3(int n, int m) {
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

void free_matrix3(int **matr) {
    free(matr[0]);
    free(matr);
}

int **allocate_matrix4(int n, int m) {
    int **matr = malloc(n * sizeof(int *) + n * m * sizeof(int));
    int *data;

    if (matr) {
        data = (int *)(matr + n);
        for (int i = 0; i < n; i++) matr[i] = data + i * m;
    }

    return matr;
}

void free_matrix4(int **matr) { free(matr); }

int input(int **matr, int n, int m) {
    int err = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%d", &matr[i][j]) != 1) err = 1;

    return err;
}

void output(int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matr[i][j]);
            if (j < m - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }
}

int input2(int ***matr, int *n, int *m) {
    int err = 0;
    if (input_size(n, m)) err = 1;

    if (!err) {
        *matr = allocate_matrix2(*n, *m);
    }
    if (!err && *matr) {
        if (input(*matr, *n, *m)) err = 1;
    }

    if (err) free_matrix2(*matr, *n);
    return err;
}

int input3(int ***matr, int *n, int *m) {
    int err = 0;
    if (input_size(n, m)) err = 1;

    if (!err) {
        *matr = allocate_matrix3(*n, *m);
    }
    if (!err && *matr) {
        if (input(*matr, *n, *m)) err = 1;
    }

    if (err) free_matrix3(*matr);
    return err;
}

int input4(int ***matr, int *n, int *m) {
    int err = 0;
    if (input_size(n, m)) err = 1;

    if (!err) {
        *matr = allocate_matrix4(*n, *m);
    }
    if (!err && *matr) {
        if (input(*matr, *n, *m)) err = 1;
    }

    if (err) free_matrix4(*matr);
    return err;
}

void find_mins1(int matr[N][N], int n, int m, int *arr_min) {
    int min;
    for (int i = 0; i < n; i++) {
        min = matr[0][i];
        for (int j = 1; j < m; j++) {
            if (matr[j][i] < min) min = matr[j][i];
        }
        arr_min[i] = min;
    }
}

void find_maxs1(int matr[N][N], int n, int m, int *arr_max) {
    int max;
    for (int i = 0; i < n; i++) {
        max = matr[i][0];
        for (int j = 1; j < m; j++) {
            if (matr[i][j] > max) max = matr[i][j];
        }
        arr_max[i] = max;
    }
}

void find_maxs(int **matr, int n, int m, int *arr_max) {
    int max;
    for (int i = 0; i < n; i++) {
        max = matr[i][0];
        for (int j = 1; j < m; j++) {
            if (matr[i][j] > max) max = matr[i][j];
        }
        arr_max[i] = max;
    }
}

void find_mins(int **matr, int n, int m, int *arr_min) {
    int min;
    for (int i = 0; i < n; i++) {
        min = matr[0][i];
        for (int j = 1; j < m; j++) {
            if (matr[j][i] < min) min = matr[j][i];
        }
        arr_min[i] = min;
    }
}

void output_arr(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
}
