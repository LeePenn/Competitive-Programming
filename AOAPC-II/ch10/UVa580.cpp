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
#include <set>

typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
const int N = 30 + 2;
int dp[N][3];
int n;
int fac[N];
void init() {
  fac[0] = 1;
  for (int i = 1; i <= 30; ++i) {
    fac[i] = fac[i - 1] * 2;
  }
}
void DP() {
  memset(dp, 0, sizeof(dp));
  dp[1][0] = dp[1][1] = 1; dp[1][2] = 0;
  dp[2][0] = 2; dp[2][1] = dp[2][2] = 1;
  
  for (int i = 3; i <= 30; ++i) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
    dp[i][1] = dp[i - 1][0];
    dp[i][2] = dp[i - 1][1];
  }
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  init();
  DP();
  while (scanf("%d", &n) == 1 && n) {
    printf("%d\n", fac[n] - dp[n][0] - dp[n][1] - dp[n][2]);
  }

  return 0;
}