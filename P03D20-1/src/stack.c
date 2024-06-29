#include "stack.h"

#include <stdlib.h>

Stack *init(int n) {
    Stack *stack = malloc(sizeof(Stack));

    if (stack) {
        stack->data = malloc(n * sizeof(double));
        if (!stack->data) {
            free(stack);
            stack = NULL;
        }
    }

    if (stack) {
        stack->n = n;
        stack->top = -1;
    }

    return stack;
}

int push(Stack *stack, double num) {
    int err = 0;
    if (stack->top == stack->n - 1)
        err = 1;
    else {
        stack->data[++stack->top] = num;
    }
    return err;
}

double pop(Stack *stack) {
    double num = 0.0;
    if (stack->top == -1)
        num = 0.0;
    else {
        num = stack->data[stack->top];
        stack->top--;
    }
    return num;
}

void destroy(Stack *stack) {
    free(stack->data);
    free(stack);
}

int is_empty(Stack *stack) { return stack->top == -1; }
