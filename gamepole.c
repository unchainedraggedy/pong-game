#include <stdio.h>

const int shirinapolya = 80;
const int visotapolya = 25;

int left_pad = (visotapolya / 2) - 1;
int right_pad = (visotapolya / 2) - 1;

int x_axi_ball = shirinapolya / 2;
int y_axi_ball = visotapolya / 2;

int score_1st_player = 0;
int score_2nd_player = 0;

int ball_movement = 5;


void screeen(int left_pad, int right_pad, int x_axi_ball, int y_axi_ball, int shirinapolya, int visotapolya, int score_1st_player, int score_2nd_player);
void score_display(int score_1st_player, int score_2nd_player);

int main() {
    screeen(left_pad, right_pad, x_axi_ball, y_axi_ball, shirinapolya, visotapolya, score_1st_player, score_2nd_player);
}

void screeen(int left_pad, int right_pad, int x_axi_ball, int y_axi_ball, int shirinapolya, int visotapolya, int score_1st_player, int score_2nd_player) {
    for(int i = 0; i <= visotapolya; i++) {
        for(int j = 0; j <= shirinapolya; j++) {
            if((i == 0 || i == visotapolya) && j != 0 && j <= shirinapolya - 1) {
                printf("-");
            } else if ((j == 0 || j == shirinapolya) && i < visotapolya + 1) {
                printf("|");
            } else if (i >= left_pad && i < left_pad + 3 && j == 3) {
                printf("*");
            } else if (i >= right_pad && i < right_pad + 3 && j == shirinapolya -3) {
                printf("*");
            } else if (i == y_axi_ball && j == x_axi_ball) {
                printf("@");
            } else {
                printf(" ");
            }
    }
    printf("\n");
}
    score_display(score_1st_player, score_2nd_player);
}

void score_display(int score_1st_player, int score_2nd_player) {
    printf("1st Player score: %d\n", score_1st_player);
    printf("2nd Player score: %d\n", score_2nd_player);

    if (score_1st_player >= 21) {
        printf("1st Player wins!\n");
    }
    if (score_2nd_player >= 21) {
        printf("2nd Player wins!\n");
    }
}