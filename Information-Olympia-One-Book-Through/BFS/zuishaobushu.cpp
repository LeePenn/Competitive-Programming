#include <bits/stdc++.h>

using namespace std;

int dx[12] = {-2, -2, -1, 1, 2, 2, 2, 2, 1, -1, -2, -2},
    dy[12] = {-1, -2, -2, -2, -2, -1, 1, 2, 2, 2, 2, 1};
int a1, a2, b1, b2;
int hd, tail, q[100000][3];
bool v[105][105];

void work(int a, int b) {
    hd = 0, tail = 1;
    memset(v, 0, sizeof(v));
    q[1][0] = a, q[1][1] = b, q[1][2] = 0;
    v[a][b] = 1;
    do {
        hd++;
        for (int i = 0; i < 12; i++) {
            int nx = q[hd][0] + dx[i], ny = q[hd][1] + dy[i];
            if (nx < 1 || nx > 100 || ny < 1 || ny > 100) continue;
            if (v[nx][ny]) continue;
            if (nx == 1 && ny == 1) {
                cout << (q[hd][2] + 1) << endl;
                return;
            }
            v[nx][ny] = 1;
            tail++;
            q[tail][0] = nx, q[tail][1] = ny, q[tail][2] = q[hd][2] + 1;
        }
    } while (hd < tail);
    
    return;
}

int main() {
    cin >> a1 >> a2 >> b1 >> b2;
    work(a1, a2);
    work(b1, b2);
    
    return 0;
}