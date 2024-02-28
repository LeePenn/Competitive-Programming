#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 50 + 2;
int l, n, a[N];
int dp[N][N];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    while (scanf("%d", &l) == 1 && l) {
        scanf("%d", &n);
        
        a[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        a[n + 1] = l;
        
        for (int i = 0; i <= n + 1; ++i) {
            for (int j = 0; j <= n + 1; ++j) {
                dp[i][j] = 100000000;
            }
        }
        for (int i = 0; i <= n + 1; ++i) {
            dp[i][i] = 0;
        }
        
        for (int len = 1; len <= n + 1; ++len) {
            for (int i = 0; i + len <= n + 1; ++i) {
                int j = i + len;
                if (len == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[j] - a[i]);
                }
            }
        }
        
        printf("The minimum cutting is %d.\n", dp[0][n + 1]);
    }
    
    


    return 0;
}