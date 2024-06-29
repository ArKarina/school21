#ifndef STATE_SORT_H
#define STATE_SORT_H

#include <stdio.h>

#define MAX_LEN 256
#define MAX_RECORDS_IN_MEMORY 10

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} Record;

int compare_records(const void *a, const void *b);
void print_record(const Record *r);
int load_next_batch(FILE *file, Record *record, size_t record_size, size_t *loaded);
void read_file(const char *filename);
void add_record(const char *filename, Record record);
void sort_file(const char *filename);

#endif