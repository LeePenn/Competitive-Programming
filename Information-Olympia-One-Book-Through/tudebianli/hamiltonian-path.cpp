#include <bits/stdc++.h>

using namespace std;

int n, m, g[100][100];
int num[100];
int loop[100], len, start;
bool v1[100], v2[100];

void print() {
    for (int i = 1; i <= len; i++) cout << loop[i] << ' ';
    cout << endl;
}

void dfs(int i, int pa) {
    loop[++len] = i;
    v1[i] = v2[i] = true;
    for (int j = 1; j <= num[i]; j++) {
        if (g[i][j] == start && g[i][j] != pa) {
            loop[++len] = g[i][j];
            print();
            len--;
            break;
        }
        if (!v2[g[i][j]]) dfs(g[i][j], i);
    }
    len--;
    v2[i] = false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][++num[x]] = y;
        g[y][++num[y]] = x;
    }
    memset(v1, 0, sizeof(v1));
    memset(v2, 0, sizeof(v2));
    for (int i = 1; i <= n; i++) {
        if (!v1[i]) {
            len = 0;
            start = i;
            dfs(i, 0);
        }
    }

    return 0;
}