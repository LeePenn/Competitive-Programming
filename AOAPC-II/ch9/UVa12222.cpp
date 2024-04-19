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
const int N = 200 + 3;
int T;
int n, n0, n1, t0[N], d0[N], t1[N], d1[N], dp[N][N][2];
int solve() {
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0] = dp[0][0][1] = 0;
  
  for (int i = 0; i <= n0; ++i) {
    for (int j = 0; j <= n1; ++j) {
      int st = dp[i][j][1], ed = 0;
      
      for (int k = i + 1; k <= n0; ++k) {
        st = max(st, t0[k]);
        ed = max(st + d0[k], ed);
        dp[k][j][0] = min(dp[k][j][0], ed);
        st += 10, ed += 10;
      }
      
      st = dp[i][j][0], ed = 0;
      for (int k = j + 1; k <= n1; ++k) {
        st = max(st, t1[k]);
        ed = max(st + d1[k], ed);
        dp[i][k][1] = min(dp[i][k][1], ed);
        st += 10, ed += 10;
      }
    }
  }
  
  return min(dp[n0][n1][0], dp[n0][n1][1]);
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    getchar();
    n0 = 0, n1 = 0;
    char c;
    for (int i = 1; i <= n; ++i) {
      c = getchar();
      if (c == 'A') {
        n0++;
        scanf("%d%d", &t0[n0], &d0[n0]);
      } else if (c == 'B') {
        n1++;
        scanf("%d%d", &t1[n1], &d1[n1]);
      }
      getchar();
    }
    // for (int i = 1; i <= n0; ++i) {
    //   printf("%d %d\n", t0[i], d0[i]);
    // }
    // printf("\n");
    // for (int i = 1; i <= n1; ++i) {
    //   printf("%d %d\n", t1[i], d1[i]);
    // }
    
    printf("%d\n", solve());
  }
  
  

  return 0;
  
  
}