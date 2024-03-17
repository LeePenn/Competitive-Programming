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
const int N = 10000 + 3, INF = 0x3f3f3f3f;
int n, dp[2][N][2];
int pos[N], dt[N];
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (cin >> n && n) {
    for (int i = 0; i < n; ++i) {
        cin >> pos[i] >> dt[i];
    }
    // dp[i][j][0] 在 i 并拿完 i - j所有财宝的最少时间
    memset(dp, 0, sizeof(dp));
    int cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            // cur ^ 1 => i + 1
            // (i + 1, j) => (i, j)
            int &d0 = dp[cur][j][0];
            d0 = min(dp[cur ^ 1][j][0] + pos[i + 1] - pos[i], dp[cur ^ 1][j][1] + pos[j] - pos[i]);
            if (d0 >= dt[i]) d0 = INF;
            // (i, j - 1) => (i, j)
            int &d1 = dp[cur][j][1];
            d1 = min(dp[cur][j - 1][0] + pos[j] - pos[i], dp[cur][j - 1][1] + pos[j] - pos[j - 1]);
            if (d1 >= dt[j]) d1 = INF;
        }
        cur ^= 1;
    }
    int ans = min(dp[cur ^ 1][n - 1][0], dp[cur ^ 1][n - 1][1]);
    if (ans == INF) cout << "No solution" << endl;
    else cout << ans << endl;
    
  }
  
  

  return 0;
  
  
}