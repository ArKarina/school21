#include <stdio.h>

#define SCREEN_H 25
#define SCREEN_W 80
#define RACKET_LX 2
#define RACKET_RX 77
#define RW 3
#define WIN_SCORE 21

void draw(int ball_x, int ball_y, int racket_ly, int racket_ry);
int check_wall(int ball_y);
int check_goal(int ball_x);
int check_racket(int ball_x, int ball_y, int racket_ly, int racket_ry);

int main(void) {
    int score_l = 0;
    int score_r = 0;
    int ball_x = RACKET_LX + 1, ball_y = SCREEN_H / 2, racket_ly = SCREEN_H / 2 - 1,
        racket_ry = SCREEN_H / 2 - 1;
    int dx = -1, dy = -1;

    while (score_l < WIN_SCORE && score_r < WIN_SCORE) {
        printf("\t\t\t\t    score: %d - %d \n", score_l, score_r);
        draw(ball_x, ball_y, racket_ly, racket_ry);

        char ch = getchar();
        if (ch != '\n') getchar();
        if (ch == 'a' || ch == 'A') {
            if (racket_ly > 0) racket_ly = racket_ly - 1;
        } else if (ch == 'z' || ch == 'Z') {
            if (racket_ly < SCREEN_H - RW) racket_ly = racket_ly + 1;
        } else if (ch == 'k' || ch == 'K') {
            if (racket_ry > 0) racket_ry = racket_ry - 1;
        } else if (ch == 'm' || ch == 'M') {
            if (racket_ry < SCREEN_H - RW) racket_ry = racket_ry + 1;
        }

        if (check_wall(ball_y)) dy = -dy;
        if (check_racket(ball_x, ball_y, racket_ly, racket_ry)) dx = -dx;
        if (check_goal(ball_x) == -1) {
            score_r++;
            dx = -1;
            dy = -1;
            ball_x = RACKET_LX + 1 - dx;
            ball_y = SCREEN_H / 2 - dy;
            racket_ly = SCREEN_H / 2 - 1;
            racket_ry = SCREEN_H / 2 - 1;
        }
        if (check_goal(ball_x) == 1) {
            score_l++;
            dx = 1;
            dy = -1;
            ball_x = RACKET_RX - 1 - dx;
            ball_y = SCREEN_H / 2 - dy;
            racket_ly = SCREEN_H / 2 - 1;
            racket_ry = SCREEN_H / 2 - 1;
        }
        ball_x += dx;
        ball_y += dy;
    }
    if (score_l == WIN_SCORE)
        printf("!!!Win left player with score %d - %d!!!\n", score_l, score_r);
    else
        printf("!!!Win right player with score %d - %d!!!\n", score_l, score_r);
    return 0;
}

int check_wall(int ball_y) { return (ball_y == 0 || ball_y == SCREEN_H - 1); }

int check_goal(int ball_x) {
    if (ball_x == 0) return -1;
    if (ball_x == SCREEN_W - 1) return 1;

    return 0;
}

int check_racket(int ball_x, int ball_y, int racket_ly, int racket_ry) {
    return ((ball_x == RACKET_LX + 1 && ball_y >= racket_ly && ball_y < racket_ly + RW) ||
            (ball_x == RACKET_RX - 1 && ball_y >= racket_ry && ball_y < racket_ry + RW));
}

void draw(int ball_x, int ball_y, int racket_ly, int racket_ry) {
    printf("/");
    for (int x = 0; x < SCREEN_W; x++) printf("-");
    printf("\\\n");

    for (int y = 0; y < SCREEN_H; y++) {
        printf("|");
        for (int x = 0; x < SCREEN_W; x++) {
            if (ball_x == x && ball_y == y)
                printf("o");
            else if (x == RACKET_LX && y >= racket_ly && y < racket_ly + RW)
                printf("|");
            else if (x == RACKET_RX && y >= racket_ry && y < racket_ry + RW)
                printf("|");
            else if (x == SCREEN_W / 2)
                printf("|");
            else
                printf(" ");
        }
        printf("|\n");
    }

    printf("\\");
    for (int x = 0; x < SCREEN_W; x++) printf("-");
    printf("/\n");
}
