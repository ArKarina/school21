#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char *start) {
    const char *end = start;

    while (*end != '\0') end++;
    return end - start;
}

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    if (*str1 - *str2 < 0)
        return -1;
    else
        return *str1 - *str2 > 0;
}

char *s21_strcpy(char *str1, const char *str2) {
    char *d = str1;
    while ((*d = *str2) != '\0') {
        d++;
        str2++;
    }
    return str1;
}

char *s21_strcat(char *str1, const char *str2) {
    char *d = str1;
    while (*d) d++;

    while ((*d = *str2)) {
        d++;
        str2++;
    }
    return str1;
}

char *s21_strchr(const char *str, int ch) {
    char *d = (char *)str;
    while (*d) {
        if (*d == ch) return d;
        d++;
    }
    return NULL;
}

char *s21_strstr(char *str1, const char *str2) {
    if (!*str2) return str1;

    for (char *d = str1; *d; d++) {
        char *d1 = d;
        char *d2 = (char *)str2;

        while (*d && *d2 && (*d == *d2)) {
            d++;
            d2++;
        }
        if (!*d2) return d1;

        d = d1;
    }

    return NULL;
}

char *s21_strtok(char *str, const char *sep) {
    static char *last = NULL;
    if (str) last = str;
    if (!last) return NULL;

    while (*last && s21_strchr(sep, *last)) last++;
    if (!*last) return NULL;

    char *token = last;
    while (*last && !s21_strchr(sep, *last)) last++;
    if (*last) *last++ = '\0';

    return token;
}
