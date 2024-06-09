#include <stdio.h>

void screen(int left_pad, int right_pad, int x_axi_ball, int y_axi_ball,
            int shirinapolya, int visotapolya, int score_1st_player,
            int score_2nd_player);
void score_display(int score_1st_player, int score_2nd_player);
void control(int shirinapolya, int visotapolya, int left_pad, int right_pad,
char button); void ball_move(int ball_movement, int x_axi_ball, int
y_axi_ball);

void ClearScreen(void);

int main() {
  char button;

  int shirinapolya = 80;
  int visotapolya = 25;
  int winners_score = 21;

  int left_pad = (visotapolya / 2) - 1;
  int right_pad = (visotapolya / 2) - 1;

  int x_axi_ball = shirinapolya / 2;
  int y_axi_ball = visotapolya / 2;

  int score_1st_player = 0;
  int score_2nd_player = 0;

  int ball_movement = 5;

  screen(left_pad, right_pad, x_axi_ball, y_axi_ball, shirinapolya, visotapolya,
         score_1st_player, score_2nd_player);

  while (scanf("%c", &button) && score_1st_player != winners_score &&
         score_2nd_player != winners_score) {

        screen(left_pad, right_pad, x_axi_ball, y_axi_ball, shirinapolya,
           visotapolya, score_1st_player, score_2nd_player);
        // Обработка нажатий (управление ракетками)


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
if (right_pad != visotapolya - 3)
right_pad++;
} else if (button == 'Q' || button == 'q') {
    break;
}

    //  switch (button) {
    //  case 'A':
    //  case 'a':
    //   if (left_pad != 1)
    //     --left_pad;
    //   break;
    //  case 'Z':
    //  case 'z':
    //   if (left_pad != visotapolya - 3)
    //     ++left_pad;
    //   break;
    //  case 'K':
    //  case 'k':
    //   if (right_pad != 1)
    //     --right_pad;
    //   break;
    //  case 'M':
    //  case 'm':
    //   if (right_pad != visotapolya - 3)    
    //     ++right_pad;
    //   break;
    // }

// Гол левому игроку

if (x_axi_ball == 1) {
    x_axi_ball = shirinapolya / 2;
    y_axi_ball = visotapolya / 2;
    left_pad = (visotapolya / 2) - 2;
    right_pad = (visotapolya / 2) - 2;
    score_1st_player++;
}

// Гол правому игроку

if (x_axi_ball == shirinapolya - 2) {
    x_axi_ball = shirinapolya / 2;
    y_axi_ball = visotapolya / 2;
    left_pad = (visotapolya / 2) - 1;
    right_pad = (visotapolya / 2) - 1;
    score_2nd_player++;
}

    // Движение мяча

 if (ball_movement == 1) {
      x_axi_ball++;
      y_axi_ball++;
    }

    if (ball_movement == 2) {
      x_axi_ball++;
    }
    if (ball_movement == 3) {
      x_axi_ball++;
      y_axi_ball++;
    }
    if (ball_movement == 4) {
      x_axi_ball--;
      y_axi_ball++;
    }
    if (ball_movement == 5) {
      x_axi_ball--;
    }
    if (ball_movement == 6) {
        x_axi_ball--;
        y_axi_ball--;

    ClearScreen();
    
  }
 }
 screen(left_pad, right_pad, x_axi_ball, y_axi_ball, shirinapolya,
           visotapolya, score_1st_player, score_2nd_player);
}

  void ClearScreen(void) { printf("\033[H\033[2J"); }

  void screen(int left_pad, int right_pad, int x_axi_ball, int y_axi_ball,
              int shirinapolya, int visotapolya, int score_1st_player,
              int score_2nd_player) {
    for (int i = 0; i <= visotapolya; i++) {
      for (int j = 0; j <= shirinapolya; j++) {
        if ((i == 0 || i == visotapolya) && j != 0 && j <= shirinapolya - 1) {
          printf("-");
        } else if ((j == 0 || j == shirinapolya) && i < visotapolya + 1) {
          printf("|");
        } else if (i >= left_pad && i < left_pad + 3 && j == 3) {
          printf("*");
        } else if (i >= right_pad && i < right_pad + 3 &&
                   j == shirinapolya - 3) {
          printf("*");
        } else if (i == y_axi_ball && j == x_axi_ball) {
          printf("o");
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