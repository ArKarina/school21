#include <stdio.h>

#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void quick_sort(int *a, int n);
void q_sort(int *a, int left, int right);
void swap(int *a, int *b);
void heap_sort(int *a, int n);
void heap(int *a, int n, int i);

int main(void) {
    int err = 0;
    int n = NMAX;
    int arr[NMAX];

    if (!input(arr, n)) {
        printf("n/a\n");
        err = 1;
    }

    if (!err) {
        quick_sort(arr, n);
        output(arr, n);
        heap_sort(arr, n);
        output(arr, n);
    }

    return err;
}

int input(int *a, int n) {
    int err = 1;
    for (int *p = a; p - a < n; p++)
        if (scanf("%d", p) != 1) err = 0;

    return err;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
}

void quick_sort(int *a, int n) { q_sort(a, 0, n - 1); }

void q_sort(int *a, int start, int end) {
    if (start >= end) return;

    int left = start, right = end, middle = a[(left + right) / 2];

    while (left <= right) {
        while (a[left] < middle) left++;
        while (a[right] > middle) right--;

        if (left <= right) {
            swap(&a[left], &a[right]);
            left++;
            right--;
        }
    }

    q_sort(a, start, right);
    q_sort(a, left, end);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heap_sort(int *a, int n) {
    for (int i = n / 2; i >= 0; i--) heap(a, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        heap(a, i, 0);
    }
}

void heap(int *a, int n, int i) {
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[root]) root = left;
    if (right < n && a[right] > a[root]) root = right;

    if (root != i) {
        swap(&a[i], &a[root]);
        heap(a, n, root);
    }
}
