#ifndef STACK_H
#define STACK_H

struct stack {
    int *data;
    int top;
    int n;
};

struct stack *init(int n);
int push(struct stack *stack, int num);
int pop(struct stack *stack, int *num);
void destroy(struct stack *stack);

#endif
