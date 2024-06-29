#include "tokenize.h"

#include <stdlib.h>
#include <string.h>

Token *tokenize(char expression[MAX_LEN], int *tokens_num) {
    Token *tokens = malloc(MAX_LEN * sizeof(Token));
    *tokens_num = 0;
    int i = 0;

    while (tokens && expression[i] != '\0') {
        if (is_digit(expression[i]) || expression[i] == '.' || expression[i] == 'x') {
            int j = 0;
            while (is_digit(expression[i]) || expression[i] == '.' || expression[i] == 'x') {
                tokens[*tokens_num].data[j++] = expression[i++];
            }
            tokens[*tokens_num].data[j] = '\0';
            tokens[*tokens_num].type = 'n';
            (*tokens_num)++;
        } else if (strchr("+-*/()", expression[i])) {
            if (expression[i] == '-' && (!(*tokens_num) || tokens[*tokens_num - 1].data[0] == '(')) {
                tokens[*tokens_num].data[0] = '~';
                i++;
            } else {
                tokens[*tokens_num].data[0] = expression[i++];
            }
            tokens[*tokens_num].data[1] = '\0';
            tokens[*tokens_num].type = 'o';
            (*tokens_num)++;
        } else if (is_alpha(expression[i])) {
            int j = 0;
            while (is_alpha(expression[i])) {
                tokens[*tokens_num].data[j++] = expression[i++];
            }
            tokens[*tokens_num].data[j] = '\0';
            tokens[*tokens_num].type = 'f';
            if (!is_func(tokens[*tokens_num].data)) {
                free(tokens);
                tokens = NULL;
            }
            (*tokens_num)++;
        } else if (expression[i] == ' ') {
            i++;
        } else {
            free(tokens);
            tokens = NULL;
        }
    }

    return tokens;
}

int is_digit(char ch) { return (ch >= '0' && ch <= '9'); }

int is_alpha(char ch) { return (ch >= 'a' && ch <= 'z'); }

int is_func(char *str) {
    return (!strcmp(str, "sin") || !strcmp(str, "cos") || !strcmp(str, "tan") || !strcmp(str, "ctg") ||
            !strcmp(str, "sqrt") || !strcmp(str, "ln"));
}
