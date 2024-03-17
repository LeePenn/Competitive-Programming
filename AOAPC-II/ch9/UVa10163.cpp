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
const int N = 100 + 3, M = 30 + 2, P = 1000 + 3;
int n, m;
int p[M];
int dp[N][M];
int dg[N][M];
int sum[M];
void solve() {
    memset(dp, 0, sizeof(dp));
    memset(dp[0], 0x3f, sizeof(dp[0]));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) {
                dp[i][j] = p[j];
                continue;
            }
            dp[i][j] = dp[i][j - 1];
            for (int k = 0; k < i; ++k) {
                int t = min(dp[k][j - 1], p[j] / (i - k));
                dp[i][j] = max(dp[i][j], t);
            }
        }
    }
    
    int mx = dp[n][m];
    if (mx == 0) {
        cout << "0 0" << endl;
        return;
    }

    memset(dg, 0x3f, sizeof(dg));
    memset(dg[0], 0, sizeof(dg[0]));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j == 1) {
                if (p[j] / i >= mx) {
                    dg[i][j] = p[j];
                } else dg[i][j] = 0x3f3f3f3f;
                continue;
            }
            
            dg[i][j] = dg[i][j - 1];
            for (int k = 0; k < i; ++k) {
                if (p[j] / (i - k) >= mx) {
                    dg[i][j] = min(dg[i][j], dg[k][j - 1] + p[j]);
                }
            }
        }
    }
    
    cout << dp[n][m] << " " << dg[n][m] << endl;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (cin >> n >> m && (n || m)) {
    sum[0] = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    solve();
  }
  
  

  return 0;
  
  
}