#include <bits/stdc++.h>
using namespace std;

const int N = 52;
int G[N][N];
int n;
char s[10];

int getID(char a1, char a2) {
  return (a1 - 'A') * 2 + (a2 == '+' ? 1 : 0);
}

void connect(char a1, char a2, char b1, char b2) {
  if (a1 == '0' || b1 == '0') return;
  int id1 = getID(a1, a2), id2 = getID(b1, b2);
  G[id1 ^ 1][id2] = 1;
}

int vis[N];

bool dfs(int u) {
  vis[u] = -1;
  for (int v = 0; v < 52; v++) {
    if (G[u][v]) {
      if (vis[v] == -1) return false;
      else if (!vis[v] && !dfs(v)) return false;
    }
  }
  vis[u] = 1;
  return true;
}

bool find_cycle() {
  memset(vis, 0, sizeof(vis));  
  for (int i = 0; i < 52; i++) {
    if (!vis[i]) {
      if (!dfs(i)) return true;
    }
  }
  return false;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    memset(G, 0, sizeof(G));
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) if (i != j) {
          connect(s[i << 1], s[(i << 1) + 1], s[j << 1], s[(j << 1) + 1]);
        }
      }
    }
    
    if (find_cycle()) puts("unbounded");
    else puts("bounded");
  }
  
  
  return 0;
}