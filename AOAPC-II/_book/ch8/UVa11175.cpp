// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 300 + 3;
vector<int> G[N], InvG[N];
int To[N];

bool check(int m) {
  for (int u = 0; u < m; u++) {
    fill_n(To, m, 0);
    for (auto v: InvG[u]) {
      for (auto x : G[v]) To[x]++;
    }
    
    for (int v = 0; v < m; v++) {
      if (To[v] == 0 || To[v] == InvG[u].size()) continue;
      return false;
    }
  }
  
  return true;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int N, m, k, x, y;
  scanf("%d", &N);
  for (int t = 1; t <= N; t++) {
    scanf("%d %d", &m, &k);
    for (int i = 0; i < m; i++) G[i].clear(), InvG[i].clear();
    for (int i = 0; i < k; i++) {
      scanf("%d %d", &x, &y);
      G[x].push_back(y);
      InvG[y].push_back(x);
    }
    bool valid = check(m);
    printf("Case #%d: %s\n", t, (valid ? "Yes" : "No"));
  }
  
  return 0;
}