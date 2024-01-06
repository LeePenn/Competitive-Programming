#include <bits/stdc++.h>

using namespace std;

int n, a[1000], f[1000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[1] = 1;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    

    return 0;
}