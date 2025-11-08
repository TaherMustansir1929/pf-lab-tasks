#include <stdio.h>

int main() {
  char board[3][3];
  int i, j;
  int x_win = 0;
  int o_win = 0;

  // init board
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }

  printf("Tic Tac Toe\n\n");

  int turn;
  char player = 'X';

  for (turn = 0; turn < 9; turn++) {

    printf("\nBoard\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);

    printf("\nPlayer %c turn\n", player);

    int r, c;
    printf("Enter row (0-2): ");
    scanf("%d", &r);
    printf("Enter col (0-2): ");
    scanf("%d", &c);

    if (r < 0 || r > 2 || c < 0 || c > 2 || board[r][c] != ' ') {
      printf("Bad move, try again\n");
      turn--; // repeat this turn
      continue;
    }

    board[r][c] = player;

    // check win
    x_win = 0;
    o_win = 0;

    for (i = 0; i < 3; i++) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
          board[i][0] != ' ') {
        if (board[i][0] == 'X')
          x_win = 1;
        if (board[i][0] == 'O')
          o_win = 1;
      }
    }

    for (j = 0; j < 3; j++) {
      if (board[0][j] == board[1][j] && board[1][j] == board[2][j] &&
          board[0][j] != ' ') {
        if (board[0][j] == 'X')
          x_win = 1;
        if (board[0][j] == 'O')
          o_win = 1;
      }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
        board[0][0] != ' ') {
      if (board[0][0] == 'X')
        x_win = 1;
      if (board[0][0] == 'O')
        o_win = 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
        board[0][2] != ' ') {
      if (board[0][2] == 'X')
        x_win = 1;
      if (board[0][2] == 'O')
        o_win = 1;
    }

    // if win, break
    if (x_win == 1) {
      printf("\nX wins\n");
      break;
    }
    if (o_win == 1) {
      printf("\nO wins\n");
      break;
    }

    // switch player
    if (player == 'X') {
      player = 'O';
    } else {
      player = 'X';
    }
  }

  // final board
  printf("\nFinal Board\n");
  printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);

  if (turn == 9 && x_win == 0 && o_win == 0) {
    printf("\nDraw\n");
  }

  return 0;
}