#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rpn.h"
#include "tokenize.h"

int main(void) {
    int err = 0;
    char expression[MAX_LEN];

    if (fgets(expression, sizeof(expression), stdin)) {
        int len = strlen(expression);
        expression[len - 1] = '\0';

        int tokens_num = 0;
        Token *tokens = tokenize(expression, &tokens_num);
        if (tokens) {
            int rpn_num = 0;
            Token *rpn = to_rpn(tokens, tokens_num, &rpn_num);

            print_graph(rpn, rpn_num);

            free(tokens);
            free(rpn);
        } else {
            printf("n/a");
            err = 1;
        }
    } else {
        printf("n/a");
        err = 1;
    }

    return err;
}

void print_graph(Token *rpn, int rpn_num) {
    char graph[HEIGHT][WIDTH];
    memset(graph, '.', sizeof(graph));

    for (int i = 0; i < WIDTH; i++) {
        double x = i * STEP;
        double y = compute_function(rpn, rpn_num, x);

        if (y >= RANGE_MIN && y <= RANGE_MAX) {
            int inverted_y = round(((y - RANGE_MIN) / (RANGE_MAX - RANGE_MIN) * HEIGHT));
            if (inverted_y >= HEIGHT) {
                inverted_y = HEIGHT - 1;
            }
            graph[inverted_y][i] = '*';
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(graph[i][j]);
        }
        if (i < HEIGHT - 1) putchar('\n');
    }
}
