#include <bits/stdc++.h>

using namespace std;

int m, n, w[1000], c[1000], p[1000], f[1000];

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) scanf("%d %d %d", &w[i], &c[i], &p[i]);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] == 0) {
            for (int j = w[i]; j <= m; j++) {
                f[j] = max(f[j], f[j - w[i]] + c[i]);
                ans = max(ans, f[j]);
            }
        } else {
            for (int j = m; j >= w[i]; j--) {
                for (int k = 1; k <= p[i]; k++) {
                    if (k * w[i] <= j) f[j] = max(f[j], f[j - k * w[i]] + k * c[i]);
                }
                ans = max(ans, f[j]);
            }
        }
    }
    
    printf("%d\n", ans);

    return 0;
}