#include <bits/stdc++.h>

using namespace std;

int n, m, a[1000][1000];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(int r, int c) {
    int q[1000][2];
    int front = 1, rear = 2;
    q[1][0] = r, q[1][1] = c;
    while (front < rear) {
        int cr = q[front][0], cc = q[front][1];
        a[cr][cc] = 0;
        front++;
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i], nc = cc + dc[i];
            if (nr >= 1 && nr <= n && nc >= 1 && nc <= m && a[nr][nc] == 1) {
                q[rear][0] = nr, q[rear][1] = nc;
                rear++;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (a[i][j] == 1) bfs(i, j), ans++;
    }
    cout << ans << endl;

    return 0;
}