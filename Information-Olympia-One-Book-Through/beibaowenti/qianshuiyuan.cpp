#include <bits/stdc++.h>

using namespace std;

int m, n, k, a[1000], b[1000], c[1000], f[1000][1000];

int main() {
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 1; i <= k; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
        
    int ans = 10000000;
    memset(f, 127, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = m + a[i]; j >= a[i]; j--) {
            for (int p = n + b[i]; p >= b[i]; p--) {
                f[j][p] = min(f[j][p], f[j - a[i]][p - b[i]] + c[i]);
                if (j >= m && p >= n) ans = min(ans, f[j][p]);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}