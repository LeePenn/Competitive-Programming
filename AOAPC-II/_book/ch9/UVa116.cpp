#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 10 + 2, M = 100 + 2, INF = 1e9 + 7;
int n, m;
int g[N][M], dp[N][M], col[M], ans, anscol[M];

void DP(int i, int j, int a) {
    if (j == m) {
        if (ans <= a + g[i][j]) return;
        if (ans > a + g[i][j]) {
            ans = a + g[i][j];
            col[m] = i;
            memcpy(anscol, col, sizeof(anscol));
            return;
        }
        
        // if (ans == a + g[i][j] && col[m] > i) {
        //     col[m] = i;
        //     memcpy(anscol, col, sizeof(anscol));
        // }
        return;
    }
    
    if (a + g[i][j] >= dp[i][j]) return;
    if (dp[i][j] == 0x3f3f3f3f || a + g[i][j] < dp[i][j]) {
        dp[i][j] = a + g[i][j];
    }
    
    col[j] = i;
    if (i == n) {
        DP(1, j + 1, a + g[i][j]);
    }
    if (i > 1) {
        DP(i - 1, j + 1, a + g[i][j]);
    } 
    DP(i, j + 1, a + g[i][j]);
    if (i < n) {
        DP(i + 1, j + 1, a + g[i][j]);
    }
    if (i == 1) {
        DP(n, j + 1, a + g[i][j]);
    }
}

void Init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    ans = INF;
}

void Clear() {
    memset(dp, 0x3f, sizeof(dp));
    ans = INF;
    for (int i = 1; i <= m; ++i) col[i] = M;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    while (scanf("%d%d", &n, &m) == 2 && n && m) {
        Init();
        Clear();
        for (int i = 1; i <= n; ++i) {
            DP(i, 1, 0);
        }
        
        printf("%d", anscol[1]);
        for (int i = 2; i <= m; ++i) printf(" %d", anscol[i]);
        printf("\n%d\n", ans);
    }
    


    return 0;
}