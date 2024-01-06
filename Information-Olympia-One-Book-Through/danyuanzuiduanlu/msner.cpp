#include <bits/stdc++.h>

using namespace std;

int n, m, w[105][105], x, y, z;
int d[105];
bool v[105];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) w[i][j] = w[j][i] = 0x7fffffff >> 1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        w[x][y] = w[y][x] = z;
    }
    
    for (int i = 1; i <= n; i++) d[i] = 0x7fffffff >> 1;
    memset(v, 0, sizeof(v));
    d[1] = 0;
    v[1] = true;
    for (int i = 1; i <= n; i++) {
        if (!v[i] && d[i] > d[1] + w[1][i]) d[i] = d[1] + w[1][i];
    }
    
    for (int i = 1; i < n; i++) {
        int k = 0;
        int minx = 0x7fffffff >> 1;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && d[j] < minx) {
                k = j;
                minx = d[j];
            }
        }
        if (k == 0) {
            break;
        }
        v[k] = true;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && d[j] > d[k] + w[k][j]) {
                d[j] = d[k] + w[k][j];
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d[i]);
    }
    cout << ans << endl;

    return 0;
}