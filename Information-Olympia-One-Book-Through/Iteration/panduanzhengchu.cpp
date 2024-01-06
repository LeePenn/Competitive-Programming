#include <bits/stdc++.h>

using namespace std;

int n, k, a[10000];

int main() {    
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    bool f[10000][k];
    memset(f, false, sizeof(f));
    f[1][a[1] % k] = true;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (f[i - 1][j]) {
                f[i][(j + a[i]) % k] = true;
                f[i][((j - a[i]) % k + k) % k] = true;
            }
        }
    }
    
    if (f[n][0]) printf("YES\n");
    else printf("NO\n");

    return 0;
}