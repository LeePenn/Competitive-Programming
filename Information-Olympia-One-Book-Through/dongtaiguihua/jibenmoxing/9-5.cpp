#include <bits/stdc++.h>

using namespace std;

int n, a[10000][10000], f[10000], d[10000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    
    for (int i = 1; i <= n; i++) f[i] = 10000000;
    f[n] = 0;
    d[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] && f[j] != 10000000 && f[i] > f[j] + a[i][j]) {
                f[i] = f[j] + a[i][j];
                d[i] = j;
            }
        }
    }
    printf("minlong=%d\n", f[1]);
    printf("1 ");
    int k = 1;
    do {
        printf("%d ", d[k]);
        k = d[k];
    } while (d[k]);
    

    return 0;
}