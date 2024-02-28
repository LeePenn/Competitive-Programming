// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 64 + 4;
int n;
char grid[N][N];

void calc(int r, int c, int len, vector<int>& ans, int path = 0, int p5 = 1) {
  int black = 0;
  for (int i = r; i < r + len; i++) {
    for (int j = c; j < c + len; j++) {
      if (grid[i][j] == '1') black++;
    }
  }
  if (!black) return;
  if (black == len * len) { ans.push_back(path); return; }
  len /= 2;
  calc(r, c, len, ans, path + p5, p5 * 5);
  calc(r, c + len, len, ans, path + p5 * 2, p5 * 5);
  calc(r + len, c, len, ans, path + p5 * 3, p5 * 5);
  calc(r + len, c + len, len, ans, path + p5 * 4, p5 * 5);
}

void draw(int r, int c, int len, int p) {
  if (!p) {
    for (int i = r; i < r + len; i++) {
      for (int j = c; j < c + len; j++) grid[i][j] = '*';
    }
    return;
  }
  len /= 2;
  int np = p % 5;
  p /= 5;
  if (np == 1) draw(r, c, len, p);
  if (np == 2) draw(r, c + len, len, p);
  if (np == 3) draw(r + len, c, len, p);
  if (np == 4) draw(r + len, c + len, len, p);
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int kase = 1; scanf("%d", &n) == 1 && n != 0; kase++) {
    if (kase > 1) puts("");
    printf("Image %d\n", kase);
    if (n > 0) {
      vector<int> ans;
      for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
      }
      calc(0, 0, n, ans);
      sort(ans.begin(), ans.end());
      int sz = (int)ans.size();
      for (int i = 0; i < sz; i++) printf("%d%s", ans[i], (i % 12 == 11 || i == sz - 1) ? "\n" : " ");
      printf("Total number of black nodes = %d\n", sz);
    } else {
      int p;
      memset(grid, 0, sizeof(grid));
      n = -n;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) grid[i][j] = '.';
      }
      while (scanf("%d", &p) == 1 && p != -1) draw(0, 0, n, p);
      for (int i = 0; i < n; i++) puts(grid[i]);
    }
  }
  
  return 0;
}