// Joker
#include <bits/stdc++.h>
using namespace std;

const int V = 20 + 2;
int n, fa[V];
set<int> G[V];
bool vis[V];
int cnt;

int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}

void dfs(int u, vector<int>& ans) {
  if (u == n) {
    bool first = true;
    for (const auto& v : ans) {
      if (first) { first = false; printf("%d", v); }
      else printf(" %d", v);
    }
    puts("");
    cnt++;
    return;
  }
  
  vis[u] = 1;
  for (set<int>::const_iterator cit = G[u].begin(); cit != G[u].end(); cit++) {
    if(vis[*cit]) continue;
    ans.push_back(*cit);
    dfs(*cit, ans);
    ans.pop_back();
  }
  vis[u] = 0;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int kase = 1; scanf("%d", &n) == 1 && n; kase++) {
    for (int i = 0; i < V; i++) { G[i].clear(); fa[i] = i; }
    int u, v;
    while (scanf("%d %d", &u, &v) == 2 && u && v) {
      G[u].insert(v); G[v].insert(u);
      int fu = find(u), fv = find(v);
      if (fu != fv) fa[fu] = fv;
    }
    printf("CASE %d:\n", kase);
    if (find(fa[1]) != find(fa[n]))
      printf("There are 0 routes from the firestation to streetcorner %d.\n", n);
    else {
      cnt = 0;
      vector<int> ans;
      ans.push_back(1);
      memset(vis, 0, sizeof(vis));
      dfs(1, ans);
      printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, n);
    }
  }
  
  
  
  return 0;
}