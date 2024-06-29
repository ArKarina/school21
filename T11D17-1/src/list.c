#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init(const struct door* door) {
    struct node* new_node = malloc(sizeof(struct node));

    if (new_node) {
        new_node->data = *door;
        new_node->next = NULL;
    }

    return new_node;
}

struct node* add_door(struct node* elem, const struct door* door) {
    if (!elem || !door) return NULL;

    struct node* new_node = malloc(sizeof(struct node));

    if (new_node) {
        new_node->data = *door;
        new_node->next = elem->next;
        elem->next = new_node;
    }

    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    while (root && root->data.id != door_id) {
        root = root->next;
    }

    return root;
}

struct node* remove_door(const struct node* elem, struct node* root) {
    if (!elem || !root) return root;
    struct node *prev = NULL, *cur = root;

    while (cur && cur != elem) {
        prev = cur;
        cur = cur->next;
    }
    if (cur) {
        if (prev) {
            prev->next = cur->next;
        } else {
            root = cur->next;
        }
        free(cur);
    }
    return root;
}

void destroy(struct node* root) {
    while (root) {
        struct node* next = root->next;
        free(root);
        root = next;
    }
}
