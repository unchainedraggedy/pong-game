#include <stdio.h>
void screen(int Lpad, int Rpad, int xBall, int yBall, int visota, int shirina, int score_A, int score_B);
void score_points(int score_A, int score_B);
// void Lev_goal(int xBall, int yBall, int visota, int shirina, int score_A, int score_B)
int main() {
    int shirina = 80;
    int visota = 25;
    int Lpad = (visota / 2) - 1;
    int Rpad = (visota / 2) - 1;
    int xBall = shirina / 2;
    int yBall = visota / 2;
    int score_A = 0;
    int score_B = 0;
    int b_move = 5;

   

    while (1) {
        screen(Lpad, Rpad, xBall, yBall, visota, shirina, score_A, score_B);

        // vvod s kaviaturi
        char v;
        scanf("%c", &v);
        if (v == 'A' || v == 'a') {
            if (Lpad > 1) {
                Lpad--;
            }
        } else if (v == 'Z' || v == 'z') {
            if (Lpad + 2 < visota - 1) {
                Lpad++;
            }
        } else if (v == 'K' || v == 'k') {
            if (Rpad > 1) {
                Rpad--;
            }
        } else if (v == 'M' || v == 'm') {
            if (Rpad + 2 < visota - 1) Rpad++;
        } else if (v == 'Q' || v == 'q') {
            break;
        }
        // Left goal
        if (xBall == 1) {
            xBall = shirina / 2;
            yBall = visota / 2;
            Lpad = (visota / 2) - 2;
            Rpad = (visota / 2) - 2;
            score_B++;
        }
        // Right goal
        if (xBall == shirina - 2) {
            xBall = shirina / 2;
            yBall = visota / 2;
            Lpad = (visota / 2) - 1;
            Rpad = (visota / 2) - 1;
            score_A++;
        }
        // ball move
        if (b_move == 1) {
            xBall++;
            yBall--;
        }
        if (b_move == 2) {
            xBall++;
        }
        if (b_move == 3) {
            xBall++;
            yBall++;
        }
        if (b_move == 4) {
            xBall--;
            yBall++;
        }
        if (b_move == 5) {
            xBall--;
        }
        if (b_move == 6) {
            xBall--;
            yBall--;
        }

        // otbivka Rpad
        if (xBall == shirina - 4) {
            if (yBall == Rpad) {
                b_move = 6;
            }
            if (yBall == Rpad + 1) {
                b_move = 5;
            }
            if (yBall == Rpad + 2) {
                b_move = 4;
            }
        }

        // otbivka Lpad
        if (xBall == 4) {
            if (yBall == Lpad) {
                b_move = 1;
            }
            if (yBall == Lpad + 1) {
                b_move = 2;
            }
            if (yBall == Lpad + 2) {
                b_move = 3;
            }
        }

        // otbivka Potolok
        if (yBall == 1) {
            if (b_move == 1) b_move = 3;
            if (b_move == 6) b_move = 4;
        }

        // otbivka Pol
        if (yBall == visota - 1) {
            if (b_move == 3) b_move = 1;
            if (b_move == 4) b_move = 6;
        }
        if (score_A == 21 || score_B == 21) {
            break;
        }
    }
    screen(Lpad, Rpad, xBall, yBall, visota, shirina, score_A, score_B);
}
void screen(int Lpad, int Rpad, int xBall, int yBall, int visota, int shirina, int score_A, int score_B) {
    for (int y = 0; y <= visota; y++) {
        for (int x = 0; x <= shirina; x++) {
            if ((y == 0 || y == visota) && x != 0 && x <= shirina - 1) {
                printf("*");
            } else if ((x == 0 || x == shirina) && y < visota + 1) {
                printf("*");
            } else if (y >= Lpad && y < Lpad + 3 && x == 3) {
                printf("|");
            } else if (y >= Rpad && y < Rpad + 3 && x == shirina - 3) {
                printf("|");
            } else if (y == yBall && x == xBall) {
                printf("@");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    score_points(score_A, score_B);
}

void score_points(int score_A, int score_B) {
    printf("1st player score: %d\n", score_A);
    printf("2nd Player score: %d\n", score_B);
    if (score_A >= 21) {
        printf("1st Player WON!!!");
    }
    if (score_B >= 21) {
        printf("2nd Player WON!!!");
    }
}