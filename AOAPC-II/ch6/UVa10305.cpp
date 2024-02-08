// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 3;
int n, m;
int edge[N][N];
int v[N];
int ans[N], t;

bool dfs(int u) {
  v[u] = -1;
  for (int i = 1; i <= n; i++) {
    if (edge[u][i]) {
      if (v[i] == -1) return false;
      else if (!v[i] && !dfs(i)) return false;
    }
  }
  v[u] = 1;
  ans[t--] = u;
  return true;
}

bool topo() {
  memset(v, 0, sizeof(v));
  memset(ans, 0, sizeof(ans));
  t = n;
  for (int i = 1; i <= n; i++) {
    if (!v[i]) {
      if (!dfs(i)) return false;
    }
  }
  return true;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d%d", &n, &m) == 2 && n) {
    memset(edge, 0, sizeof(edge));
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u][v] = 1;
    }
    
    
    if (topo()) {
      for (int i = 1; i < n; i++) printf("%d ", ans[i]);
      printf("%d\n", ans[n]);
    } else printf("No\n");
  }
  
  return 0;
}