#include <bits/stdc++.h>

using namespace std;

int v, n, t, w[100][100], c[100][100], f[100], g[100];

int main() {
    scanf("%d%d%d", &v, &n, &t);
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[z]++;
        w[z][g[z]] = x;
        c[z][g[z]] = y;
    }
    int ans;
    for (int i = 1; i <= t; i++) {
        for (int j = v; j >= 0; j--) {
            for (int k = 1; k <= g[i]; k++) {
                if (j >= w[i][k]) f[j] = max(f[j], f[j - w[i][k]] + c[i][k]);
                ans = max(ans, f[j]);
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}