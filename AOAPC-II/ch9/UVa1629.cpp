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
const int N = 20 + 2, INF = 1e8;
int n, m, k;
int cherry[N][N];
int dp[N][N][N][N];
int vis[N][N][N][N];
int cherry_num[N][N][N][N];
int kase;
void read_data() {
    int u, v;
    memset(cherry, 0, sizeof(cherry));
    for (int i = 1; i <= k; ++i) {
        scanf("%d%d", &u, &v);
        cherry[u][v] = 1;
    }
}
void init() {
    memset(cherry_num, 0, sizeof(cherry_num));
    int sum[N][N];
    memset(sum, 0, sizeof(sum));
    for (int i1 = 1; i1 <= n; ++i1) {
        for (int j1 = 1; j1 <= m; ++j1) {
            sum[i1][j1] += sum[i1][j1 - 1];
            if (cherry[i1][j1]) {
                sum[i1][j1]++;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    for (int i1 = 1; i1 <= n; ++i1) {
        for (int j1 = 1; j1 <= m; ++j1) {
            for (int i2 = i1; i2 <= n; ++i2) {
                for (int j2 = j1; j2 <= m; ++j2) {
                    cherry_num[i1][j1][i2][j2] = 
                    sum[i2][j2] - sum[i1 - 1][j2] - sum[i2][j1 - 1] + sum[i1 - 1][j1 - 1];
                    // printf("%d %d %d %d = %d\n", i1, j1, i2, j2, cherry_num[i1][j1][i2][j2]);
                }
            }
        }
    }
    
                    
}
int DP(int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return INF;
    int &ans = dp[r1][c1][r2][c2];
    if (vis[r1][c1][r2][c2] == kase) return ans;
    vis[r1][c1][r2][c2] = kase;
    
    ans = INF;
    if (cherry_num[r1][c1][r2][c2] <= 1) {
        return ans = 0;
    }
    
    // cut row
    for (int i = r1; i < r2; ++i) {
        if (cherry_num[r1][c1][i][c2] > 0 && cherry_num[i + 1][c1][r2][c2] > 0) {
            ans = min(ans, DP(r1, c1, i, c2) + DP(i + 1, c1, r2, c2) + c2 - c1 + 1);
        }
    }
    // cut column
    for (int i = c1; i < c2; ++i) {
        if (cherry_num[r1][c1][r2][i] > 0 && cherry_num[r1][i + 1][r2][c2]) {
            ans = min(ans, DP(r1, c1, r2, i) + DP(r1, i + 1, r2, c2) + r2 - r1 + 1);
        }
    }
    return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  memset(dp, -1, sizeof(dp));
  memset(vis, 0, sizeof(vis));
  kase = 1;
  while (scanf("%d%d%d", &n, &m, &k) == 3) {
    read_data();
    init();
    printf("Case %d: %d\n", kase++, DP(1, 1, n, m));
    // printf("Test %d: %d\n", cherry_num[1][1][2][1], DP(1, 1, 2, 1));
  }
  
  

  return 0;
}