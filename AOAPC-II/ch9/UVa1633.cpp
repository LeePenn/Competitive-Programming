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
const int N = 400 + 4, K = 10; 
LL MOD = 1e9 + 7;
int T, n, k, P[1 << (K + 1)], P1[1 << (K + 1)];
LL dp[N][1 << K];
void dfsP(int i, int j) {
  if (i == k) {
    P[j] = 1;
    return;
  }
  if (i == k + 1) {
    P1[j] = 1;
    return;
  }
  dfsP(i + 2, j << 1);
  dfsP(i + 2, ((1 << (i + 1)) | 1) | (j << 1));
}
void init() {
  memset(P, 0, sizeof(P));
  memset(P1, 0, sizeof(P1));
  memset(dp, -1, sizeof(dp));
  dfsP(1, 0);
  dfsP(1, 1);
  dfsP(2, 0);
  dfsP(2, 3);
}
LL pow_mod(LL x, int p) {
  if (p == 0) return 1;
  LL ans = pow_mod(x, p / 2);
  ans = (ans * ans) % MOD;
  if (p & 1) ans *= x;
  return ans % MOD;
}
LL DP(int i, int b) {
  LL &d = dp[i][b];
  if (d != -1) return d;
  if (i == n) return d = 1;
  
  d = 0;
  int nb = b << 1;
  if (!P1[nb] && !P[nb & ((1 << k) - 1)]) {
    d = (d + DP(i + 1, nb & ((1 << k) - 1))) % MOD;
  }
  nb = b << 1 | 1;
  if (!P1[nb] && !P[nb & ((1 << k) - 1)]) {
    d = (d + DP(i + 1, nb & ((1 << k) - 1))) % MOD;
  }
  return d;
  
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  cin >> T;
  while (T--) {
    cin >> n >> k;
    if (k > n) {
      cout << pow_mod(2, n) << endl;
      continue;
    }
    init();
    LL ans = 0;
    for (int i = 0; i < (1 << k); ++i) {
      // k 位 ，前 k 位为 i
      if (!P[i]) {
        ans = (ans + DP(k, i)) % MOD;
      }
    }
    cout << ans << endl;
  }
  
  
  

  return 0;
  
  
}