#include <bits/stdc++.h>

using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};
int w, h, house[24][24], sx, sy, tot;
bool v[24][24];
char str[24];

bool inbound(int r, int c, int R, int C) {
    return r >= 1 && r <= R && c >= 1 && c <= C; 
}

void work(int r, int c) {
    tot++;
    v[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (inbound(nr, nc, h, w) && !v[nr][nc] && house[nr][nc] == '.') {
            work(nr, nc);
        }
    
    }

    return;
}

int main() {
    while (scanf("%d %d", &w, &h) == 2 && w && h) {
        for (int i = 1; i <= h; i++) {
            scanf("%s", str);
            for (int j = 1; j <= w; j++) {
                house[i][j] = str[j - 1];
                if (str[j - 1] == '@') sx = i, sy = j;
            }
        }
        memset(v, false, sizeof(v));
        tot = 0;
        work(sx, sy);
        printf("%d\n", tot);
    }



    return 0;
}
