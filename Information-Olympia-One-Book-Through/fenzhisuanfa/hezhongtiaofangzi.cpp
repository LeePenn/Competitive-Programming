#include <bits/stdc++.h>

using namespace std;

int L, n, m, a[100000], b[100000];

int work(int mid) {
    for (int i = 0; i <= n; i++) b[i] = a[i];
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] - b[i - 1] < mid) {
            k++;
            b[i] = b[i - 1];
        }
        if (k > m) return k;
    }
    return k;
}

int main() {
    cin >> L >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    n++;
    a[0] = 0, a[n] = L;
    int mind = 0, maxd = L;
    while (mind < maxd) {
        int mid = (mind + maxd) >> 1;
        if (work(mid) >= m) maxd = mid - 1;
        else mind = mid + 1;
    }
    cout << mind << endl;

    return 0;
}