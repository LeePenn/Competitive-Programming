#include <bits/stdc++.h>

using namespace std;

int dirs[4][2] = {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
};

int n, m, h[10000][3];
bool v[100][100];
char a[100][100];
int ans;

void fill(int p, int q) {
    v[p][q] = 1;
    ans++;
    int head = 0, tail = 1;
    h[1][1] = p, h[1][2] = q;
    do {
        head++;
        for (int i = 0; i < 4; i++) {
            int px = h[head][1] + dirs[i][0], qx = h[head][2] + dirs[i][1];
            if (px >= 0 && px < n && qx >= 0 && qx < m && a[px][qx] >= '1' && a[px][qx] <= '9' && !v[px][qx]) {
                tail++;
                h[tail][1] = px, h[tail][2] = qx, v[px][qx] = true;
            }
        }
    } while (head < tail);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        scanf("%s", a[i]);
    }
    ans = 0;
    memset(v, 0, sizeof(v));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (a[i][j] >= '1' && a[i][j] <= '9' && !v[i][j]) {
                fill(i, j);
            }
        }
    }
    printf("NUMBER of cells=%d\n", ans);
    
    return 0;
}