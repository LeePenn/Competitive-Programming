#include <bits/stdc++.h>

using namespace std;

int T, n, k, m[100], p[100], f[100];

int main() {
    cin >> T;
    
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> m[i];
        for (int i = 1; i <= n; i++) cin >> p[i];
        
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) {
            f[i] = p[i];
            int j = i - 1;
            while (j >= 1) {
                if (m[i] - m[j] >= k) {
                    f[i] = max(f[i - 1], f[j] + p[i]);
                }
                j--;
            }
        }
        cout << f[n] << endl;
    
    }
    return 0;
}