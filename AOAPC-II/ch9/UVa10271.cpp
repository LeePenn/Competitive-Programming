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
const int N = 5000 + 4;
int T, k, n;
int d[N], dp[N][N >> 1];
int mind[N][N], last[N][N];
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &k, &n);
    k += 8;
    for (int i = n; i >= 1; --i) {
        scanf("%d", &d[i]);
    }
    
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = 0x3f3f3f3f;
        }
    }
    
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i < j * 3) continue;
            
            dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (d[i] - d[i - 1]) * (d[i] - d[i - 1]));
        }
    }
    
    printf("%d\n", dp[n][k]);
  }
  
  

  return 0;
  
  
}