// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 3;
const int INF = 1e9;

struct Edge {
  int u, v, c;
  Edge(int u = 0, int v = 0, int c = 0):u(u), v(v), c(c) {}
};

int n;
vector<Edge> edges;
vector<int> G[N];

void addEdge(int u, int v, int c) {
  int idx = edges.size();
  edges.push_back(Edge(u, v, c));
  G[u].push_back(idx);
}

int vis[N];
int d[N];

void rev_bfs() {
  memset(vis, 0, sizeof(vis));
  vis[n] = true;
  d[n] = 0;
  queue<int> q;
  q.push(n);
  while (q.size()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int e = G[u][i];
      int v = edges[e].v;
      if (vis[v]) continue;
      vis[v] = true;
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
}

vector<int> ans;

void bfs() {
  memset(vis, 0, sizeof(vis));
  vis[1] = 0;
  vector<int> nxt;
  nxt.push_back(1);
  ans.clear();
  for (int i = 0; i < d[1]; i++) {
    int min_color = INF;
    for (int j = 0; j < nxt.size(); j++) {
      int u = nxt[j];
      for (int k = 0; k < G[u].size(); k++) {
        int e = G[u][k];
        int v = edges[e].v;
        if (d[u] == d[v] + 1) 
          min_color = min(min_color, edges[e].c);
      }
    }
    ans.push_back(min_color);
    
    vector<int> nxt2;
    for (int j = 0; j < (int)nxt.size(); j++) {
      int u = nxt[j];
      for (int k = 0; k < G[u].size(); k++) {
        int e = G[u][k];
        int v = edges[e].v;
        if (vis[v]) continue;
        if (d[u] == d[v] + 1 && edges[e].c == min_color) {
          vis[v] = true;
          nxt2.push_back(v);
        }
      }
    }
    nxt = nxt2;
  }
  
  printf("%d\n", d[1]);
  printf("%d", ans[0]);
  for (int i = 1; i < ans.size(); i++) {
    printf(" %d", ans[i]);
  }
  printf("\n");
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int m, u, v, c;
  while (scanf("%d %d", &n, &m) == 2) {
    edges.clear();
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &u, &v, &c);
      addEdge(u, v, c); addEdge(v, u, c);
    }
    rev_bfs();
    bfs();
  }
  
  
  return 0;
}