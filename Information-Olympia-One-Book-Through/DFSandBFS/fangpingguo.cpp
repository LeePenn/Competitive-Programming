#include <bits/stdc++.h>

using namespace std;

int a[11] = {1}, ans, n, m;

void x(int s, int k) {
    for (int i = a[k - 1]; i <= s; i++) {
        s -= i;
        a[k] = i;
        if (s == 0 && k <= n) ans++;
        else x(s, k + 1);
        s += i;
    }
    return;
}

int main() {
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        ans = 0;
        cin >> m >> n;
        x(m, 1);
        cout << ans << endl;
    }


    return 0;
}