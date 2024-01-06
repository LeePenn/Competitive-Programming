#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int n, m, a[100][100], q[1000][2];
int hd, tail, maxRoom;
bool v[100][100];

void work(int x, int y) {
    v[x][y] = true;
    hd = 0, tail = 1;
    q[1][0] = x, q[1][1] = y;
    int cnt = 1;
    do {
        hd++;
        for (int i = 0; i < 4; i++) {
            int curX = q[hd][0], curY = q[hd][1];
            if (((a[curX][curY] >> i) & 1) == 1) continue;
            int nx = curX + dx[i], ny = curY + dy[i];
            if (v[nx][ny]) continue;
            tail++;
            v[nx][ny] = true;
            q[tail][0] = nx, q[tail][1] = ny;
            cnt++;
        }
    } while (hd < tail);
    if (cnt > maxRoom) maxRoom = cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    memset(v, 0, sizeof(v));
    int ans = 0;
    maxRoom = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!v[i][j]) {
                work(i, j);
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    cout << maxRoom << endl;

    return 0;
}
