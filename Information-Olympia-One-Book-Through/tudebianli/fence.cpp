#include <bits/stdc++.h>

using namespace std;

int m, n, g[500][500];
int d[500];
int start;
int len, ans[500];

void dfs(int i) {
    for (int j = 1; j <= n; j++) {
        if (g[i][j]) {
            ans[++len] = j;
            g[i][j] = g[j][i] = 0;
            dfs(j);
        }
    }
}

int main() {
    cin >> m;
    int x, y;
    n = 0;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
        d[x]++, d[y]++;
        n = max(n, max(x, y));
    }
    start = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] % 2 == 1) {
            start = i;
            break;
        }
    }
    ans[++len] = start;
    dfs(start);
    
    for (int i = 1; i <= len; i++) cout << ans[i] << ' ';
    cout << endl;
    
    return 0;
}