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
const int N = 20 + 1;
LL dp[N][N][N];
void init() {
  memset(dp, 0, sizeof(dp));
  dp[1][1][1] = 1, dp[2][1][2] = dp[2][2][1] = 1;
  
  for (int i = 3; i <= 20; ++i) {
    for (int j = 1; j <= i; ++j) {
      for (int k = 1; k <= i; ++k) {
        dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + 
        dp[i - 1][j][k] * (i - 2);
      }
    }
  }
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  
  init();
  int T;
  cin >> T;
  int n, l, r;
  while (T--) {
    cin >> n >> l >> r;
    cout << dp[n][l][r] << endl;
  }

  return 0;
}