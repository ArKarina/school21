#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bstree_create_node_test() {
    int item1 = 4;
    t_btree *node1 = bstree_create_node(item1);
    if (node1 && node1->item == item1 && node1->left == NULL && node1->right == NULL) {
        printf("Test 1 SUCCESS: Node created with item = %d\n", item1);
    } else {
        printf("Test 1 FAIL\n");
    }

    int item2 = 7;
    t_btree *node2 = bstree_create_node(item2);
    if (node2 && node2->item == item2 && node2->left == NULL && node2->right == NULL) {
        printf("Test 2 SUCCESS: Node created with item = %d\n", item2);
    } else {
        printf("Test 2 FAIL\n");
    }

    free(node1);
    free(node2);
}

int main() {
    bstree_create_node_test();
    return 0;
}
