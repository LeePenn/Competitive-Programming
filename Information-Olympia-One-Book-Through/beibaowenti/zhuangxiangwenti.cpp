#include <bits/stdc++.h>

using namespace std;

int v, n, a[10000], f[20000];

int main() {
    cin >> v >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    f[0] = 0;
    int maxv = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= a[i]; j--) {
            f[j] = max(f[j], f[j - a[i]] + 1);
            if (f[j] > 0) maxv = max(maxv, j);
        }
    }
    cout << (v - maxv) << endl;
    

    return 0;
}