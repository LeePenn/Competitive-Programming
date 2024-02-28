#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1000 + 2;
int kase, n, T;
char s[N];
bool palim[N][N];
int vis[N][N];
int dp[N];

bool is_palim(int i, int j) {
    if (i >= j) return true;
    if (s[i] != s[j]) return false;
    
    if (vis[i][j] == kase) return palim[i][j];
    vis[i][j] = kase;
    return palim[i][j] = is_palim(i + 1, j - 1);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    scanf("%d", &T);
    for (kase = 1; kase <= T; ++kase) {
        scanf("%s", s + 1);
        
        n = strlen(s + 1);
        memset(palim, 0, sizeof(palim));
        memset(vis, 0, sizeof(vis));
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;
            for (int j = i - 1; j >= 0; --j) {
                if (is_palim(j + 1, i)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        
        printf("%d\n", dp[n]);
    }
    


    return 0;
}