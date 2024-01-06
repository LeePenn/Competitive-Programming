#include <bits/stdc++.h>

using namespace std;

int n, k, f[200][10];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i < j) f[i][j] = 0;
            else if (i == j) f[i][j] = 1;
            else f[i][j] = f[i - j][j] + f[i - 1][j - 1];
        }
    }
    cout << f[n][k] << endl;
    return 0;
}