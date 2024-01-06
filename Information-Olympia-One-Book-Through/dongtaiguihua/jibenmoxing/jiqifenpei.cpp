#include <bits/stdc++.h>

using namespace std;

int n, m, a[100][100], f[100][100];
int max1;

void show(int p, int q) {
    if (p == 1) {
        printf("%d %d\n", p, q);
        return;
    }
    for (int k = 0; k <= q; k++) {
        if (f[p - 1][q - k] + a[p][k] == max1) {
            max1 -= a[p][k];
            show(p - 1, q - k);
            printf("%d %d\n", p, k);
            return;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) cin >> a[i][j];
        
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + a[i][k]);
            }
        }
    }
    cout << f[n][m] << endl;
    max1 = f[n][m];
    show(n, m);
    
    return 0;
}