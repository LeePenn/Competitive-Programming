#include <bits/stdc++.h>

using namespace std;

int T, n, a[100000], f[100000][3][2]; // pre-n stocks, after k transactions, not/own one stock profit

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        memset(f, -127, sizeof(f));
        f[1][0][0] = f[1][1][0] = f[1][2][0] = 0;
        f[1][0][1] = f[1][1][1] = f[1][2][1] = -a[1];
        for (int i = 2; i <= n; i++) { 
            for (int j = 1; j <= 2; j++) {
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + a[i]);
                f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - a[i]);
            }
        }    
        cout << f[n][2][0] << endl;
    }

    return 0;
}