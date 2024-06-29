#include <stdio.h>

#include "s21_string.h"

#define MAX_TEXT_LEN 100

void text_process(char *str, int width);

int main(int argc, char *argv[]) {
    int err = 0;
    int n;
    char str[MAX_TEXT_LEN + 1];

    if (argc != 2 || s21_strcmp(argv[1], "-w")) {
        printf("n/a");
        err = 1;
    } else if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
        err = 1;
    }

    if (!err) {
        getchar();
        fgets(str, MAX_TEXT_LEN + 1, stdin);

        int len = s21_strlen(str);
        if (str[len - 1] == '\n') str[len - 1] = '\0';

        text_process(str, n);
    }

    return err;
}

void print_word_with_hyphen(char *word, int width) {
    int len = s21_strlen(word);
    int start = 0;
    while (start < len) {
        if (start + width < len) {
            printf("%.*s-\n", width - 1, word + start);
            start += width - 1;
        } else {
            printf("%s", word + start);
            start = len;
        }
    }
}

void text_process(char *str, int width) {
    char *words[MAX_TEXT_LEN / 2];
    int word_count = 0;

    char *word = s21_strtok(str, " ");
    while (word != NULL) {
        words[word_count++] = word;
        word = s21_strtok(NULL, " ");
    }

    int i = 0;
    while (i < word_count) {
        int line_len = 0;
        int start = i;

        while (i < word_count && line_len + (int)s21_strlen(words[i]) + (i - start) <= width) {
            if ((int)s21_strlen(words[i]) > width) {
                break;
            }
            line_len += s21_strlen(words[i]);
            i++;
        }

        if (i == start) {
            int len = s21_strlen(words[i]);
            while (len > width) {
                printf("%.*s-\n", width - 1, words[i]);
                words[i] += width - 1;
                len -= width - 1;
            }
            printf("%s", words[i]);
            i++;
        } else {
            if (i == word_count || line_len + (i - start - 1) == width) {
                for (int j = start; j < i; j++) {
                    if (j > start) printf(" ");
                    printf("%s", words[j]);
                }
            } else {
                int spaces = width - line_len;
                int gaps = i - start - 1;
                for (int j = start; j < i; j++) {
                    if (j > start) {
                        int space_count = gaps > 0 ? (spaces / gaps + (j - start <= spaces % gaps)) : 0;
                        for (int k = 0; k < space_count; k++) printf(" ");
                    }
                    printf("%s", words[j]);
                }
            }
        }
        if (i < word_count) printf("\n");
    }
}