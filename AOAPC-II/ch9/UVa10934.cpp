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
int k;
LL n;
LL dp[100 + 3][70];
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= 65; ++i) dp[1][i] = i;
  for (int i = 2; i <= 100; ++i) {
    for (int j = 1; j <= 63; ++j) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
    }
  }
//   printf("%lld\n", dp[63][1]);
//   exit(0);
  
  while (scanf("%d%lld", &k, &n) == 2 && k) {
    bool found = 0;
    for (int i = 1; i <= 63; ++i) {
        if (dp[k][i] >= n) {
            printf("%d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) printf("More than 63 trials needed.\n");
  }
  
  
  

  return 0;
}