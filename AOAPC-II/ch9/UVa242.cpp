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
const int S = 10 + 2, N = 10 + 3, M = 1000 + 4;
int s, n;
int dp[M];
vector<int> stamps[N];
int maxlen, ans;
bool stamp_cmp(vector<int> &a, vector<int> &b) {
    if (a.size() > b.size()) return 1;
    if (a.size() < b.size()) return 0;
    for (size_t i = a.size() - 1; i >= 0; --i) {
        if (a[i] < b[i]) return 0;
        if (a[i] > b[i]) return 1;
    }
    return 0;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (scanf("%d", &s) == 1 && s) {
    ans = -1, maxlen = 0;
    scanf("%d", &n);
    int c, x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c);
        stamps[i].clear();
        for (int j = 0; j < c; ++j) {
            scanf("%d", &x);
            stamps[i].push_back(x);
        }
        
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        int cnt = stamps[i].size();
        int curlen = 0;
        for (int j = 1; j <= stamps[i][cnt - 1] * s; ++j) {
            if (dp[j] <= s && dp[j] >= 0) continue;
            for (int k = 0; k < cnt; ++k) {
                if (j - stamps[i][k] < 0) break;
                dp[j] = min(dp[j], dp[j - stamps[i][k]] + 1);
            }
            if (dp[j] == 0x3f3f3f3f || dp[j] > s) {
                curlen = j - 1;
                break;
            }
            curlen = j;
            // printf("## %d\n", j);
        }
        // printf("# %d\n", maxlen);
        if (curlen > maxlen) {
            ans = i;
            maxlen = curlen;
        } else if (curlen == maxlen) {
            if (stamp_cmp(stamps[ans], stamps[i])) {
                ans = i;
            }
        }
    }
    printf("max coverage = %3d :", maxlen);
    for (auto x : stamps[ans]) {
        printf("%3d", x);
    }
    printf("\n");
  }
  
  

  return 0;
}