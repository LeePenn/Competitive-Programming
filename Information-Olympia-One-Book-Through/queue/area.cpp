#include <bits/stdc++.h>

using namespace std;

int n;
char a[1000][1000];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(int r, int c) {
    int q[1000000][2];
    int front = 1, rear = 2;
    q[front][0] = r, q[front][1] = c;
    while (front < rear) {
        int cr = q[front][0], cc = q[front][1];
        a[cr][cc] = '1';
        front++;
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i], nc = cc + dc[i];
            if (nr >= 1 && nr <= n && nc >= 1 && nc <= n && a[nr][nc] == '0') {
                q[rear][0] = nr, q[rear][1] = nc;
                rear++;
            }
        }
    }
}

int main() {
    n = 1;
    while (scanf("%s", a[n] + 1) == 1) {
        n++;
    }
    for (int i = 1; i <= n; i++) if (a[1][i] == '0') bfs(1, i);
    for (int i = 1; i <= n; i++) if (a[n][i] == '0') bfs(n, i);
    for (int i = 1; i <= n; i++) if (a[i][1] == '0') bfs(i, 1);
    for (int i = 1; i <= n; i++) if (a[i][n] == '0') bfs(i, n);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            if (a[i][j] == '0') ans++;
            
    printf("%d\n", ans);
}