#include <bits/stdc++.h>

using namespace std;

int n, m, g[100][100];
int d[100];
int x, y;
int road[100], tot;

void dfs(int s) {
    road[++tot] = s;
    for (int i = 1; i <= n; i++) {
        if (g[s][i] == 1) {
            g[s][i] = g[i][s] = 0;
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
        d[x]++, d[y]++;
    }
    int start = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] % 2 == 1) {
            start = i;
            break;
        }
    }
    dfs(start);
    for (int i = 1; i <= tot; i++) cout << road[i] << ' ';
    cout << endl;
    
    return 0;
}