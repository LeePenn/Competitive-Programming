#include <bits/stdc++.h>

using namespace std;

int n, m, a[100000];

int main() {
    cin >> n >> m;
    int l = 0, r = 100000000;
    for (int i = 1; i <= n; i++) cin >> a[i], l = max(l, a[i]);
    int sum = 0, mid;
    int tot;
    while (l < r) {
        sum = 0;
        mid = (l + r) >> 1;
        tot = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i];
            if (sum >= mid) {
                tot++;
                sum = 0;
                continue;
            }
        }
        if (tot <= m) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;

    return 0;
}