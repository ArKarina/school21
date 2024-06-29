#include "s21_string.h"

#include "string.h"

void s21_strlen_test() {
    const char *input[] = {"Hello, world!", "", "\0Hello, world!", " ", "рарара"};

    size_t res[] = {13, 0, 0, 1, 12};

    printf("s21_strlen_test\n");
    for (int i = 0; i < 5; i++) {
        size_t r = s21_strlen(input[i]);
        printf("Input: \"%s\", expected: %zu, result: %zu - %s\n", input[i], res[i], r,
               res[i] == r ? "SUCCESS" : "FAIL");
    }
}

void s21_strcmp_test() {
    const char *input1[] = {"Hello, world!", "He", "Hello", ""};
    const char *input2[] = {"Hello, world!", "Hello", "He", "\0Hello, world!"};
    int res[] = {0, -1, 1, 0};

    printf("s21_strcmp_test\n");
    for (int i = 0; i < 4; i++) {
        int r = s21_strcmp(input1[i], input2[i]);
        printf("Input: \"%s\" \"%s\", expected: %d, result: %d - %s\n", input1[i], input2[i], res[i], r,
               res[i] == r ? "SUCCESS" : "FAIL");
    }
}

void s21_strcpy_test() {
    char dest[50];
    const char *input1[] = {"Hello, world!", "He", "Hello\0Hello", ""};
    const char *res[] = {"Hello, world!", "He", "Hello", ""};

    printf("s21_strcpy_test\n");
    for (int i = 0; i < 4; i++) {
        char *r = s21_strcpy(dest, input1[i]);
        printf("Input: \"\" \"%s\", expected: \"%s\", result: \"%s\" - %s\n", input1[i], res[i], r,
               !s21_strcmp(res[i], r) ? "SUCCESS" : "FAIL");
    }
}

void s21_strcat_test() {
    char dest[50];
    const char *input1[] = {"Hello,", "He", "", "lala"};
    const char *input2[] = {" world!", "He", "Hello\0Hello", ""};
    const char *res[] = {"Hello, world!", "HeHe", "Hello", "lala"};

    printf("s21_strcat_test\n");
    for (int i = 0; i < 4; i++) {
        s21_strcpy(dest, input1[i]);
        char *r = s21_strcat(dest, input2[i]);
        printf("Input: \"%s\" \"%s\", expected: \"%s\", result: \"%s\" - %s\n", input1[i], input2[i], res[i],
               r, !s21_strcmp(res[i], r) ? "SUCCESS" : "FAIL");
    }
}

void s21_strchr_test() {
    const char *input1[] = {"Hello,", "NAwaNA", "", "lala"};
    const char input2[] = {'l', 'a', 'd', 'f'};
    char *res[] = {"llo,", "aNA", NULL, NULL};

    printf("s21_strchr_test\n");
    for (int i = 0; i < 4; i++) {
        char *r = s21_strchr(input1[i], input2[i]);
        printf("Input: \"%s\" \"%c\", expected: \"%s\", result: \"%s\" - %s\n", input1[i], input2[i], res[i],
               r, (res[i] == r || (res[i] && r && !s21_strcmp(res[i], r))) ? "SUCCESS" : "FAIL");
    }
}

void s21_strstr_test() {
    char *input1[] = {"Hello,", "NAwaNA", "", "lala"};
    const char *input2[] = {"ld", "Awa", "", "dodo"};
    char *res[] = {NULL, "AwaNA", "", NULL};

    printf("s21_strchr_test\n");
    for (int i = 0; i < 4; i++) {
        char *r = s21_strstr(input1[i], input2[i]);
        printf("Input: \"%s\" \"%s\", expected: \"%s\", result: \"%s\" - %s\n", input1[i], input2[i], res[i],
               r, (res[i] == r || (res[i] && r && !s21_strcmp(res[i], r))) ? "SUCCESS" : "FAIL");
    }
}

void s21_strtok_test() {
    char input1[][50] = {"Hello, world! This is test.", "aaa,,,bbb,,ccc", "a,b,c,d", "lala lala"};
    const char *input2[] = {" ,!.", ",", ",", "."};
    const char *res[][5] = {{"Hello", "world", "This", "is", "test"},
                            {"aaa", "bbb", "ccc", NULL, NULL},
                            {"a", "b", "c", "d", NULL},
                            {"lala lala", NULL, NULL, NULL, NULL}};

    printf("s21_strtok_test\n");
    for (int i = 0; i < 4; i++) {
        printf("Input: \"%s\" \"%s\"\n", input1[i], input2[i]);
        char *token = s21_strtok(input1[i], input2[i]);
        int j = 0;
        while (token) {
            printf("Expected: \"%s\", result: \"%s\" - %s\n", res[i][j], token,
                   res[i][j] && strcmp(res[i][j], token) == 0 ? "SUCCESS" : "FAIL");
            token = s21_strtok(NULL, input2[i]);
            j++;
        }
    }
}

int main(void) {
#ifdef STRLEN_TEST
    s21_strlen_test();
#endif
#ifdef STRCMP_TEST
    s21_strcmp_test();
#endif
#ifdef STRCPY_TEST
    s21_strcpy_test();
#endif
#ifdef STRCAT_TEST
    s21_strcat_test();
#endif
#ifdef STRCHR_TEST
    s21_strchr_test();
#endif
#ifdef STRSTR_TEST
    s21_strstr_test();
#endif
#ifdef STRTOK_TEST
    s21_strtok_test();
#endif
    return 0;
}
