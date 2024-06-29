#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#define SCREEN_H 25
#define SCREEN_W 80
#define SPEED 4

void input(int matr[SCREEN_H][SCREEN_W], int n, int m);
void output(int matr[SCREEN_H][SCREEN_W], int n, int m);
int num_neighbors(int matr[SCREEN_H][SCREEN_W], int n, int m, int i, int j);
void logic(int matr[SCREEN_H][SCREEN_W], int n, int m);
int check_matrix(int matr[SCREEN_H][SCREEN_W], int n, int m);

int main(void) {
    int exit = 0;
    int n = SCREEN_H, m = SCREEN_W;
    int matr[SCREEN_H][SCREEN_W];
    int speed = SPEED;

    input(matr, n, m);

    if (freopen("/dev/tty", "r", stdin)) initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);

    output(matr, n, m);

    while (check_matrix(matr, n, m) && !exit) {
        char ch = getch();
        if (ch == 'q')
            exit = 1;
        else if (ch == '+' && speed > 1)
            speed--;
        else if (ch == '-' && speed < 10)
            speed++;

        logic(matr, n, m);
        usleep(speed * 100000);
    }

    endwin();
    printf("\nGame over!!!\n\n");
    return 0;
}

void input(int matr[SCREEN_H][SCREEN_W], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &matr[i][j]);
}

void output(int matr[SCREEN_H][SCREEN_W], int n, int m) {
    move(0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matr[i][j] == 1)
                addch('x');
            else
                addch('.');
        }
        if (i < n - 1) addch('\n');
    }
    printw("\n\t  To end the game, press q. To change the speed press + or -.\n");
}

int num_neighbors(int matr[SCREEN_H][SCREEN_W], int n, int m, int i, int j) {
    int counter = 0;
    int xx, yy;
    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            xx = (x + n) % n;
            yy = (y + m) % m;

            if ((xx != i || yy != j) && matr[xx][yy] == 1) counter++;
        }
    }
    return counter;
}

void logic(int matr[SCREEN_H][SCREEN_W], int n, int m) {
    int temp[SCREEN_H][SCREEN_W];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) temp[i][j] = matr[i][j];

    int neighbors;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            neighbors = num_neighbors(matr, n, m, i, j);
            if (matr[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                temp[i][j] = 0;
                move(i, j);
                addch('.');
            } else if (matr[i][j] == 1)
                temp[i][j] = 1;
            else if (matr[i][j] == 0 && neighbors == 3) {
                temp[i][j] = 1;
                move(i, j);
                addch('x');
            } else
                temp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) matr[i][j] = temp[i][j];
}

int check_matrix(int matr[SCREEN_H][SCREEN_W], int n, int m) {
    int err = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matr[i][j] == 1) err = 1;

    return err;
}
