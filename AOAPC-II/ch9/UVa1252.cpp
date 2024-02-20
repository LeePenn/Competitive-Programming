#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;
const int N = 128, M = 11;
int kase, n, m;
char ob[N][M + 100];

int vis[1 << M][1 << M], dp[1 << M][1 << M];
int cnt[1 << M][1 << M];

int DP(int s, int f) {
    if (cnt[s][f] <= 1) return 0;
    if (cnt[s][f] == 2) return 1;
    
    if (vis[s][f] == kase) return dp[s][f];
    
    vis[s][f] = kase;
    int &ans = dp[s][f];
    ans = m;
    for (int i = 0; i < m; ++i) {
        if (s & (1 << i)) continue;
        int s1 = s | (1 << i), f1 = f | (1 << i);
        if (cnt[s1][f1] >= 1 && cnt[s1][f] >= 1) {
            ans = min(ans, max(DP(s1, f), DP(s1, f1)) + 1);
        }
    }
    return ans;
}
void Init() {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
        int feature = 0;
        for (int j = 0; j < m; ++j) {
            if (ob[i][j] == '1') feature |= 1 << j;
        }
        for (int j = 0; j < (1 << m); ++j) {
            cnt[j][j & feature]++;
        }
    }
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
      
  memset(vis, 0, sizeof(vis));
  while (cin >> m >> n && n) {
    kase++;
    for (int i = 1; i <= n; ++i) cin >> ob[i];
    Init();
    cout << DP(0, 0) << endl;
  }
  

  return 0;
}