#include <bits/stdc++.h>

using namespace std;

int n, t, a[100];
long long f[100];

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = t; j >= a[i]; j--) {
            f[j] += f[j - a[i]];
        }
    }
    cout << f[t] << endl;

    return 0;
}