#include <bits/stdc++.h>

using namespace std;

int a[100000], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        bool ok = true;
        for (int j = 1; j <= n - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ans++;
                ok = false;
            }
        }
        if (ok) break;
    }
    cout << ans << endl;

    return 0;
}