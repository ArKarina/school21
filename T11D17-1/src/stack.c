#include "stack.h"

#include <stdlib.h>

struct stack *init(int n) {
    struct stack *stack = malloc(sizeof(struct stack));
    if (!stack) {
        return NULL;
    }

    stack->data = malloc(n * sizeof(int));
    if (!stack->data) {
        free(stack);
        return NULL;
    }

    stack->n = n;
    stack->top = -1;
    return stack;
}

int push(struct stack *stack, int num) {
    int err = 0;
    if (stack->top == stack->n - 1)
        err = 1;
    else {
        stack->data[++stack->top] = num;
    }
    return err;
}

int pop(struct stack *stack, int *num) {
    int err = 0;
    if (stack->top == -1)
        err = 1;
    else {
        *num = stack->data[stack->top--];
    }
    return err;
}

void destroy(struct stack *stack) {
    free(stack->data);
    free(stack);
}
