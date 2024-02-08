// Joker
#include <bits/stdc++.h>
using namespace std;

const int R = 9;
char final_board[5][R + 2];
char board[5][R + 2];

bool check_same() {
  for (int i = 0; i < 5; i++) {
    if (strcmp(final_board[i], board[i]) != 0) return false;
  }
  return true;
}

bool prework() {
  char line[12];
  for (int i = 0; i < 5; i++) {
    fgets(line, 12, stdin);
    if (line[0] == '0') return false;
    for (int j = 0; j < R; j++) {
      final_board[i][j] = line[j];
    }
    final_board[i][R] = '\0';
  }
  memcpy(board, final_board, sizeof(final_board));
  for (int i = 0; i < 5; i++) {
    int len = strlen(final_board[i]);
    for (int j = 0; j < len; j++) board[i][j] = ' ';
  }
  //for (int i = 0; i < 5; i++) cout << final_board[i] << endl;
  //for (int i = 0; i < 5; i++) cout << board[i] << endl;
  return true;
}

bool dfs(int n) {
  if (n == 6) {
    if (!check_same()) return false;
    else return true;
  }
  if (check_same()) return true;
  
  char board_bak[5][R + 2];
  memcpy(board_bak, board, sizeof(board));
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      // draw verticle line
      for (int ri = r + 1; ri < r + 3; ri++) {
        board[ri][2 * c] = board[ri][2 * c + 4] = '|';
      }
      // draw horizon line
      for (int ci = c; ci < c + 2; ci++) {
        board[r][2 * ci + 1] = board[r + 2][2 * ci + 1] = '_';
      }
      // draw blank
      for (int ci = 2 * c + 1; ci < 2 * c + 4; ci++) {
        board[r + 1][ci] = ' ';
      }
      board[r + 2][2 * c + 2] = ' ';
      if (dfs(n + 1)) return true;
      memcpy(board, board_bak, sizeof(board_bak));
    }
  }
  return false;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int kase = 1; prework(); kase++) {
    printf("Case %d: ", kase);
    if (dfs(0)) printf("Yes\n");
    else printf("No\n");
  }
  
  
  
  return 0;
}