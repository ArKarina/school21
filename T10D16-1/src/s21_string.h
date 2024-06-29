#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>

size_t s21_strlen(const char *start);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *str1, const char *str2);
char *s21_strcat(char *str1, const char *str2);
char *s21_strchr(const char *str, int ch);
char *s21_strstr(char *str1, const char *str2);
char *s21_strtok(char *str, const char *sep);

#endif
