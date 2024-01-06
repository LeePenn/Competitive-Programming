#include <bits/stdc++.h>

using namespace std;

int m, n, w[1000], c[1000];
int f[1000][1000], f2[1000];

// 2 dimensions
void version1() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> w[i] >> c[i];
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= w[i]) f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + c[i]);
            ans = max(ans, f[i][j]);
        }
    }
    cout << f[n][m] << endl;
}

// optimize
void version2() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> w[i] >> c[i];
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            // 等式右边第一个f2[j]代表上一轮（i - 1）时装j时的价值，等式左边是最后更新为本轮的价值
            f2[j] = max(f2[j], f2[j - w[i]] + c[i]);
            ans = max(ans, f2[j]);
        }
    }
    cout << ans << endl;
}

int main() {
    version2();
    
    
    return 0;
}



