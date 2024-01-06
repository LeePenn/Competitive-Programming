#include <bits/stdc++.h>

using namespace std;

int n, a[100], f[100][100];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    
    memset(f, 127, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k <= j - 1; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
            }
        }
    }
    cout << f[1][n] << endl;

    return 0;
}