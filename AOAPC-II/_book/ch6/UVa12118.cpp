// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 3;
vector<int> V[N];
int v, e, t;
bool vis[N];

void dfs(int u, int& sp) {
  vis[u] = 1;
  sp += V[u].size() % 2;
  for (auto y : V[u]) {
    if (vis[y]) continue;
    dfs(y, sp);
  }
}


int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int kase = 1; scanf("%d %d %d", &v, &e, &t) == 3 && (v || e || t); kase++) {
    for (int i = 0; i < v; i++) V[i].clear();
    for (int i = 0; i < e; i++) {
      int x, y;
      cin >> x >> y;
      V[x - 1].push_back(y - 1); V[y - 1].push_back(x - 1);
    }
    
    memset(vis, 0, sizeof(vis));
    int ans = 0, nc = 0;
    for (int i = 0; i < v; i++) {
      if (vis[i] || V[i].empty()) continue;
      int sp = 0;
      dfs(i, sp);
      if (sp > 2) ans += (sp - 2) / 2;
      nc++;
    }
    printf("Case %d: %d\n", kase, t * (e + ans + max(0, nc - 1)));
  }
  
  return 0;
}