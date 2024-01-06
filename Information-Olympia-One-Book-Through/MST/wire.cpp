#include <bits/stdc++.h>

using namespace std;

int n, g[100][100], d[100];
bool v[100];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> g[i][j] ;
    }
    
    memset(d, 0x7f, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= n; i++) {
        int k = 0;
        int mind = d[0];
        for (int j = 1; j <= n; j++) {
            if (!v[j] && d[j] < mind) {
                k = j;
                mind = d[j];
            }
        }
        if (k == 0) break;
        v[k] = true;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && g[k][j] < d[j]) d[j] = g[k][j];
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += d[i];
    cout << ans << endl;

    return 0;
}