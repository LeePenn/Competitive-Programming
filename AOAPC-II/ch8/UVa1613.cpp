// 每个v都至少和deg[u]个颜色不同的相邻 -> n一定是偶数
// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 10000 + 4;
int n, m, c[N];
vector<int> G[N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int a, b;
  for (int kase = 0; scanf("%d %d", &n, &m) == 2 && n && m; kase++) {
    if (kase) puts("");
    for (int i = 0; i < n; i++) G[i].clear();
    
    int k = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d %d", &a, &b);
      a--, b--;
      G[a].push_back(b), G[b].push_back(a);
      k = max(k, (int)G[a].size()), k = max(k, (int)G[b].size());
    }
    
    if (k % 2 == 0) k++;
    unordered_set<int> colors;
    for (int i = 1; i <= k; i++) colors.insert(i);
    memset(c, -1, sizeof(c));
    
    queue<int> q;
    q.push(0);
    c[0] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      auto cs = colors;
      for (auto v : G[u]) {
        if (c[v] > 0) cs.erase(c[v]);
        if (c[v] < 0) c[v] = 0, q.push(v);
      }
      c[u] = *(cs.begin());
    }
    printf("%d\n", k);
    for (int i = 0; i < n; i++) printf("%d\n", c[i]);
  }
  
  
  return 0;
}