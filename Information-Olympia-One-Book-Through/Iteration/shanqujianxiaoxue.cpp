#include <bits/stdc++.h>

using namespace std;

int m, n, a[500][500], c[500][500], f[500][500];

int main() {
    int inf = 0x7fffffff;
    int mid;
    scanf("%d%d", &m, &n);
    for (int i = 1; i < m; i++) scanf("%d", &a[i][i + 1]);
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            a[i][j] = a[i][j - 1] + a[j - 1][j];
            a[j][i] = a[i][j];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            mid = (i + j) / 2;
            for (int k = i; k <= j; k++) {
                c[i][j] += a[k][mid];
            }
        }
    }
    
    for (int i = 1; i <= m; i++) {
        f[i][1] = c[1][i];
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            f[i][j] = inf;
            for (int k = j - 1; k < i; k++) {
                f[i][j] = min(f[i][j], f[k][j - 1] + c[k + 1][i]);
            }
        }
    }
    cout << f[m][n] << endl;


    return 0;
}