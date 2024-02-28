#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 64 + 5;
int n, d, K[N];
ULL dp[N][N];
int zcnt = 0, ocnt = 0;
int z[N], o[N];
bool can_receive_zero(int i, int j) {
    /**!SECTION
     * i + 1 <= zcnt, i + 1 means zero cnt
     * j == ocnt, j means one cnt
     * o[j] + d >= z[i], i, j mean next zero, one launch time
    */
    return i + 1 <= zcnt && (j == ocnt || o[j + 1] + d >= z[i + 1]);
}
bool can_receive_one(int i, int j) {
    return j + 1 <= ocnt && (i == zcnt || z[i + 1] + d >= o[j + 1]);
}
void greed(ULL &minv, ULL &maxv) {
    minv = maxv = 0;
    int i = 0, j = 0;
    while (i < zcnt || j < ocnt) {
        if (can_receive_one(i, j)) {
            j++;
            maxv <<= 1;
            maxv += 1;
        } else {
            i++;
            maxv <<= 1;
        }
    }
    i = 0, j = 0;
    while (i < zcnt || j < ocnt) {
        if (can_receive_zero(i, j)) {
            i++;
            minv <<= 1;
        } else {
            j++;
            minv <<= 1;
            minv += 1;
        }
    }
}
void solve() {
    zcnt = ocnt = 0;
    memset(z, 0, sizeof(z));
    memset(o, 0, sizeof(o));
    for (int i = 0; i < n; ++i) {
        if (K[i] == 0) {
            z[++zcnt] = i + 1;
        } else {
            o[++ocnt] = i + 1;
        }
    }
    
    ULL minv, maxv;
    greed(minv, maxv);
    
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i <= zcnt; ++i) {
        for (int j = 0; j <= ocnt; ++j) {
            if (can_receive_zero(i, j)) dp[i + 1][j] += dp[i][j];
            if (can_receive_one(i, j)) dp[i][j + 1] += dp[i][j];
        }
    }
    
    cout << dp[zcnt][ocnt] << " " << minv << " " << maxv << endl;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  int kase = 0;
  ULL k;
  while (cin >> n >> d >> k) {
    for (int i = 0; i < n; ++i) {
        K[n - i - 1] = k % 2;
        k >>= 1;
    }
    cout << "Case " << ++kase << ": ";
    solve();
  }
  
  

  return 0;
}