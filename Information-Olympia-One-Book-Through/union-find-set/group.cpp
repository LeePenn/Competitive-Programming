#include <bits/stdc++.h>

using namespace std;

int n, m, p, x, y;
int f[1000], a[1000];

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
    for (int i = 1; i <= n; i++) f[i] = i;
    
    for (int i = 1; i <= m; i++) {
        cin >> p >> x >> y;
        if (p == 0) uni(x, y);
        else {
            if (a[y] == 0) {
                a[y] = x;
            } else uni(x, a[y]);
            
            if (a[x] == 0) {
                a[x] = y;
            } else uni(y, a[x]);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) ans++;
    }
    
    cout << ans << endl;

    return 0;
}