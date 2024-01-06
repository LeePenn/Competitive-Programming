#include <bits/stdc++.h>

using namespace std;

int n, a[206], d[206][206], f[206], b[206];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    memset(d, 0, sizeof(d));
    int x, y;
    while (scanf("%d %d", &x, &y) == 2 && x && y) {
        d[x][y] = 1;
    }
    
    memset(f, 0, sizeof(f));
    f[n] = a[n];
    b[n] = 0;
    int ans = -1, mx = -1;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (d[i][j] == 1 && f[i] < a[i] + f[j]) {
                f[i] = a[i] + f[j];
                b[i] = j;
            }
        }
        if (f[i] > mx) {
            mx = f[i];
            ans = i;
        }
    }
    
    printf("%d", ans);
    while (b[ans]) {
        printf("-%d", b[ans]);
        ans = b[ans];
    }
    printf("\n");
    printf("%d\n", mx);
    
    
    return 0;
}