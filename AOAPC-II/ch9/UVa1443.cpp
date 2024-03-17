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
const int N = 40000 + 4, M = 10000 + 4, D = 10000 + 4, INF = 0x3f3f3f3f;
int T, n, m, d, sum[N], t, dp[N][2];
bool check(int mid) {
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 2; i <= n; i += 2) {
        for (int len = 1; len <= d && len <= (i >> 1); ++len) {
            if (sum[i] - sum[i - len] > mid) break;
            if (sum[i - len] - sum[i - len * 2] > mid) continue;
            dp[i][0] = min(dp[i][0], dp[i - 2 * len][1] + 1);
            dp[i][1] = min(dp[i][1], dp[i - 2 * len][0] + 1);
        }
    }
    return dp[n][(m - 1) & 1] < m;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        sum[i] = sum[i - 1] + t;
    }
    if ((n & 1) || n > 2 * d * (m - 1) || n < 2 * (m - 1)) {
        printf("BAD\n");
        continue;
    }
    
    int left = 1, right = sum[n];
    while (left < right) {
        int mid = (left + right) >> 1;
        if (check(mid)) right = mid;
        else left = mid + 1;
    }
    printf("%d\n", left);
  }
  
  

  return 0;
  
  
}