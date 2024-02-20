#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 50 + 2, T = 9678 + 2;
int n, t;
int s[N], dp[T];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int kase;
    scanf("%d", &kase);
    for (int k = 1; k <= kase; ++k) {
        printf("Case %d: ", k);
        
        scanf("%d%d", &n, &t);
        for (int i = 1; i <= n; ++i) scanf("%d", &s[i]);
        
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = t; j >= 0; --j) {
                if (j - s[i] >= 0 && dp[j - s[i]] >= 0) {
                    dp[j] = max(dp[j], dp[j - s[i]] + 1);
                    // printf("!! %d\n", dp[j]);
                }
            }
        }
        
        int ans = 0, maxT = 678;
        for (int i = t - 1; i >= 0; --i) {
            if (ans < dp[i]) {
                ans = dp[i];
                maxT = i + 678;
            }
        }
        printf("%d %d\n", ans + 1, maxT);
    }
    


    return 0;
}