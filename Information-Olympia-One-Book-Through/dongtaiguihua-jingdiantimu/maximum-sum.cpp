#include <bits/stdc++.h>

using namespace std;

int T, n, a[50000], l[50000], r[50000];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        a[0] = a[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] + l[i - 1] <= a[i]) l[i] = a[i];
            else l[i] = l[i - 1] + a[i];
        }
        for (int i = n; i >= 1; i--) {
            if (a[i] + r[i + 1] <= a[i]) r[i] = a[i];
            else r[i] = r[i + 1] + a[i];
        }
        
        int ans = -1000000;
        int temp = -1000000;
        for (int i = 1; i < n; i++) {
            temp = max(temp, l[i]);
            ans = max(ans, temp + r[i + 1]);
        }
        cout << ans << endl;
    }

    return 0;
}