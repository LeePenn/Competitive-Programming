#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};
int n, m, matrix[100][100], sx, sy, ex, ey;
int hd, tail, q[1000][3];
bool v[100][100];

void print(int idx) {
    if (q[idx][2] == 0) {
        printf("%d %d\n", q[idx][0], q[idx][1]);
        return;
    }
    print(q[idx][2]);
    printf("%d %d\n", q[idx][0], q[idx][1]);
}

void work() {
    hd = 0, tail = 1;
    q[1][0] = sx, q[1][1] = sy, q[1][2] = 0;
    memset(v, 0, sizeof(v));
    v[sx][sy] = 1;
    int lastIndex = -1;
    do {
        hd++; 
        for (int i = 0; i < 4; i++) {
            int nx = q[hd][0] + dx[i], ny = q[hd][1] + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (matrix[nx][ny] == -1) continue;
            if (v[nx][ny]) continue;
            if (nx == ex && ny == ey) {
                lastIndex = hd;
                break;
            }
            v[nx][ny] = 1;
            tail++;
            q[tail][0] = nx, q[tail][1] = ny, q[tail][2] = hd;
        }
        if (lastIndex > 0) break;
    } while (hd < tail);
    
    if (lastIndex == -1) {
        printf("no way.\n");
    } else {
        print(lastIndex);
        printf("%d %d\n", ex, ey);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> matrix[i][j];
    }
    cin >> sx >> sy >> ex >> ey;
    
    work();
    

    return 0;
}