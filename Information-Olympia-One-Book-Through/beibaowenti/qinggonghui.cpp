#include <bits/stdc++.h>

using namespace std;

int n, m, v[1000], w[1000], f[1000];
int x, y, z, t, n1;

int main() {
    scanf("%d %d", &n, &m);
    n1 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x, &y, &z);
        t = 1;
        while (z > t) {
            v[++n1] = t * x;
            w[n1] = t * y;
            z -= t;
            t *= 2;
        }
        v[++n1] = z * x;
        w[n1] = z * y;
    }
    
    int ans = 0;
    for (int i = 1; i <= n1; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            ans = max(ans, f[j]);
        }
    }
    printf("%d\n", ans);

    return 0;
}