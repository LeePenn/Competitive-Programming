#include <bits/stdc++.h>

using namespace std;

const int MAX = 0x7fffffff >> 1;
int n, m, g[2000][2000];
int d[2000];
bool v[2000];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) g[i][j] = MAX;
    }
    
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    
    for (int i = 1; i <= n; i++) d[i] = MAX;
    memset(v, 0, sizeof(v));
    d[1] = 0; v[1] = true;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) d[i] = d[1] + g[1][i];
    }
    
    for (int i = 1; i < n; i++) {
        int k = 0;
        int minx = MAX;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && d[j] < minx) {
                k = j;
                minx = d[j];
            }
        }
        if (k == 0 || k == n) break;
        v[k] = true;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && d[j] > d[k] + g[k][j]) {
                d[j] = d[k] + g[k][j];
            }
        }
    }
    
    if (d[n] == MAX) cout << -1 << endl;
    else cout << d[n] << endl;
    

    return 0;
}