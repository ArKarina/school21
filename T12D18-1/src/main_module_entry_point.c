#include <stdio.h>

#include "documentation_module.h"
#include "print_module.h"

int main() {
    int err = 0;
    print_log(print_char, Module_load_success_message);

    char* documents[] = {Documents};
    int* availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    if (availability_mask) {
        for (int i = 0; i < Documents_count; i++) {
            printf("%-15s: %s\n", documents[i], availability_mask[i] ? "available" : "unavailable");
        }
        free(availability_mask);
    } else {
        printf("n/a");
        err = 1;
    }

    return err;
}
