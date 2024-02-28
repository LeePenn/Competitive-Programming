// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, a[N];
int maxd;

bool dfs(int d) {
  if (a[d] == n) return 1;
  if (d == maxd) return 0;
  int maxv = a[0];
  for (int i = 1; i <= d; i++) maxv = max(maxv, a[i]);
  if ((maxv << (maxd - d)) < n) return 0;
  
  for (int i = d; i >= 0; i--) {
    a[d + 1] = a[d] + a[i];
    if (dfs(d + 1)) return 1;
    a[d + 1] = a[d] - a[i];
    if (dfs(d + 1)) return 1;
  }
  return 0;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  a[0] = 1;
  while (scanf("%d", &n) == 1 && n) {
    maxd = 0;
    while (!dfs(0)) maxd++;
    printf("%d\n", maxd);
  }
  
  
  return 0;
}