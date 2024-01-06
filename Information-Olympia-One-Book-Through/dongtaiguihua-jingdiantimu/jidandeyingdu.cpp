#include <bits/stdc++.h>

using namespace std;

int n, m, f[100][100];

int main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) f[i][j] = i;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                for (int k = 1; k <= i; k++) {
                    f[i][j] = min(f[i][j], max(f[k - 1][j - 1], f[i - k][j]) + 1);
                }
            }
        }
        
        cout << f[n][m] << endl;
    }
    

    return 0;
}