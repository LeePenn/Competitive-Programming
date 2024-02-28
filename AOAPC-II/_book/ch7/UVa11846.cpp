// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 20 + 2;
int n, k;
char G[N][N], ans[N][N];

bool dfs(const char c, int pos) {
  while (pos < n * n && ans[pos / n][pos % n] != '.') pos++;
  if (pos == n * n) return true;
  
  int x1 = pos / n, y1 = pos % n;
  for (int x2 = x1; x2 < n; x2++) {
    for (int y2 = y1; y2 < n; y2++) {
      int area = (x2 - x1 + 1) * (y2 - y1 + 1);
      if (area > 9 || ans[x2][y2] != '.') break;
      
      int lcnt = 0, ld = -1;
      bool used = false, not_suit = false;
      for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
          char ch = G[x][y];
          if (isdigit(ch)) {
            lcnt++;
            ld = ch - '0';
            if (lcnt > 1 || ld < area || (ld % (x2 - x1 + 1))) { not_suit = true; break; }
          } 
          if (ans[x][y] != '.') { used = true; break; }
        }
        if (used || not_suit) break;
      }
      if (not_suit || used) break; 
      if (lcnt == 0 || ld > area) continue;
      
      for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
          ans[x][y] = c;
        }
      }
      if (dfs(c + 1, pos + (y2 - y1 + 1))) return true;
      for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
          ans[x][y] = '.';
        }
      }
    }
  }
  return false;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d %d", &n, &k) == 2 && n && k) {
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) scanf(" %c ", &G[r][c]);
    }
    
    memset(ans, '.', sizeof(ans));
    dfs('A', 0);
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) putchar(ans[r][c]);
      puts("");
    }
  }
  
  
  return 0;
}