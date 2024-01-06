#include <bits/stdc++.h>

using namespace std;

int n, k, a[1000], f[1000][1000];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // cannot use one-dimensional array, cause j is not sequential consistence, it can jump
    for (int i = 1; i <= n; i++) {
        f[i][a[i] % k] = a[i];
        for (int j = k - 1; j >= 0; j--) {
            f[i][j] = max(f[i][j], f[i - 1][j]);
            // zero means not exist num = (j - (a[i] % k) + k) % k candy bag
            if (f[i - 1][(j - (a[i] % k) + k) % k] != 0) {
                f[i][j] = max(f[i][j], f[i - 1][(j - (a[i] % k) + k) % k] + a[i]);
            }
        }
    }
    cout << f[n][0] << endl;
    

    return 0;
}