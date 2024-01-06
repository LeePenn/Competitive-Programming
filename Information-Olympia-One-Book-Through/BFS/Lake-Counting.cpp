#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int n, m;
char land[100][100];
int q[1000][2];
int hd, tail;

void work(int r, int c) {
    hd = 0, tail = 1;
    q[1][0] = r, q[1][1] = c;
    land[r][c] = '.';
    do {
        hd++;
        for (int i = 0; i < 8; i++) {
            int nr = q[hd][0] + dx[i], nc = q[hd][1] + dy[i];
            if (nr < 1 || nr > n || nc < 1 || nc > m) continue;
            if (land[nr][nc] == '.') continue;
            land[nr][nc] = '.';
            tail++;
            q[tail][0] = nr, q[tail][1] = nc;
        }
    } while (hd < tail);
    
}

int main() {
    cin >> n >> m;
    char s[100];
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) land[i][j] = s[j - 1];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (land[i][j] == 'W') {
                work(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}   