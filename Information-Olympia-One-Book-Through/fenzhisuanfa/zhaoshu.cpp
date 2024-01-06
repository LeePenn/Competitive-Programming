#include <bits/stdc++.h>

using namespace std;

int n, m, a[100000], x;

int main() {
    cin >> n >> m;
    a[0] = -1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        cin >> x;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] <= x) l = mid + 1;
            else r = mid - 1;
        }
        cout << r << endl;
    }

    return 0;
}