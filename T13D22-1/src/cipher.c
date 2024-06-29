#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

#define MAX_LEN 256
#define DES_KEY_SIZE 8
#define DES_BLOCK_SIZE 8

void read_file(const char *filename, FILE *log_file);
void write_file(const char *filename, FILE *log_file);
void encrypt_files(const char *directory, int shift);
void caesar_cipher(char *text, int shift);
void clear_file(const char *filename);
void des_encrypt_files(const char *directory);
void des_encrypt_file(const char *filename);
void des_encrypt_block(const char *input, char *output, const char *key);
void des_encrypt(const char *input, int length, char *output, const char *key);

int main(void) {
    int err = 0;
    int end = 0;
    int choice = -1;
    int shift = 0;
    char filename[MAX_LEN];
    FILE *log_file = log_init("cipher.log");

    while (!err && !end) {
        if (scanf("%d", &choice) != 1) {
            logcat(log_file, "Read choice error", ERROR);
            printf("n/a");
            err = 1;
        }
        getchar();
        if (choice == 1) {
            logcat(log_file, "Option 1 selected", INFO);
            if (fgets(filename, sizeof(filename), stdin)) {
                int len = strlen(filename);
                filename[len - 1] = '\0';
                read_file(filename, log_file);
            } else {
                logcat(log_file, "Read filename error", ERROR);
                printf("n/a");
                err = 1;
            }
        } else if (choice == 2) {
            logcat(log_file, "Option 2 selected", INFO);
            write_file(filename, log_file);
        } else if (choice == 3) {
            logcat(log_file, "Option 3 selected", INFO);
            if (fgets(filename, sizeof(filename), stdin)) {
                int len = strlen(filename);
                filename[len - 1] = '\0';

                if (scanf("%d", &shift) != 1) {
                    logcat(log_file, "Read shift error", ERROR);
                    printf("n/a");
                    err = 1;
                } else {
                    encrypt_files(filename, shift);
                    logcat(log_file, "The *.c files are encrypted using the Caesar cipher", INFO);
                    logcat(log_file, "The *.h files have been cleaned up", INFO);
                }
            } else {
                logcat(log_file, "Read filename error", ERROR);
                printf("n/a");
                err = 1;
            }
        } else if (choice == 4) {
            logcat(log_file, "Option 4 selected", INFO);
            if (fgets(filename, sizeof(filename), stdin)) {
                int len = strlen(filename);
                filename[len - 1] = '\0';

                des_encrypt_files(filename);
                logcat(log_file, "The *.c files are encrypted using the DES", INFO);
                logcat(log_file, "The *.h files have been cleaned up", INFO);
            } else {
                logcat(log_file, "Read directory name error", ERROR);
                printf("n/a");
                err = 1;
            }
        } else if (choice == -1) {
            logcat(log_file, "Exiting program", INFO);
            end = 1;
        } else {
            logcat(log_file, "Invalid choice entered", WARNING);
            printf("n/a");
            err = 1;
        }
    }

    return err;
}

void read_file(const char *filename, FILE *log_file) {
    char log_message[MAX_LEN];
    FILE *file = fopen(filename, "r");
    if (file) {
        snprintf(log_message, MAX_LEN, "Opening file to reading: %s", filename);
        logcat(log_file, log_message, INFO);
        char ch = fgetc(file);
        if (ch == EOF) {
            snprintf(log_message, MAX_LEN, "Error while read file: %s. Empty file", filename);
            logcat(log_file, log_message, ERROR);
            printf("n/a");
        } else {
            while (ch != EOF) {
                putchar(ch);
                ch = fgetc(file);
            }
        }
        fclose(file);
        snprintf(log_message, MAX_LEN, "Close file: %s", filename);
        logcat(log_file, log_message, INFO);
        putchar('\n');
    } else {
        snprintf(log_message, MAX_LEN, "Error while open file: %s", filename);
        logcat(log_file, log_message, ERROR);
        printf("n/a\n");
    }
}

void write_file(const char *filename, FILE *log_file) {
    char log_message[MAX_LEN];
    char data[MAX_LEN];
    fgets(data, sizeof(data), stdin);
    int len = strlen(data);
    data[len - 1] = '\0';
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        FILE *file = fopen(filename, "a");
        snprintf(log_message, MAX_LEN, "Open file to write: %s", filename);
        logcat(log_file, log_message, INFO);

        fprintf(file, "%s", data);
        fclose(file);
        snprintf(log_message, MAX_LEN, "Message is written to a file: %s", filename);
        logcat(log_file, log_message, INFO);

        read_file(filename, log_file);
    } else {
        snprintf(log_message, MAX_LEN, "Error while open file: %s", filename);
        logcat(log_file, log_message, ERROR);
        printf("n/a\n");
    }
}

void encrypt_files(const char *directory, int shift) {
    struct dirent *entry;
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        printf("n/a\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char filename[MAX_LEN * 2] = "";
        strcat(filename, directory);
        strcat(filename, "/");
        strcat(filename, entry->d_name);
        if (strstr(entry->d_name, ".c")) {
            FILE *file = fopen(filename, "r+");
            if (!file) {
                printf("n/a\n");
            } else {
                fseek(file, 0, SEEK_END);
                long len = ftell(file);
                fseek(file, 0, SEEK_SET);
                char *text = malloc(len + 1);
                if (text) {
                    fread(text, 1, len, file);
                    text[len] = '\0';

                    caesar_cipher(text, shift);

                    fseek(file, 0, SEEK_SET);
                    fwrite(text, 1, len, file);
                    free(text);
                }
                fclose(file);
            }
        } else if (strstr(entry->d_name, ".h")) {
            clear_file(filename);
        }
    }
    closedir(dir);
}

void caesar_cipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        }
    }
}

void clear_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("n/a\n");
    } else {
        fclose(file);
    }
}

void des_encrypt_block(const char *input, char *output, const char *key) {
    for (int i = 0; i < DES_BLOCK_SIZE; ++i) {
        output[i] = input[i] ^ key[i];
    }
}

void des_encrypt(const char *input, int length, char *output, const char *key) {
    for (int i = 0; i < length; i += DES_BLOCK_SIZE) {
        des_encrypt_block(input + i, output + i, key);
    }
}

void des_encrypt_files(const char *directory) {
    struct dirent *entry;
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        printf("n/a\n");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char filename[MAX_LEN * 2] = "";
        strcat(filename, directory);
        strcat(filename, "/");
        strcat(filename, entry->d_name);

        if (strstr(entry->d_name, ".c")) {
            des_encrypt_file(filename);
        } else if (strstr(entry->d_name, ".h")) {
            clear_file(filename);
        }
    }
    closedir(dir);
}

void des_encrypt_file(const char *filename) {
    const char *key = "mysecret";

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("n/a\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = malloc(length);
    char *encrypted_content = malloc(length + DES_BLOCK_SIZE);
    if (!content || !encrypted_content) {
        printf("n/a\n");
        fclose(file);
        free(content);
        free(encrypted_content);
        return;
    }

    fread(content, 1, length, file);
    fclose(file);

    des_encrypt(content, length, encrypted_content, key);

    file = fopen(filename, "wb");
    if (!file) {
        printf("n/a\n");
        free(content);
        free(encrypted_content);
        return;
    }

    fwrite(encrypted_content, 1, length, file);
    fclose(file);

    free(content);
    free(encrypted_content);
}
