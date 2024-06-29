#include <math.h>
#include <stdio.h>

void encode();
void decode();
char hex_to_char(char ch1, char ch2);
int dig_from_char(char ch);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("n/a\n");
        return 1;
    }

    int mode = argv[1][0] - '0';
    if (mode == 0)
        encode();
    else if (mode == 1)
        decode();
    else {
        printf("n/a\n");
        return 1;
    }

    return 0;
}

void encode() {
    char ch1, ch2;
    ch1 = getchar();
    ch2 = getchar();

    if (ch2 != '\n' && ch2 != ' ') {
        printf("n/a\n");
        return;
    }
    while (ch2 != '\n') {
        printf("%X ", ch1);
        ch1 = getchar();
        ch2 = getchar();
    }
    printf("%X\n", ch1);
}

void decode() {
    char ch1, ch2, ch3;
    ch1 = getchar();
    ch2 = getchar();
    ch3 = getchar();

    if (ch3 != '\n' && ch3 != ' ') {
        printf("n/a\n");
        return;
    }
    while (ch3 != '\n') {
        printf("%c ", hex_to_char(ch1, ch2));
        ch1 = getchar();
        ch2 = getchar();
        ch3 = getchar();
    }
    printf("%c\n", hex_to_char(ch1, ch2));
}

char hex_to_char(char ch1, char ch2) {
    int x = dig_from_char(ch1);
    int y = dig_from_char(ch2);
    return x * 16 + y;
}

int dig_from_char(char ch) {
    if ('0' <= ch && ch <= '9') return ch - '0';
    if ('A' <= ch && ch <= 'F') return ch - 'A' + 10;
    return -1;
}
