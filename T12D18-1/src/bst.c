#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

t_btree *bstree_create_node(int item) {
    t_btree *node = malloc(sizeof(t_btree));

    if (node) {
        node->item = item;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

int compare_int(int a, int b) { return (a - b); }

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    if (!root) return;

    t_btree *cur = root;
    t_btree *parent = root;

    while (cur) {
        parent = cur;
        if (cmpf(item, cur->item) < 0) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    t_btree *new_node = bstree_create_node(item);
    if (cmpf(item, parent->item) < 0) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (!root) return;
    bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (!root) return;
    applyf(root->item);
    bstree_apply_prefix(root->left, applyf);
    bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (!root) return;
    bstree_apply_postfix(root->left, applyf);
    bstree_apply_postfix(root->right, applyf);
    applyf(root->item);
}

void print_item(int item) { printf("%d ", item); }
