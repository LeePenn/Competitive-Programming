#include <bits/stdc++.h>

using namespace std;

int n, a[10000], f[10000], d[10000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    f[1] = 1;
    d[1] = a[1];
    int k = 1;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] < a[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
        
        bool find = false;
        int mi = 0;
        for (int j = 1; j <= k; j++) {
            if (d[j] > a[i]) {
                if (!find) {
                    find = true;
                    mi = j;
                } else {
                    if (d[j] < d[mi]) {
                        mi = j;
                    }
                }
            }
        }
        if (!find) {
            d[++k] = a[i];
        } else {
            d[mi] = a[i];
        }
        
    }
    
    cout << ans << endl;
    cout << k << endl;

    return 0;
}