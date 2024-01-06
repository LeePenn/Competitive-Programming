#include <bits/stdc++.h>

using namespace std;

int n, m, a[1000][1000], f[1000], s[1000];

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        s[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
        for (int j = 1; j <= a[i][0]; j++) cin >> a[i][j];
    }
    
    bool ok = false;
    for (int i = n; i >= 1; i--) {
        if (ok) break;
        for (int j = 1; j <= a[i][0]; j++) {
            if (a[i][j] > i) {
                int fx = find(a[i][j]);
                int fy = find(i);
                if (fx != fy) {
                    f[fx] = fy;
                    s[fy] += s[fx];
                    if (s[fy] > (n + 1) / 2) {
                        printf("%d\n", i);
                        ok = true;
                        break;
                    }
                }
            }
        }
    }
    
    return 0;
}