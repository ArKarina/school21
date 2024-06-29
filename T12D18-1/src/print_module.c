#include "print_module.h"

#include <stdio.h>
#include <time.h>

void print_log(int (*print)(char), char* message) {
    char buffer[9];
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    strftime(buffer, sizeof(buffer), "%H:%M:%S", t);

    for (int i = 0; Log_prefix[i] != '\0'; i++) {
        print(Log_prefix[i]);
    }
    print(' ');
    for (int i = 0; buffer[i] != '\0'; i++) {
        print(buffer[i]);
    }
    print(' ');
    for (int i = 0; message[i] != '\0'; i++) {
        print(message[i]);
    }
    print('\n');
}

int print_char(char ch) { return putchar(ch); }
