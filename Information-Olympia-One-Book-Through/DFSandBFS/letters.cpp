#include <bits/stdc++.h>

using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};
int letters[25][25], pass[26], ans;
int r, c;
char ch[10];

bool onboard(int i, int j) {
    return i >= 1 && i <= r && j >= 1 && j <= c;
}

void work(int r, int c, int p) {
    bool can = false;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (onboard(nr, nc) && !pass[letters[nr][nc]]) {
            can = true;
            pass[letters[nr][nc]] = 1;
            work(nr, nc, p + 1);
            pass[letters[nr][nc]] = 0;
        }
    }
    if (!can) {
        if (p > ans) ans = p;
    }


    return;
} 

int main() {
    scanf("%d %d", &r, &c);
    cout << r << ' ' << c << endl;
    for (int i = 1; i <= r; i++) {
        scanf("%s", ch);
        for (int j = 0; j < c; j++) {
            letters[i][j + 1] = ch[j] - 'A';
        }
    }
    
    pass[letters[1][1]] = 1;
    work(1, 1, 1);
    printf("%d\n", ans);

    return 0;
}