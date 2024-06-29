/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main(void) {
    int err = 0;
    int n;
    int arr[NMAX];

    input(arr, &n);

    if (!n) {
        printf("n/a\n");
        err = 1;
    }

    int num = 0;
    if (!err) {
        num = sum_numbers(arr, n);
        if (!num) {
            printf("n/a\n");
            err = 1;
        }
    }

    if (!err) {
        int res[NMAX];
        int n2 = find_numbers(arr, n, num, res);

        printf("%d\n", num);
        output(res, n2);
    }
    return err;
}

void input(int *buffer, int *length) {
    if (scanf("%d", length) != 1 || *length > NMAX || *length <= 0) {
        *length = 0;
    }

    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d", p) != 1) {
            *length = 0;
        }
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i < length - 1) printf(" ");
    }
    printf("\n");
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if ((buffer[i]) % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] && number % buffer[i] == 0) {
            numbers[j] = buffer[i];
            j++;
        }
    }
    return j;
}
