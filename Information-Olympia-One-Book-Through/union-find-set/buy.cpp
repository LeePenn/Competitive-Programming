#include <bits/stdc++.h>

using namespace std;

int n, m, w, a[1000], b[1000], f[1000], c[1000][2], d[1000][2], cnt, dp[1000];

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void uni(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) f[fy] = fx;
}

int main() {
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++) f[i] = i;
    
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        uni(x, y);
    }
    
    for (int i = 1; i <= n; i++) {
        c[find(i)][0] += a[i];
        c[find(i)][1] += b[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if (c[i][0] != 0) {
            d[++cnt][0] = c[i][0];
            d[cnt][1] = c[i][1];
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        for (int j = w; j >= 1; j--) {
            if (j >= d[i][0]) {
                dp[j] = max(dp[j], dp[j - d[i][0]] + d[i][1]);
                ans = max(ans, dp[j]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}