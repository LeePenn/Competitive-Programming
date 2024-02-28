// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 103;
char grid[N][N];
int n, m;

bool inRange(int r, int c) {
  return r >= 0 && r < m && c >= 0 && c < n;
}

void dfs(int r, int c) {
  if (!inRange(r, c) || grid[r][c] == '*') return;
  grid[r][c] = '*';
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int nr = r + i, nc = c + j;
      dfs(nr, nc);
    }
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (cin >> m >> n && m && n) {
    for (int i = 0; i < m; i++) {
      scanf("%s", grid[i]);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '@') {
          cnt++;
          dfs(i, j);
        }
      }
    }
    cout << cnt << endl;
  }
  
  
  return 0;
}