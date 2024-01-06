#include <bits/stdc++.h>

using namespace std;

const int dr[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int T, n, m, maze[12][12], x, y, ans;

bool inbound(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void work(int r, int c, int s) {
    if (s > n * m) {
        ans++; 
        return;
    }
    
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (inbound(nr, nc) && !maze[nr][nc]) {
            maze[nr][nc] = 1;
            work(nr, nc, s + 1);
            maze[nr][nc] = 0;
        }
    }

    return;
}

int main() {    
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &x, &y);
        ans = 0;
        memset(maze, 0, sizeof(maze));
        maze[x][y] = 1;
        work(x, y, 2);
        printf("%d\n", ans);
        
    
    }


    return 0;
}