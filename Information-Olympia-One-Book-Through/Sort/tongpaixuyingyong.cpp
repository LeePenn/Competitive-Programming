#include <bits/stdc++.h>

using namespace std;

int a[1005], b[1005], n, ans;

int main() {
    memset(b, 0, sizeof(b));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[a[i]]++;
    }
    ans = 0;
    for (int i = 1; i <= 1000; i++) {
        if (b[i] > 0) {
            ans++;
            continue;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= 1000; i++) {
        if (b[i] > 0) {
            cout << i << ' ';
            continue;
        }
    }
    cout << endl;

    return 0;
}