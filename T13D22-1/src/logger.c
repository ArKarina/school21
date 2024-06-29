#include "logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static const char *level_to_string(log_level level) {
    switch (level) {
        case DEBUG:
            return "DEBUG";
        case INFO:
            return "INFO";
        case WARNING:
            return "WARNING";
        case ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

FILE *log_init(char *filename) {
    FILE *log_file = fopen(filename, "a+");
    if (!log_file) {
        perror("Failed to open log file");
    }
    return log_file;
}

int logcat(FILE *log_file, char *message, log_level level) {
    if (!log_file) return -1;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", t);

    fprintf(log_file, "[%s] %s: %s\n", time_str, level_to_string(level), message);
    fflush(log_file);

    return 0;
}

int log_close(FILE *log_file) {
    if (!log_file) return -1;
    return fclose(log_file);
}
