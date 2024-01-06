#include <bits/stdc++.h>

using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};
int T, n, ha, la, hb, lb, maze[105][105];
bool pass[105][105];
char str[105];

bool inmaze(int r, int c) {
    return r >= 1 && r <= n && c >= 1 && c <= n;
}

bool work(int r, int c) {
    if (r == hb && c == lb) return true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (inmaze(nr, nc) && !pass[nr][nc] && maze[nr][nc] == '.') {
            pass[nr][nc] = 1;
            if (work(nr, nr)) {
                return true;
            }
            pass[nr][nc] = 0;
        }
    }

    return false;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%s", str);
            for (int j = 1; j <= n; j++) {
                maze[i][j] = str[j - 1];
            }
        }
        scanf("%d %d %d %d", &ha, &la, &hb, &lb);
        ha++, la++, hb++, lb++;
        if (maze[ha][la] == '#' || maze[hb][lb] == '#') {
            printf("NO\n");
            continue;
        }
        memset(pass, false, sizeof(pass));
        pass[ha][la] = true;
        if (work(ha, la)) printf("YES\n");
        else printf("NO\n");
    
    }


    return 0;
}