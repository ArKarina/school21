#include "state_sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int err = 0;
    int choice = -1;
    char filename[MAX_LEN];
    Record record;

    if (fgets(filename, sizeof(filename), stdin)) {
        int len = strlen(filename);
        filename[len - 1] = '\0';

        if (scanf("%d", &choice) != 1) {
            printf("n/a");
            err = 1;
        }

        if (choice == 0) {
            read_file(filename);
        } else if (choice == 1) {
            sort_file(filename);
            read_file(filename);
        } else if (choice == 2) {
            if (scanf("%d %d %d %d %d %d %d %d", &record.year, &record.month, &record.day, &record.hour,
                      &record.minute, &record.second, &record.status, &record.code) != 8) {
                printf("n/a\n");
                err = 1;
            } else {
                add_record(filename, record);
                sort_file(filename);
                read_file(filename);
            }
        } else {
            printf("n/a\n");
            err = 1;
        }
    } else {
        printf("n/a\n");
        err = 1;
    }

    return err;
}

int compare_records(const void *a, const void *b) {
    const Record *ra = (const Record *)a;
    const Record *rb = (const Record *)b;

    if (ra->year != rb->year) return ra->year - rb->year;
    if (ra->month != rb->month) return ra->month - rb->month;
    if (ra->day != rb->day) return ra->day - rb->day;
    if (ra->hour != rb->hour) return ra->hour - rb->hour;
    if (ra->minute != rb->minute) return ra->minute - rb->minute;
    return ra->second - rb->second;
}

void print_record(const Record *r) {
    printf("%d %d %d %d %d %d %d %d\n", r->year, r->month, r->day, r->hour, r->minute, r->second, r->status,
           r->code);
}

int load_next_batch(FILE *file, Record *record, size_t record_size, size_t *loaded) {
    *loaded = fread(record, sizeof(Record), record_size, file);
    return *loaded > 0;
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fseek(file, 0, SEEK_END);
        long len = ftell(file);
        fseek(file, 0, SEEK_SET);
        if (!len) {
            printf("n/a\n");
        } else {
            Record record;
            while (fread(&record, sizeof(Record), 1, file) == 1) {
                print_record(&record);
            }
        }
        fclose(file);
    } else {
        printf("n/a\n");
    }
}

void add_record(const char *filename, Record record) {
    FILE *file = fopen(filename, "ab");
    if (file) {
        fwrite(&record, sizeof(Record), 1, file);
        fclose(file);
    } else {
        printf("n/a\n");
    }
}

void sort_file(const char *filename) {
    FILE *file = fopen(filename, "r+b");
    if (!file) {
        printf("n/a\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long len = ftell(file);
    rewind(file);

    int records_num = len / sizeof(Record);
    if (!records_num) {
        printf("n/a\n");
        fclose(file);
        return;
    }

    Record *records = malloc(records_num * sizeof(Record));
    if (!records) {
        printf("n/a\n");
        fclose(file);
        return;
    }

    size_t loaded;
    while (load_next_batch(file, records, records_num, &loaded)) {
        qsort(records, loaded, sizeof(Record), compare_records);
        fseek(file, 0, SEEK_SET);
        fwrite(records, sizeof(Record), loaded, file);
        fflush(file);
    }

    free(records);
    fclose(file);
}
