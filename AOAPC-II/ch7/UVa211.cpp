// Joker
#include <bits/stdc++.h>
using namespace std;

int domino[7][8], ans[7][8];
bool vis[7][8];
map<int, int> domino2id;
set<int> used;
int cnt;

int encode(int x, int y) {
  return x * 6 + y;
}

bool prework() {
  int x;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 8; j++) {
      if (scanf("%d", &x) != 1) return false;
      domino[i][j] = x;
    }
  }
  return true;
}

void dfs(int n, int r) {
  if (n == 28) {
    for (int i = 0; i < 7; i++) {
      printf(" ");
      for (int j = 0; j < 8; j++) {
        printf("%4d", ans[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    cnt++;
    return;
  }
  
  int c = 0;
  while (r < 7 && vis[r][c]) {
    c++;
    if (c == 8) { r++; c = 0; }
  }
  if (r == 7) return;
  
  // try horizon
  if (c + 1 < 8 && !vis[r][c] && !vis[r][c + 1]) {
    int x = domino[r][c], y = domino[r][c + 1];
    if (x >= y) swap(x, y);
    int code = encode(x, y);
    if (!used.count(code)) {
      used.insert(code);
      vis[r][c] = vis[r][c + 1] = 1;
      ans[r][c] = ans[r][c + 1] = domino2id[code];
      dfs(n + 1, r);
      used.erase(code);
      vis[r][c] = vis[r][c + 1] = 0;
    }
  }
  
  // try verticle
  if (r + 1 < 7 && !vis[r][c] && !vis[r + 1][c]) {
    int x = domino[r][c], y = domino[r + 1][c];
    if (x >= y) swap(x, y);
    int code = encode(x, y);
    if (!used.count(code)) {
      used.insert(code);
      vis[r][c] = vis[r + 1][c] = 1;
      ans[r][c] = ans[r + 1][c] = domino2id[code];
      dfs(n + 1, r);
      used.erase(code);
      vis[r][c] = vis[r + 1][c] = 0;
    } 
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int num = 1;
  for (int i = 0; i < 7; i++) {
    for (int j = i; j < 7; j++) {
      domino2id[encode(i, j)] = num++;
    }
  }
  
  for (int kase = 1; prework(); kase++) {
    if (kase > 1) printf("\n\n\n");
    printf("Layout #%d:\n\n", kase);
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) printf("%4d", domino[i][j]);
      printf("\n");
    }
    printf("\nMaps resulting from layout #%d are:\n\n", kase);
    
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    used.clear();
    dfs(0, 0);
    printf("There are %d solution(s) for layout #%d.\n", cnt, kase);
  }
  
  
  
  return 0;
}