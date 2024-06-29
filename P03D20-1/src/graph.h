#ifndef GRAPH_H
#define GRAPH_H

#include <math.h>

#include "tokenize.h"

#define HEIGHT 25
#define WIDTH 80
#define DEFINITION (4 * M_PI)
#define STEP (DEFINITION / (WIDTH - 1))
#define RANGE_MIN -1
#define RANGE_MAX 1

void print_graph(Token *rpn, int rpn_num);

#endif
