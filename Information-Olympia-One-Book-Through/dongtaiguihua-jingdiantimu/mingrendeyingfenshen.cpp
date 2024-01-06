#include <bits/stdc++.h>

using namespace std;

int t, m, n, f[10][10];

int main() {
    cin >> t;
    while (t--) {
        cin >> m >> n;
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 1) f[i][j] = 1;
                else if (i < j) f[i][j] = f[i][i];
                else f[i][j] = f[i - j][j] + f[i][j - 1];
            }
        }
        cout << f[m][n] << endl;
    
    }

    return 0;
}