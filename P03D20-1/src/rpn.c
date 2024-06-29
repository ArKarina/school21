#include "rpn.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

Token *to_rpn(Token *tokens, int tokens_num, int *rpn_num) {
    Token *rpn = malloc(MAX_LEN * sizeof(Token));
    *rpn_num = 0;

    Stack *stack = init(MAX_LEN);

    for (int i = 0; i < tokens_num; i++) {
        if (tokens[i].type == 'n') {
            rpn[(*rpn_num)++] = tokens[i];
        } else if (tokens[i].type == 'o') {
            if (tokens[i].data[0] == '(') {
                push(stack, i);
            } else if (tokens[i].data[0] == ')') {
                while (!is_empty(stack) && tokens[(int)stack->data[stack->top]].data[0] != '(') {
                    rpn[(*rpn_num)++] = tokens[(int)pop(stack)];
                }
                pop(stack);
            } else {  // +, -, *, /
                while (!is_empty(stack) &&
                       priority(tokens[(int)stack->data[stack->top]].data) >= priority(tokens[i].data)) {
                    rpn[(*rpn_num)++] = tokens[(int)pop(stack)];
                }
                push(stack, i);
            }
        } else if (tokens[i].type == 'f') {
            push(stack, i);
        }
    }

    while (!is_empty(stack)) {  // other elements from stack
        rpn[(*rpn_num)++] = tokens[(int)pop(stack)];
    }

    destroy(stack);
    return rpn;
}

double compute_function(Token *rpn, int rpn_num, double x) {
    Stack *stack = init(MAX_LEN);

    for (int i = 0; i < rpn_num; i++) {
        if (rpn[i].type == 'n') {
            if (strcmp(rpn[i].data, "x") == 0) {
                push(stack, x);
            } else {
                push(stack, atof(rpn[i].data));
            }
        } else if (rpn[i].type == 'o') {
            if (rpn[i].data[0] == '~') {
                double a = pop(stack);
                push(stack, -a);
            } else {
                double b = pop(stack);
                double a = pop(stack);
                push(stack, calc(a, b, rpn[i].data[0]));
            }
        } else if (rpn[i].type == 'f') {
            double a = pop(stack);
            push(stack, func(a, rpn[i].data));
        }
    }
    double result = pop(stack);
    destroy(stack);
    return result;
}

int priority(char *op) {
    int res = 0;
    if (!strcmp(op, "~")) {
        res = 5;
    } else if (!strcmp(op, "+") || !strcmp(op, "-")) {
        res = 2;
    } else if (!strcmp(op, "*") || !strcmp(op, "/")) {
        res = 3;
    } else if (is_func(op)) {
        res = 4;
    }
    return res;
}

double calc(double a, double b, char op) {
    double res = 0.0;
    if (op == '+') {
        res = a + b;
    } else if (op == '-') {
        res = a - b;
    } else if (op == '*') {
        res = a * b;
    } else if (op == '/') {
        res = a / b;
    }
    return res;
}

double func(double a, char *op) {
    double res = 0.0;
    if (!strcmp(op, "sin")) {
        res = sin(a);
    } else if (!strcmp(op, "cos")) {
        res = cos(a);
    } else if (!strcmp(op, "tan")) {
        res = tan(a);
    } else if (!strcmp(op, "sqrt")) {
        res = sqrt(a);
    } else if (!strcmp(op, "ln")) {
        res = log(a);
    }
    return res;
}
