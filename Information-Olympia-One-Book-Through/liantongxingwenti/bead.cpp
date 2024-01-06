#include <bits/stdc++.h>

using namespace std;

int n, m, g[100][100], fg[100][100];
int d[100], fd[100];

int dfs(int u, int heavy) {
    if (heavy == 1) {
        if (d[u] != -1) return d[u];
        
        int tot = 0;
        for (int i = 1; i <= g[u][0]; i++) {
            tot += dfs(g[u][i], heavy);
        }
        return tot + g[u][0];
    } else {
        if (fd[u] != -1) return fd[u];
        
        int tot = 0;
        for (int i = 1; i <= fg[u][0]; i++) {
            tot += dfs(fg[u][i], heavy);
        }
        return tot + fg[u][0];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][++g[x][0]] = y, fg[y][++fg[y][0]] = x;
    }
    for (int i = 1; i <= n; i++) {
        d[i] = -1, fd[i] = -1;
    }
    
    for (int i = 1; i <= n; i++) {
        if (d[i] == -1) {
            d[i] = dfs(i, 1);
        }
        if (fd[i] == -1) {
            fd[i] = dfs(i, 0);
        }
    }
    
    int ans = 0;
    int mid = (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        if (d[i] >= mid) ans++;
        else if (fd[i] >= mid) ans++;
    }
    
    cout << ans << endl;

    return 0;
}