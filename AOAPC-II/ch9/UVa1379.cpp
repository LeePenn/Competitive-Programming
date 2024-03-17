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
const int N = 100 + 4, G = 200 + 10 + 4;
int T, n, m, g_num;
struct WinP {
    int p, pit;
    WinP(): p(0), pit(0) {}
    bool operator <(const WinP &rhs) const {
        return p > rhs.p;
    }
};
WinP winps[N][N];
int g[G], dp[2][6][6][6][6];
inline int getPi(int op, int i) {
    return winps[op][i].pit;
}
double solve() {
    memset(dp, 0, sizeof(dp));
    int ans = 0, cur = 0;
    for (int i = 1; i <= g_num; ++i) {
        memset(dp[cur ^ 1], 0, sizeof(dp[cur ^ 1]));
        
        int op = g[i];
        if (op == 0) {
            for (int p1 = 0; p1 <= 5; ++p1) {
                for (int p2 = 0; p2 <= 5; ++p2) {
                    for (int p3 = 0; p3 <= 5; ++p3) {
                        for (int p4 = 0; p4 <= 5; ++p4) {
                            int &d = dp[cur ^ 1][0][p1][p2][p3];
                            d = max(d, dp[cur][p1][p2][p3][p4]);
                            ans = max(ans, d);
                        }
                    }
                }
            }
            continue;
        } 
        
        for (int p0 = 1; p0 <= 5; ++p0) {
            int opi = getPi(op, p0);
            for (int p1 = 0; p1 <= 5; ++p1) {
                if (i > 1 && getPi(g[i - 1], p1) == opi) continue;
                for (int p2 = 0; p2 <= 5; ++p2) {
                    if (i > 2 && getPi(g[i - 2], p2) == opi) continue;
                    for (int p3 = 0; p3 <= 5; ++p3) {
                        if (i > 3 && getPi(g[i - 3], p3) == opi) continue;
                        for (int p4 = 0; p4 <= 5; ++p4) {
                            if (i > 4 && getPi(g[i - 4], p4) == opi) continue;
                            int &d = dp[cur ^ 1][p0][p1][p2][p3];
                            d = max(d, dp[cur][p1][p2][p3][p4] + winps[op][p0].p);
                            ans = max(ans, d);
                        }
                    }
                }
            }
        }
        
        cur ^= 1;
    }
    
    return ans * 0.01;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &g_num);
    g_num += 10;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &winps[i][j].p);
            winps[i][j].pit = j;
        }
        sort(winps[i] + 1, winps[i] + n + 1);
    }
    
    g[0] = 0;
    for (int i = 1; i <= g_num; ++i) {
        scanf("%d", &g[i]);
    }
    
    printf("%.2lf\n", solve());
  }
  
  

  return 0;
  
  
}