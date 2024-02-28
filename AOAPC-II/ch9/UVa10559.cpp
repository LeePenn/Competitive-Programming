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
const int N = 200 + 4;
int n, a[N], dp[N][N][N];
int DP(int l, int r, int k) {
    if (l > r) return 0;
    int &ans = dp[l][r][k];
    if (ans >= 0) return ans;
    int p = r;
    while (p >= 0 && a[p] == a[r]) p--;
    p++;
    ans = DP(l, p - 1, 0) + (r - p + k + 1) * (r - p + k + 1);
    
    for (int q = l; q < p; q++) {
        if (a[q] == a[r] && a[q + 1] != a[q]) {
            ans = max(ans, DP(l, q, r - p + k + 1) + DP(q + 1, p - 1, 0));
        }
    }
    return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  int T;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; ++kase) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
    printf("Case %d: %d\n", kase, DP(0, n - 1, 0));
  }
  

  return 0;
}