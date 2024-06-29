#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bstree_traverse_test() {
    t_btree *root = bstree_create_node(5);
    bstree_insert(root, 3, compare_int);
    bstree_insert(root, 7, compare_int);
    bstree_insert(root, 2, compare_int);
    bstree_insert(root, 4, compare_int);

    printf("Tree 1 structure:\n");
    printf("Infix traversal:\n");
    bstree_apply_infix(root, print_item);
    printf("\n");

    printf("Prefix traversal:\n");
    bstree_apply_prefix(root, print_item);
    printf("\n");

    printf("Postfix traversal:\n");
    bstree_apply_postfix(root, print_item);
    printf("\n\n");

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    t_btree *root2 = bstree_create_node(10);
    bstree_insert(root2, 15, compare_int);
    bstree_insert(root2, 5, compare_int);
    bstree_insert(root2, 7, compare_int);
    bstree_insert(root2, 12, compare_int);

    printf("Tree 2 structure:\n");
    printf("Infix traversal:\n");
    bstree_apply_infix(root2, print_item);
    printf("\n");

    printf("Prefix traversal:\n");
    bstree_apply_prefix(root2, print_item);
    printf("\n");

    printf("Postfix traversal:\n");
    bstree_apply_postfix(root2, print_item);
    printf("\n");

    free(root2->left->right);
    free(root2->left);
    free(root2->right->left);
    free(root2->right);
    free(root2);
}

int main() {
    bstree_traverse_test();
    return 0;
}
