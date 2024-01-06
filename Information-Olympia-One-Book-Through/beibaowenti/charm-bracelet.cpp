#include <bits/stdc++.h>

using namespace std;

int n, m, w[10000], c[10000], f[20000];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i] >> c[i];
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + c[i]);
            ans = max(ans, f[j]);
        }
    }
    cout << ans << endl;

    return 0;
}