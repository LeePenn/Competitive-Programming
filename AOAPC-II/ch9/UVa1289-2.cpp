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
const int N = 50 + 4;
int n, m, plateSize[N * N];
// n 上有直径为 m 的
int has[N * N][N];
// 直径包含 m 的stack
vector<int> c[N * N];
/**
 * [第 ith 的板][颜色是 j]的最小的不同色板，这样得出分裂数为 min(dp[m - 1][j]) - n
 * 所以最终答案等于 2 * (x - n) + n - 1 = 2 * x - n - 1
 */ 

int dp[N * N][N];
int DP() {
    for (int i = 0; i < n; ++i) {
        if (has[0][i]) {
            dp[0][i] = plateSize[0];
        }
    }
    
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!has[i][j]) continue;
            
            for (int k = 0; k < n; ++k) {
                if (has[i][k] && (j != k || plateSize[i] == 1)) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + plateSize[i] - 1);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + plateSize[i]);
                }
            }
        }
    }
    int ret = 0x3f3f3f3f;
    for (int i = 0; i < n; ++i) {
        ret = min(ret, dp[m - 1][i]);
    }
    
    return ret;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  int kase = 1;
  int h, x;
  while (scanf("%d", &n) == 1 && n) {
    vector<pair<int, int>> D;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h);
        for (int j = 0; j < h; ++j) {
            scanf("%d", &x);
            D.push_back(make_pair(x, i));
        }
    }
    
    memset(has, 0, sizeof(has));
    memset(dp, 0x3f, sizeof(dp));
    
    sort(D.begin(), D.end());
    D.resize(unique(D.begin(), D.end()) - D.begin());
    m = 0;
    for (int i = 0; i < D.size();) {
        int cnt = 0, j = i;
        while (j < D.size() && D[i].first == D[j].first) {
            has[m][D[j].second] = 1;
            ++j, ++cnt;
        }
        plateSize[m] = cnt;
        ++m;
        i = j;
    }
    
    printf("Case %d: %d\n", kase, 2 * DP() - n - 1);
    kase++;
    
    
  }
  
  

  return 0;
  
  
}