#include <stdio.h>

#define LEN 100

int input(int *num);
void output(int *num, int n);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int compare(int *buff1, int len1, int *buff2, int len2);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
      * 2 длинных числа в виде массивов до 100 элементов
      * В один элемент массива нельзя вводить число > 9
    Вывод:
      * Результат сложения и разности чисел-массивов
    Пример:
      * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
        2 9

        1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
        1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main(void) {
    int num1[LEN], num2[LEN], res1[LEN], res2[LEN];

    int n1 = input(num1);
    if (!n1) {
        printf("n/a\n");
        return 1;
    }
    int n2 = input(num2);
    int n3 = 0, n4 = 0;

    if (!n2) {
        printf("n/a\n");
        return 1;
    }

    sum(num1, n1, num2, n2, res1, &n3);
    sub(num1, n1, num2, n2, res2, &n4);

    output(res1, n3);
    if (n4)
        output(res2, n4);
    else
        printf("n/a\n");

    return 0;
}

int input(int *num) {
    int i = 0;
    char ch1 = getchar();
    char ch2 = getchar();

    if (ch2 != '\n' && ch2 != ' ') {
        return 0;
    }
    while (ch2 != '\n') {
        if (!(ch1 >= '0' && ch1 <= '9') || ch2 != ' ') return 0;
        num[i++] = ch1 - '0';
        ch1 = getchar();
        ch2 = getchar();
    }
    if (!(ch1 >= '0' && ch1 <= '9')) return 0;
    num[i++] = ch1 - '0';
    return i;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int transfer = 0, sum = 0, x = 0;
    int i = len1 - 1;
    int j = len2 - 1;

    while (i >= 0 || j >= 0 || transfer) {
        sum = transfer;
        if (i >= 0) sum += buff1[i--];
        if (j >= 0) sum += buff2[j--];
        transfer = sum / 10;
        result[x++] = sum % 10;
    }
    *result_length = x;

    int temp;
    for (int k = 0; k < *result_length / 2; k++) {
        temp = result[k];
        result[k] = result[*result_length - k - 1];
        result[*result_length - k - 1] = temp;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    if (compare(buff1, len1, buff2, len2) == -1) {
        result_length = 0;
        return;
    }

    int transfer = 0, sub = 0, x = 0;
    int i = len1 - 1;
    int j = len2 - 1;

    while (i >= 0 || j >= 0) {
        if (j >= 0)
            sub = buff1[i] - buff2[j] - transfer;
        else
            sub = buff1[i] - transfer;

        if (sub < 0) {
            sub += 10;
            transfer = 1;
        } else
            transfer = 0;

        result[x++] = sub;
        i--;
        j--;
    }

    while (x > 1 && !result[x - 1]) x--;
    *result_length = x;

    int temp;
    for (int k = 0; k < *result_length / 2; k++) {
        temp = result[k];
        result[k] = result[*result_length - k - 1];
        result[*result_length - k - 1] = temp;
    }
}

int compare(int *buff1, int len1, int *buff2, int len2) {
    if (len1 < len2) return -1;
    if (len2 < len1) return 1;

    for (int i = 0; i < len1; i++) {
        if (buff1[i] < buff2[i]) return -1;
        if (buff2[i] < buff1[i]) return 1;
    }
    return 0;
}