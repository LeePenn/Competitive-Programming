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
const int N = 100 + 4;
int kase, n;
int p[N], v[N];
int dp[N][N][N][2];
int vis[N][N][N][2];

int DP(int l, int r, int k, int pos) {
    if (k == 0) return 0;
    int &ans = dp[l][r][k][pos];
    if (vis[l][r][k][pos] == kase) return ans;
    
    vis[l][r][k][pos] = kase;
    ans = 0;
    if (!pos) {
        for (int s = l - 1; s >= 0; --s) {
            ans = max(ans, v[s] - abs(p[s] - p[l]) * k + DP(s, r, k - 1, 0));
        }
        for (int e = r + 1; e < n; ++e) {
            ans = max(ans, v[e] - abs(p[e] - p[l]) * k + DP(l, e, k - 1, 1));
        }
    } else {
        for (int s = l - 1; s >= 0; --s) {
            ans = max(ans, v[s] - abs(p[s] - p[r]) * k + DP(s, r, k - 1, 0));
        }
        for (int e = r + 1; e < n; ++e) {
            ans = max(ans, v[e] - abs(p[e] - p[r]) * k + DP(l, e, k - 1, 1));
        }
    }
    return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  int T;
  scanf("%d", &T);
  memset(vis, 0, sizeof(vis));
  for (kase = 1; kase <= T; ++kase) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    
    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 0; i < n; ++i) {
            ans = max(ans, v[i] - abs(p[i]) * k + DP(i, i, k - 1, 0));
        }
    }
    printf("%d\n", ans);
  }
  
  

  return 0;
}