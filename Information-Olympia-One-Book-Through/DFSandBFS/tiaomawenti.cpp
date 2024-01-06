#include <bits/stdc++.h>

using namespace std;

const int dr[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int a[8][8], b[8][8], ans;

void print() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) printf("%02d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
    
    return;
}

bool onboard(int r, int c) {
    return r >= 1 && r <= 5 && c >= 1 && c <= 5;
    
}

void work(int r, int c, int steps) {
    if (steps > 25) {
        ans++;
        if (ans < 6) print();
        return;
    }
    
    for (int i = 0; i <= 7; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (!b[nr][nc] && onboard(nr, nc)) {
            a[nr][nc] = steps;
            b[nr][nc] = 1;
            work(nr, nc, steps + 1);
            a[nr][nc] = 0;
            b[nr][nc] = 0;
        }
    }

    return;
}

int main() {
    a[1][1] = 1, b[1][1] = 1;
    work(1, 1, 2);
    printf("%d\n", ans);

    return 0;
}