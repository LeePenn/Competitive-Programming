#include <bits/stdc++.h>

using namespace std;

int T, n, m, a[1000][1000], f[1000][1000];

int main() {
    cin >> T;
    while (T--) {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++) 
                cin >> a[i][j];
                
        
        f[1][1] = a[1][1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
            }
        }
    
        cout << f[n][m] << endl;
    }

    return 0;
}