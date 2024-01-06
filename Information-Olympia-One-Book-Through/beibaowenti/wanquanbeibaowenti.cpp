#include <bits/stdc++.h>

using namespace std;

int m, n, w[1000], c[1000], f[1000];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> w[i] >> c[i];
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - w[i]] + c[i]);
            ans = max(ans, f[j]);
        }
    }
    cout << ans << endl;
    
    return 0;
}