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
void search_by_date(const char *filename, const char *date);

int main(void) {
    int err = 0;
    char filename[MAX_LEN];
    char date[DATE_LEN];

    if (fgets(filename, sizeof(filename), stdin)) {
        int len = strlen(filename);
        filename[len - 1] = '\0';

        if (fgets(date, DATE_LEN, stdin)) {
            date[DATE_LEN - 1] = '\0';

            search_by_date(filename, date);

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

void search_by_date(const char *filename, const char *date) {
    int day, month, year;
    if (!parse_date(date, &day, &month, &year)) {
        printf("n/a\n");
        return;
    }

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("n/a\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long len = ftell(file);
    rewind(file);

    if (!len) {
        printf("n/a\n");
        fclose(file);
        return;
    }

    Record record;
    while (fread(&record, sizeof(Record), 1, file) == 1) {
        if (record.year == year && record.month == month && record.day == day) {
            printf("%d\n", record.code);
            fclose(file);
            return;
        }
    }

    printf("n/a\n");
    fclose(file);
}
