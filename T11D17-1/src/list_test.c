#include "list.h"

#include <stdio.h>

void add_door_test() {
    int err = 0;
    struct door door_test = {1, 0};
    struct node *root = init(&door_test);
    if (!root)
        err = 1;
    else {
        struct door new_door = {2, 0};
        const struct node *new_node = add_door(root, &new_door);
        if (!new_node || new_node->data.id != 2 || new_node->data.status != 0) err = 1;

        destroy(root);
    }

    printf("add_door_test\n");
    if (!err) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void remove_door_test() {
    int err = 0;
    struct door door_test = {1, 0};
    struct node *root = init(&door_test);
    if (!root)
        err = 1;
    else {
        struct door new_door = {2, 0};
        add_door(root, &new_door);
        const struct node *remove = find_door(2, root);
        if (!remove)
            err = 1;
        else {
            root = remove_door(remove, root);
            if (find_door(2, root)) err = 1;
        }
        destroy(root);
    }

    printf("remove_door_test\n");
    if (!err) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

int main(void) {
    add_door_test();
    remove_door_test();
}
