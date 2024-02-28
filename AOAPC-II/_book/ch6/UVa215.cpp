// Joker
#include <bits/stdc++.h>
using namespace std;

const int R = 20 + 2, C = 10 + 2;
char E[R][C][75 + 5];
int r, c, V[R][C], vis[R][C];

bool eval(int r, int c) {
  const char* p = E[r][c];
  if (vis[r][c] == -1) return false;
  if (vis[r][c] == 1) return true;
  vis[r][c] = -1;
  int sign = 1, &num = V[r][c];
  num = 0;
  while (*p) {
    if (*p == '+') { sign = 1; p++; }
    else if (*p == '-') { sign = -1; p++; }
    else if (isdigit(*p)) {
      int cur_val = 0;
      auto curp = p;
      while (isdigit(*curp)) {
        cur_val = cur_val * 10 + (*curp - '0');
        curp++;
      }
      num += sign * cur_val;
      sign = 1;
      p = curp;
    } else {
      int refR = *p++ - 'A', refC = *p++ - '0';
      if (!eval(refR, refC)) return false;
      num += sign * V[refR][refC];
      sign = 1;
    }
  }
  
  vis[r][c] = 1;
  return true;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d %d", &r, &c) == 2 && r && c) {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) scanf("%s", E[i][j]);
    }
    
    bool ok = true;
    memset(V, 0, sizeof(V));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (eval(i, j)) continue;
        ok = false;
        printf("%c%d: %s\n", i + 'A', j, E[i][j]);
      }
    }
    
    if (ok) {
      printf(" ");
      for (int j = 0; j < c; j++) printf("%6d", j);
      puts("");
      for (int i = 0; i < r; i++) {
        printf("%c", i + 'A');
        for (int j = 0; j < c; j++) printf("%6d", V[i][j]);
        puts("");
      }
    }
    puts("");
  }
  
  return 0;
}