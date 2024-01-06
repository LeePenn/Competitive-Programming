#include <bits/stdc++.h>

using namespace std;

int n, a[10000], m, ans, diff;

void query(int l, int r, int x) {
    if (diff == 0) return;
    while (l < r) {
        int mid = (l + r) >> 1;
        int temp = abs(a[mid] - x);
        if (temp < diff || (temp == diff && a[mid] < ans)) {
            diff = temp, ans = a[mid];
        }
        if (a[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int temp = abs(a[l] - x);
    if (temp < diff || (temp == diff && a[l] < ans)) {
        diff = temp, ans = a[l];
    }

    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    int x;
    while (m--) {
        diff = 10000000;
        cin >> x;
        query(1, n, x);
        cout << ans << endl;
    }
    
    
    return 0;
}