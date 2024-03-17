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
const int N = 1000 + 4;
string s, secret;
int dp[N][10][10][10];
int up(int a, int b) {
    return (a + b) % 10;
}
int down(int a, int b) {
    return (a - b + 20) % 10;
}
int DP(int cur, int i0, int i1, int i2) {
    int &ans = dp[cur][i0][i1][i2];
    if (ans >= 0) return ans;
    int tcur = secret[cur] - '0';
    if (cur == s.length() - 1) return ans = min((tcur - i0 + 10) % 10, (i0 - tcur + 10) % 10);
    int s3 = cur + 3 > s.length() - 1 ? 0 : s[cur + 3] - '0';
    if (i0 == tcur) return DP(cur + 1, i1, i2, s3);
    
    ans = 0x3f3f3f3f;
    // rotate up
    int kup = (tcur - i0 + 10) % 10;
    for (int k1 = 0; k1 <= kup; ++k1) {
        for (int k2 = 0; k2 <= k1; ++k2) {
            ans = min(ans, kup + DP(cur + 1, up(i1, k1), up(i2, k2), s3));
        }
    }
    // rotate down
    int kdown = (i0 - tcur + 10) % 10;
    for (int k1 = 0; k1 <= kdown; ++k1) {
        for (int k2 = 0; k2 <= k1; ++k2) {
            ans = min(ans, kdown + DP(cur + 1, down(i1, k1), down(i2, k2), s3));
        }
    }
    return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (cin >> s >> secret) {
    while (s.length() < 3) {
        s.push_back('0');
        secret.push_back('0');
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", DP(0, s[0] - '0', s[1] - '0', s[2] - '0'));
  }
  
  

  return 0;
  
  
}