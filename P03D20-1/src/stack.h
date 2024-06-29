#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    double *data;
    int top;
    int n;
} Stack;

Stack *init(int n);
int push(Stack *stack, double num);
double pop(Stack *stack);
void destroy(Stack *stack);
int is_empty(Stack *stack);

#endif
