#include <bitset>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <queue>

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 10000 + 4, INF = INT_MAX;
int n, c1, c2, dp[N][4];
vector<int> g[N];
int min(int a, int b, int c) {
    return min(min(a, b), c);
}
int min(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}
void dfs(int u, int fa) {
    int *D = dp[u]; 
    int U1E = 0, minV0 = INF;
    memset(D, 0, sizeof(dp[u]));
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        int *DV = dp[v], w = min(DV[0], DV[1], DV[2]);
        D[0] += min(DV[0], DV[1], DV[2], DV[3]);
        D[1] += w;
        D[2] += DV[1];
        D[3] += w;
        U1E += w;
        minV0 = min(minV0, DV[0] - w);
    }
    D[0] += c2;
    D[1] = min(D[1] + c1, U1E + minV0);
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  int u, v;
  while (scanf("%d%d%d", &n, &c1, &c2) == 3 && n) {
    for (int i = 0; i <= n; ++i) g[i].clear();
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    printf("%d\n", min(dp[1][0], dp[1][1], dp[1][2]));
  }
  
  

  return 0;
  
  
}