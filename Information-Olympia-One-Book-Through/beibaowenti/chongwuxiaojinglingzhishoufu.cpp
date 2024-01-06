#include <bits/stdc++.h>

using namespace std;

int n, m, k, a[1000], b[1000], f[1000][1000];

int main() {
    cin >> n >> m >> k;
    
    for (int i = 1; i <= k; i++) cin >> a[i] >> b[i];
    
    f[0][0] = 0;
    int maxc = 0, maxr = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = n; j >= a[i]; j--) {
            for (int p = m; p >= b[i]; p--) {
                // cost j and p
                f[j][p] = max(f[j][p], f[j - a[i]][p - b[i]] + 1);
                if (f[j][p] > maxc || (f[j][p] == maxc && p < maxr)) {
                    maxc = f[j][p];
                    maxr = p;
                }
            }
        }
    }
    cout << maxc << " " << (m - maxr) << endl;

    return 0;
}