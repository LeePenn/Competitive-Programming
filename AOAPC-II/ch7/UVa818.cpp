// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 16;
int n, vis[N];
unordered_set<int> G[N];
bitset<N> open;

bool dfs(int u, int pu) {
  vis[u] = 1; // 判环
  int d = 0;
  for (const auto& v : G[u]) {
    if (open[v]) continue;
    if (++d > 2) return false; // 不能有分叉
    if (v != pu) {
      if (vis[v] || !dfs(v, u)) return false;
    }
  }
  return true;
}

int solve() {
  int ans = n;
  for (int bin = 0; bin < (1 << n); bin++) {
    open.reset();
    for (int i = 0; i < n; i++) 
      if (bin >> i & 1) open.set(i);
    int oc = open.count(), connected = 0;
    bool valid = true;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      if (!open[i] && !vis[i]) {
        if (++connected > oc + 1 || !dfs(i, -1)) { // 没个打开的环只能连最多oc + 1个连通分量
          valid = false;
          break;
        }
      }
    }
    if (valid) ans = min(ans, oc);
  }
  return ans;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int kase = 1; scanf("%d", &n) == 1 && n; kase++) {
    for (int i = 0; i < N; i++) G[i].clear();
    int x, y;
    while (scanf("%d %d", &x, &y) == 2 && x > 0 && y > 0) {
      x--; y--;
      G[x].insert(y); G[y].insert(x);
    }
    printf("Set %d: Minimum links to open is %d\n", kase, solve());
  }
  
  
  
  return 0;
}