#include <bits/stdc++.h>

using namespace std;

int n, a[100000], m;

int find_num(int num, int l, int r) {
    int b = -1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= num) r = mid - 1;
        else l = mid + 1;
    }
    if (a[l] == num) return a[l];
    return b;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (m - a[i] <= 0) break;
        int b = find_num(m - a[i], i + 1, n);
        if (b != -1) {
            cout << a[i] << ' ' << b << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;

    return 0;
}