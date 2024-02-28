// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 80 + 4;
int n, L, cnt;
char hard[N];

bool dfs(int cur) {
  if (cnt == n) {
    for (int i = 0; i < cur; i++) {
      if (i % 64 == 0 && i) {
        printf("\n");
      } else if (i % 4 == 0 && i) printf(" ");
      printf("%c", hard[i]);
    }
    printf("\n%d\n", cur);
    return 1;
  }
  
  for (int i = 0; i < L; i++) {
    hard[cur] = 'A' + i;
    bool ok = true;
    for (int j = 1; 2 * j <= cur + 1; j++) {
      bool same = true;
      for (int k = 1; k <= j; k++) {
        if (hard[cur - 2 * j + k] != hard[cur - j + k]) { same = false; break; }
      }
      if (same) { ok = false; break; }
    }
    if (ok) {
      cnt++;
      //printf("%s %d\n", hard, cnt + 1);
      if (dfs(cur + 1)) return 1;
    }
    //hard[cur] = 0; // 回溯！！！！！！！！！不然会影响之后的cur长度的获取
  }
  return 0;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d %d", &n, &L) == 2 && n && L) {
    memset(hard, 0, sizeof(hard));
    cnt = 0;
    dfs(0);
  }
  
  
  return 0;
}