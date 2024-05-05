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
const int N = 1000 + 2, M = 10056;
int n;
int C[N][N];
int dp[N];
void init() {
  C[1][0] = C[1][1] = 1;
  for (int i = 2; i <= 1000; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
    }
  }
  
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i] = (dp[i] + C[i][j] * dp[i - j]) % M;
    }
  }
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  init();
  int T, kase = 1;
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("Case %d: %d\n", kase, dp[n]);
    kase++;
  }
  

  return 0;
}