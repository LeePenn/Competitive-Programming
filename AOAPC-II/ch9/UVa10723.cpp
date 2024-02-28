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
const int N = 30 + 5;
int T, kase;
char s1[N], s2[N];
LL dp[N][N], cnt[N][N];
void update(LL &v1, LL &v2, LL &c1, LL &c2) {
    if (v1 > v2 + 1) {
        v1 = v2 + 1;
        c1 = c2;
    } else if (v1 == v2 + 1) {
        c1 += c2;
    }
}
void solve() {
    memset(dp, 0x3f, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    cnt[0][0] = 1;
    dp[0][0] = 0;
    int l1 = strlen(s1 + 1), l2 = strlen(s2 + 1);
    for (int i = 0; i <= l1; ++i) {
        for (int j = 0; j <= l2; ++j) {
            if (!i) {
                dp[i][j] = j;
                cnt[i][j] = 1;
                continue;
            }
            if (!j) {
                dp[i][j] = i;
                cnt[i][j] = 1;
                continue;
            }
            if (s1[i] == s2[j]) {
                update(dp[i][j], dp[i - 1][j - 1], cnt[i][j], cnt[i - 1][j - 1]);
            } else {
                update(dp[i][j], dp[i - 1][j], cnt[i][j], cnt[i - 1][j]);
                update(dp[i][j], dp[i][j - 1], cnt[i][j], cnt[i][j - 1]);
            }
        }
    }
    cout << "Case #" << kase << ": " << dp[l1][l2] << " " << cnt[l1][l2] << endl;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  cin >> T;
  gets(s1);
  for (kase = 1; kase <= T; ++kase) {
    
    gets(s1 + 1);
    gets(s2 + 1);
    // printf("%s\n%s\n", s1 + 1, s2 + 1);
    solve();
    
  }
  
  

  return 0;
}