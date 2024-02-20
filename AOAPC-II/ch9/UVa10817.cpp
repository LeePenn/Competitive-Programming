#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;
const int N = 100 + 20 + 4, INF = 1e8;
int s, m, n;
int c[N], st[N], dp[N][1 << 8][1 << 8];

int DP(int i, int s0, int s1, int s2) {
    if (i == m + n) return s2 == (1 << s) - 1 ? 0 : INF;
    int &ans = dp[i][s1][s2];
    if (ans >= 0) return ans;
    
    ans = INF;
    if (i >= m) ans = DP(i + 1, s0, s1, s2);
    
    int m0 = st[i] & s0, m1 = st[i] & s1;
    s0 ^= m0;
    s1 = (s1 ^ m1) | m0;
    s2 |= m1;
    ans = min(ans, c[i] + DP(i + 1, s0, s1, s2));
    return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
    
    int a;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        ss >> s >> m >> n;
        if (s == 0) break;
        
        for (int i = 0; i < m + n; ++i) {
            getline(cin, line);
            stringstream ss(line);
            ss >> c[i];
            st[i] = 0;
            while (ss >> a) {
                st[i] |= 1 << (a - 1);
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << DP(0, (1 << s) - 1, 0, 0) << endl;
    }


  return 0;
}