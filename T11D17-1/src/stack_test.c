#include "stack.h"

#include <stdio.h>

void push_test() {
    int err = 0;
    struct stack *stack = init(10);
    if (!stack)
        err = 1;
    else {
        if (push(stack, 1) || push(stack, 2)) err = 1;

        destroy(stack);
    }

    printf("push_test\n");
    if (!err) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void pop_test() {
    int err = 0;
    struct stack *stack = init(10);
    if (!stack)
        err = 1;
    else {
        int num = 0;
        if (push(stack, 1) || push(stack, 2)) err = 1;
        if (pop(stack, &num) || num != 2) err = 1;
        destroy(stack);
    }

    printf("pop_test\n");
    if (!err) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

int main(void) {
    push_test();
    pop_test();
}
