#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATE_LEN 11
#define MAX_LEN 256

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

int parse_date(const char *date, int *day, int *month, int *year);
int is_date_in_range(Record *record, Record *start, Record *end);
void clear_state(const char *filename, char *start_date_str, char *end_date_str);
void read_file(const char *filename);
void print_record(const Record *r);

int main(void) {
    int err = 0;
    char filename[MAX_LEN];
    char start_date_str[DATE_LEN];
    char end_date_str[DATE_LEN];

    if (fgets(filename, sizeof(filename), stdin)) {
        if (scanf("%10s", start_date_str) == 1 && scanf("%10s", end_date_str) == 1) {
            filename[strcspn(filename, "\n")] = 0;
            clear_state(filename, start_date_str, end_date_str);
            read_file(filename);
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

int parse_date(const char *date, int *day, int *month, int *year) {
    return sscanf(date, "%2d.%2d.%4d", day, month, year) == 3;
}

int is_date_in_range(Record *record, Record *start, Record *end) {
    if (record->year < start->year || record->year > end->year) return 0;
    if (record->year == start->year &&
        (record->month < start->month || (record->month == start->month && record->day < start->day)))
        return 0;
    if (record->year == end->year &&
        (record->month > end->month || (record->month == end->month && record->day > end->day)))
        return 0;
    return 1;
}

void clear_state(const char *filename, char *start_date_str, char *end_date_str) {
    int start_day, start_month, start_year;
    int end_day, end_month, end_year;

    if (!parse_date(start_date_str, &start_day, &start_month, &start_year) ||
        !parse_date(end_date_str, &end_day, &end_month, &end_year)) {
        printf("n/a\n");
        return;
    }

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("n/a\n");
        return;
    }

    FILE *temp_file = tmpfile();
    if (!temp_file) {
        printf("n/a\n");
        fclose(file);
        return;
    }

    Record start_date = {start_year, start_month, start_day, 0, 0, 0, 0, 0};
    Record end_date = {end_year, end_month, end_day, 23, 59, 59, 0, 0};
    Record record;

    int n = 0;
    while (fread(&record, sizeof(Record), 1, file) == 1) {
        if (!is_date_in_range(&record, &start_date, &end_date)) {
            fwrite(&record, sizeof(Record), 1, temp_file);
            n++;
        }
    }

    if (!n) {
        printf("n/a\n");
        fclose(file);
        fclose(temp_file);
        return;
    }

    freopen(filename, "wb", file);
    rewind(temp_file);
    while (fread(&record, sizeof(Record), 1, temp_file) == 1) {
        fwrite(&record, sizeof(Record), 1, file);
    }

    fclose(file);
    fclose(temp_file);
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

void print_record(const Record *r) {
    printf("%d %d %d %d %d %d %d %d\n", r->year, r->month, r->day, r->hour, r->minute, r->second, r->status,
           r->code);
}
