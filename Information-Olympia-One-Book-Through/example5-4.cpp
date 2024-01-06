#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, p, t, tot, a[101];
    cin >> n >> m;

    memset(a, 0, sizeof(a));
    p = 0, t = 0, tot = n;
    while (n) {
        p++;
        if (p == tot + 1) {
            p = 1;
        }
        if (a[p]) {
            continue;
        }
        t++;
        if (t == m) {
            cout << p << ' ';
            a[p] = 1;
            t = 0;
            n--;
        }
    }

    return 0;
}