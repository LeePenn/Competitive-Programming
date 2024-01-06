#include <bits/stdc++.h>

using namespace std;

int n, a[10000], f[10000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    f[1] = a[1];
    int max1 = a[1];
    for (int i = 2; i <= n; i++) {
        f[i] = a[i];
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j] + a[i]);
                max1 = max(max1, f[i]);
            }
        }
    }
    cout << max1 << endl;

    return 0;
}