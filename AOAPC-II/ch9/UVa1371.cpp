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
const int N1 = 50 + 3, N2 = 5000 + 3;
int T;
char B[N1], A[N2];
int n, m;
int dp[N2][N1];

void update(int i, int j, int val) {
  dp[i][j] = min(dp[i][j], val);
}

bool check(int mid) {
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
    
  for (int i = 0; i <= n; ++i) {
    if (dp[i][m] <= mid) dp[i][0] = 0;
    for (int j = 0; j <= m; ++j) {
      int d = dp[i][j];
      update(i + 1, j + 1, d + (A[i + 1] != B[j + 1]));
      update(i, j + 1, d + 1); update(i + 1, j, d + 1);
    }
  }
  
  return dp[n][m] <= mid;
}
int solve() {
  int l = 0, r = m;
  int ans = m;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
        ans = mid;
        r = mid - 1;
    } else l = mid + 1;
  }
  
  return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%s", B + 1);
    scanf("%s", A + 1);
    m = strlen(B + 1), n = strlen(A + 1);
    printf("%d\n", solve());
  }
  
  

  return 0;
  
  
}