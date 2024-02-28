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
const int N = 100 + 5;
char area[N];
int n, m, T, kase;
int g[N][N];
int dp[N][N];
int vis[N][N];
int dirs[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};
int DP(int r, int c) {
    int &ans = dp[r][c];
    if (vis[r][c] == kase) return dp[r][c];
    
    vis[r][c] = kase;
    ans = 1;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dirs[i][0], nc = c + dirs[i][1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] < g[r][c]) {
            ans = max(ans, DP(nr, nc) + 1);
        }
    }
    return ans;
}
void solve() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j] != kase) {
                ans = max(ans, DP(i, j));
            }
        }
    }
    printf("%s: %d\n", area, ans);
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  scanf("%d", &T);
  memset(dp, -1, sizeof(dp));
  memset(vis, 0, sizeof(vis));
  for (kase = 1; kase <= T; ++kase) {
    scanf("%s%d%d", area, &n, &m);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &g[i][j]);
        }
    }
    
    solve();
  }
  
  

  return 0;
}