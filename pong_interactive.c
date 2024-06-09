#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>

void screen(int left_pad, int right_pad, int x_axi_ball, int y_axi_ball, int shirinapolya, int visotapolya,
            int score_1st_player, int score_2nd_player);
void score_display(int score_1st_player, int score_2nd_player);
void ClearScreen(void);

int main() {
    char button = getch();

    int shirinapolya = 80;
    int visotapolya = 25;
    int winners_score = 21;

    int left_pad = (visotapolya / 2) - 1;
    int right_pad = (visotapolya / 2) - 1;

    int x_axi_ball = shirinapolya / 2;
    int y_axi_ball = visotapolya / 2;

    int score_1st_player = 0;
    int score_2nd_player = 0;

    int ball_movement;
    int sizeLine;

    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    srand(time(NULL));
    ball_movement = rand() % 6 + 1;

    screen(left_pad, right_pad, x_axi_ball, y_axi_ball, shirinapolya, visotapolya, score_1st_player,
           score_2nd_player);

    while (scanf("%c", &button) && score_1st_player != winners_score && score_2nd_player != winners_score) {
        // проверка на кол-во введенных символов
        sizeLine = 1;
        while (getchar() != '\n') {
            ++sizeLine;
        }

        if (sizeLine != 1) {
            ClearScreen();
            screen(left_pad, right_pad, x_axi_ball, y_axi_ball, shirinapolya, visotapolya, score_1st_player,
                   score_2nd_player);
            continue;
        }
        //Обработка нажатий (управление ракетками)

        if (button == 'A' || button == 'a') {
            if (left_pad != 1) {
                left_pad--;
            }
        } else if (button == 'Z' || button == 'z') {
            if (left_pad != visotapolya - 3) {
                left_pad++;
            }
        } else if (button == 'K' || button == 'k') {
            if (right_pad != 1) {
                right_pad--;
            }
        } else if (button == 'M' || button == 'm') {
            if (right_pad != visotapolya - 3) right_pad++;
        } else if (button == 'Q' || button == 'q') {
            break;
        } else if (button != ' ') {
            ClearScreen();
            screen(left_pad, right_pad, x_axi_ball, y_axi_ball, shirinapolya, visotapolya, score_1st_player,
                   score_2nd_player);
            continue;
        }

        // Гол левому игроку

        if (x_axi_ball == 1) {
            x_axi_ball = shirinapolya / 2;
            y_axi_ball = visotapolya / 2;
            left_pad = (visotapolya / 2) - 2;
            right_pad = (visotapolya / 2) - 2;
            score_1st_player++;
            ball_movement = rand() % 6 + 1;
        }

        // Гол правому игроку

        if (x_axi_ball == shirinapolya - 1) {
            x_axi_ball = shirinapolya / 2;
            y_axi_ball = visotapolya / 2;
            left_pad = (visotapolya / 2) - 1;
            right_pad = (visotapolya / 2) - 1;
            score_2nd_player++;
            ball_movement = rand() % 6 + 1;
            }

        if (score_1st_player == winners_score || score_2nd_player == winners_score) break;

        // Отбивание правая ракетка

        if (x_axi_ball == shirinapolya - 2) {
            if (y_axi_ball == right_pad) {
                ball_movement = 4;
            }
            if (y_axi_ball == right_pad + 1) {
                ball_movement = 5;
            }
            if (y_axi_ball == right_pad + 2) {
                ball_movement = 6;
            }
        }

        // Отбивка левая ракетка

        if (x_axi_ball == 2) {
            if (y_axi_ball == left_pad) {
                ball_movement = 3;
            }
            if (y_axi_ball == left_pad + 1) {
                ball_movement = 2;
            }
            if (y_axi_ball == left_pad + 2) {
                ball_movement = 1;
            }
        }

        // Удар об стену мяча

        if (y_axi_ball == 1)  // верхняя стенка
        {
            if (ball_movement == 3) {
                ball_movement = 1;
            } else if (ball_movement == 4) {
                ball_movement = 6;
            }
        } else if (y_axi_ball == visotapolya - 1) {  //
            if (ball_movement == 1) {
                ball_movement = 3;
            } else if (ball_movement == 6) {
                ball_movement = 4;
            }
        }

        // Движение мяча

        if (ball_movement == 1) {
            x_axi_ball++;
            y_axi_ball++;
        }

        else if (ball_movement == 2) {
            x_axi_ball++;
        } else if (ball_movement == 3) {
            x_axi_ball++;
            y_axi_ball--;
        } else if (ball_movement == 4) {
            x_axi_ball--;
            y_axi_ball--;
        } else if (ball_movement == 5) {
            x_axi_ball--;
        } else if (ball_movement == 6) {
            x_axi_ball--;
            y_axi_ball++;
        }
        ClearScreen();
        screen(left_pad, right_pad, x_axi_ball, y_axi_ball, shirinapolya, visotapolya, score_1st_player,
               score_2nd_player);

               usleep(100000);
        endwin();
               
    }
}

void ClearScreen(void) { printf("\033[H\033[2J"); }

void screen(int left_pad, int right_pad, int x_axi_ball, int y_axi_ball, int shirinapolya, int visotapolya,
            int score_1st_player, int score_2nd_player) {
    for (int i = 0; i <= visotapolya; i++) {
        for (int j = 0; j <= shirinapolya; j++) {
            if ((i == 0 || i == visotapolya) && j != 0 && j <= shirinapolya - 1) {
                printw("-");
            } else if ((j == 0 || j == shirinapolya) && i < visotapolya + 1) {
                printw("|");
            } else if (i >= left_pad && i < left_pad + 3 && j == 1) {
                printw("*");
            } else if (i >= right_pad && i < right_pad + 3 && j == shirinapolya - 1) {
                printw("*");
            } else if (i == y_axi_ball && j == x_axi_ball) {
                printw("o");
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }
    score_display(score_1st_player, score_2nd_player);
    refresh();
}

int visota = 25;
int shirina = 80;

void score_display(int score_1st_player, int score_2nd_player) {
    printw("1st Player score: %d\n", score_1st_player);
    printw("2nd Player score: %d\n", score_2nd_player);

    if (score_1st_player >= 21) {
        mvprintw(visota / 2, (shirina / 2) - 10, "1st Player wins!\n");
    }
    if (score_2nd_player >= 21) {
        mvprintw(visota / 2, (shirina / 2) - 10, "1st Player wins!\n");
    }
}
