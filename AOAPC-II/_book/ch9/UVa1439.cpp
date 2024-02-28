#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>

#define LL long long
using namespace std;
const int N = 15, M = 100 + 5;
int n, m, u[M], v[M], g[N][N];
int ind[1 << N], d[1 << N], best[1 << N], label[N];

bool independent(int mask) {
    for (int i = 0; i < N; ++i) if (mask & (1 << i)) {
        for (int j = 0; j < N; ++j) if (mask & (1 << j)) {
            if (i != j && g[i][j]) return false;
        }
    }
    
    return true;
}
int dp(int mask) {
    int &ans = d[mask];
    if (ans >= 0) return ans;
    if (mask == 0) return 0;
    ans = N + 1;
    for (int s = mask; s; s = (s - 1) & mask) {
        if (ind[s]) {
            int v = dp(mask ^ s) + 1;
            if (v < ans) {
                ans = v;
                best[mask] = s;
            }
        }
    }
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (scanf("%d", &m) == 1) {
    memset(g, 0, sizeof(g));
    int useful = 0;
    for (int i = 0; i < m; ++i) {
        char r1[9], r2[9];
        scanf("%s%s", r1, r2);
        u[i] = r1[0] - 'L', v[i] = r2[0] - 'L';
        g[u[i]][v[i]] = 1;
        useful |= (1 << u[i]);
        useful |= (1 << v[i]);
    }
    memset(ind, 0, sizeof(ind));
    for (int s = useful; s; (s - 1) & useful) {
        if (independent(s)) ind[s] = true;
    }
    
    memset(d, -1, sizeof(d));
    int ans = dp(useful);
  }
  
  

  return 0;
}