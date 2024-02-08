// Joker
#include <bits/stdc++.h>
using namespace std;

struct Cube {
  char top, front;
  Cube(char t = 'E', char f = 'E'):top(t), front(f) {};
};
int ex, ey;
char final_board[3][3];
const char colors[] = "BWR";
Cube board[3][3];
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool inRange(int x, int l, int r) {
  if (l > r) return inRange(x, r, l);
  return x >= l && x < r;
}

void init_board(int ex, int ey) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == ey && j == ex) { Cube cub('E', 'E'); board[i][j] = cub; }
      else { Cube cub('W', 'R'); board[i][j] = cub; }
    }
  }
}

int check_same() {
  int ans = 0;
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (board[r][c].top != final_board[r][c]) ans++;
    }
  }
  return ans;
}

void VRoll(int cx, int cy, int ex, int ey) {
  char top = board[cx][cy].top, front = board[cx][cy].front;
  board[cx][cy].top = 'E', board[cx][cy].front = 'E';
  board[ex][ey].top = front, board[ex][ey].front = top;
}

void HRoll(int cx, int cy, int ex, int ey) {
  char top = board[cx][cy].top, front = board[cx][cy].front;
  char ntop = top ^ front ^ 'B' ^ 'W' ^ 'R';
  board[cx][cy].top = 'E', board[cx][cy].front = 'E';
  board[ex][ey].top = ntop, board[ex][ey].front = front;
}

void dfs(int d, int ex, int ey, int pex, int pey, int& ans) {
  if (check_same() == 0) {
    ans = min(ans, d);
    return;
  }
  if (d + check_same() > ans) return;
  
  Cube board_bak[3][3];
  memcpy(&board_bak, &board, sizeof(board)); 
  for (int dir = 0; dir < 4; dir++) {
    int cx = ex + dx[dir], cy = ey + dy[dir];
    if (cx == pex && cy == pey) continue;
    if (!inRange(cx, 0, 3) || !inRange(cy, 0, 3)) continue;
    if (dir == 0 || dir == 2) VRoll(cx, cy, ex, ey);
    else HRoll(cx, cy, ex, ey);
    dfs(d + 1, cx, cy, ex, ey, ans);
    memcpy(&board, &board_bak, sizeof(board_bak));
  }
}



int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  
  while (scanf("%d %d", &ex, &ey) == 2 && ex && ey) {
    ex--, ey--;
    init_board(ex, ey);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) scanf(" %c ", &final_board[i][j]);
    }
    
    int ans = 32;
    dfs(0, ey, ex, -1, -1, ans);
    
    if (ans <= 30) printf("%d\n", ans);
    else puts("-1");
  }
  
  return 0;
}