// Joker
#include <bits/stdc++.h>
using namespace std;

int a[24];
int line[8][7] = {
  { 0, 2, 6, 11, 15, 20, 22},
  { 1, 3, 8, 12, 17, 21, 23},
  {10, 9, 8,  7,  6,  5,  4},
  {19,18,17, 16, 15, 14, 13},
};
const int rev[] = {5, 4, 7, 6, 1, 0, 3, 2};
const int center[] = {6, 7, 8, 11, 12, 15, 16, 17};
char ans[1000];
int maxd;

int h() {
  int cnt1, cnt2, cnt3;
  cnt1 = cnt2 = cnt3 = 0;
  for (int i = 0; i < 8; i++) {
    cnt1 += a[center[i]] == 1;
    cnt2 += a[center[i]] == 2;
    cnt3 += a[center[i]] == 3;
  }
  return min(8 - cnt1, min(8 - cnt2, 8 - cnt3));
}

bool check() {
  for (int i = 1; i < 8; i++) {
    if (a[center[i]] != a[center[0]]) return false;
  }
  return true;
}

void move(int cmd) {
  int tmp = a[line[cmd][0]];
  for (int i = 0; i < 6; i++) a[line[cmd][i]] = a[line[cmd][i + 1]];
  a[line[cmd][6]] = tmp;
}

bool dfs(int d) {
  
  if (d + h() > maxd) return 0;
  if (check()) {
    ans[d] = '\0';
    return 1;
  }
  for (int i = 0; i < 8; i++) {
    ans[d] = 'A' + i;
    move(i);
    if (dfs(d + 1)) return 1;
    move(rev[i]);
  }
  return 0;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int i = 4; i < 8; i++) {
    for (int j = 0; j < 7; j++) line[i][j] = line[rev[i]][6 - j];
  }
  
  while (scanf("%d", &a[0]) == 1 && a[0]) {
    for (int i = 1; i < 24; i++) scanf("%d", &a[i]);
    if (check()) printf("No moves needed\n");
    else {
      maxd = 1;
      while (!dfs(0)) maxd++;
      printf("%s\n", ans);
    }
    printf("%d\n", a[6]);
  }
  
  
  return 0;
}