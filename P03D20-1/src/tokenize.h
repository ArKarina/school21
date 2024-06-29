#ifndef TOKENIZE_H
#define TOKENIZE_H

#define MAX_LEN 256

typedef struct Token {
    char data[32];
    char type;
} Token;

Token *tokenize(char expression[MAX_LEN], int *count);
int is_digit(char ch);
int is_alpha(char ch);
int is_func(char *str);

#endif
