#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bstree_insert_test() {
    t_btree *root1 = bstree_create_node(5);
    bstree_insert(root1, 3, compare_int);
    bstree_insert(root1, 7, compare_int);
    bstree_insert(root1, 2, compare_int);
    bstree_insert(root1, 4, compare_int);

    printf("Tree 1 structure:\n");
    printf("Insert 2, 4 after 3\n");
    printf("      %d\n", root1->item);
    printf("     / \\\n");
    printf("    %d   %d\n", root1->left->item, root1->right->item);
    printf("   / \\\n");
    printf("  %d   %d\n", root1->left->left->item, root1->left->right->item);

    free(root1->left->left);
    free(root1->left->right);
    free(root1->left);
    free(root1->right);
    free(root1);

    t_btree *root2 = bstree_create_node(10);
    bstree_insert(root2, 15, compare_int);
    bstree_insert(root2, 5, compare_int);
    bstree_insert(root2, 7, compare_int);
    bstree_insert(root2, 12, compare_int);

    printf("Tree 2 structure:\n");
    printf("Insert 15 after 10\n");
    printf("      %d\n", root2->item);
    printf("     / \\\n");
    printf("    %d   %d\n", root2->left->item, root2->right->item);
    printf("     \\    \\\n");
    printf("      %d    %d\n", root2->left->right->item, root2->right->left->item);

    free(root2->left->right);
    free(root2->left);
    free(root2->right->left);
    free(root2->right);
    free(root2);
}

int main() {
    bstree_insert_test();
    return 0;
}
