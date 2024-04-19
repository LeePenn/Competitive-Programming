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

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 500 + 3;
int dp[N][N];
int ops[N][N], valid[N][N];
int num[N];
int n, a[N];
void init() {
  memset(dp, 0x3f, sizeof(dp));
  memset(ops, -1, sizeof(ops));
  memset(valid, -1, sizeof(valid));
  
  for (int i = 1; i <= n; ++i) {
    bool has_one = false;
    for (int j = 1; j <= n; ++j) num[j] = 0;
    
    for (int j = i; j <= n; ++j) {
      int cur = a[j];
      
      if (num[cur]) break;
      
      if (has_one && cur == 1) break;
      
      if (cur == 1) has_one = 1;
      
      if (i == j) {
        ops[i][j] = 0;
        num[cur] = 1;
      } else {
        int tot = j - i;
        int low = 0;
        for (int k = 1; k < cur; ++k) {
          if (num[k]) low++;
        }
        // if (i == 4 && j == 6) {
        //   printf("!!!!!!!!!!!!!\n");
        //   printf("## %d %d %d\n", low, tot, ops[i][j - 1]);
        // }
        if (!low) {
          ops[i][j] = tot + ops[i][j - 1];
          num[cur] = 1;
        } else {
          ops[i][j] = tot - low + 1 + ops[i][j - 1];
          num[cur] = 1;
        }
      }
      if (has_one) {
        valid[i][j] = ops[i][j];
      }
    }
  }
}
int DP(int l, int r) {
  if (valid[l][r] > 0) return dp[l][r] = valid[l][r];
  if (l == r) return 0x3f3f3f3f;
  
  if (dp[l][r] != 0x3f3f3f3f) return dp[l][r];
  
  for (int k = l; k < r; ++k) {
    dp[l][r] = min(dp[l][r], DP(l, k) + DP(k + 1, r));
  }
  
  return dp[l][r];
}
int solve() {
  init();
  
  DP(1, n);
  
  if (dp[1][n] == 0x3f3f3f3f) return -1;
  return dp[1][n];
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    
    int ans = solve();
    
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= n; ++j) {
    //     printf("!! i = %d, j = %d, ops[%d][%d] = %d\n", i, j, i, j, ops[i][j]);
    //   }
    // }
    if (ans == -1) printf("impossible\n");
    else printf("%d\n", ans);
  }
  
  

  return 0;
  
  
}