#ifndef RPN_H
#define RPN_H

#include "tokenize.h"

Token *to_rpn(Token *tokens, int tokens_num, int *rpn_num);
double compute_function(Token *rpn, int rpn_num, double x);
int priority(char *op);
double calc(double a, double b, char op);
double func(double a, char *op);

#endif
