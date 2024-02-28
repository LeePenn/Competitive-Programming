#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

using namespace std;
const int N = 1e5 + 3;
int n, T;
struct Edge {
  int u, v, to;
  Edge(int u, int v, int to): u(u), v(v), to(to) {}
  Edge() { u = v = to = 0; }
}e[N << 1];
int tot, hd[N];
int dp[N];

void add_edge(int u, int v) {
  e[++tot] = Edge(u, v, hd[u]);
  hd[u] = tot;
}

int DP(int u, int p) {
  int cnt = 0;
  
  vector<int> ch;
  for (int i = hd[u]; i; i = e[i].to) {
    int v = e[i].v;
    if (v == p) continue;
    cnt++;
    
    ch.push_back(DP(v, u));
  }
  if (!cnt) return 1;
  
  sort(ch.begin(), ch.end());
  int num = (cnt * T + 99) / 100;
  int ret = 0;
  for (int i = 0; i < num; ++i) ret += ch[i];
  return ret;
  
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
    
  while (scanf("%d%d", &n, &T) == 2 && (n || T)) {
    tot = 0;
    memset(hd, 0, sizeof(hd));
    memset(dp, 0x3f, sizeof(dp));
    int x;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x);
      add_edge(i, x); add_edge(x, i);
    }
    
    printf("%d\n", DP(0, -1));
  }


  return 0;
}