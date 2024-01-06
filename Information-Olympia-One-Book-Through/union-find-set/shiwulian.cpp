#include <bits/stdc++.h>

using namespace std;

int n, m, f[150000], d, a, b;

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void uni(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) f[fy] = fx;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= 3 * n; i++) f[i] = i;
    
    int fake = 0;
    for (int i = 1; i <= m; i++) {
        cin >> d >> a >> b;
        if (a > n || b > n) fake++;
        else if (d == 1) {
            if (find(a) == find(b + n) || find(a) == find(b + 2 * n)) fake++;
            else {
                uni(a, b); uni(a, b + n); uni(a, b + 2 * n);
            }
        } else {
            if (find(a) == find(b + 2 * n) || find(a) == find(b)) fake++;
            else {
                uni(a, b + n); uni(a + n, b + 2 * n); uni(a + 2 * n, b);
            }
        }
    }
    cout << fake << endl;

    return 0;
}