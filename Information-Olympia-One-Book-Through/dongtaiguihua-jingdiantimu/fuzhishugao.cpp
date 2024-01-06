#include <bits/stdc++.h>

using namespace std;

int m, k, a[1000], b[1000], f[1000][1000];

int main() {
    cin >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        b[i] = a[i];
        a[i] += a[i - 1];
    }
    
    memset(f, 127, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= m; j++) {
            for (int l = i - 1; l < j; l++) {
                f[i][j] = min(f[i][j], max(f[i - 1][l], a[j] - a[l]));
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        if (sum == 0) printf("%d ", i);
        sum += b[i];
        if (sum > f[k][m]) {
            printf("%d\n", i - 1);
            printf("%d ", i);
            sum = b[i];
        }
    }
    printf("%d\n", m);

    return 0;
}