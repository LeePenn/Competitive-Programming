#include <bits/stdc++.h>

using namespace std;

int R, C, ans[10][10], steps;
const int dirs[4][2] = {
    {2, 1}, {-2, 1}, {1, 2}, {-1, 2}
};

void print() {
    int tot = 0;
    for (int i = 0; i <= C; i++) {
        for (int j = 0; j <= R; j++) {
            if (ans[j][i]) {
                printf("%d,%d", j, i);
                tot++;
                if (tot < steps) printf("->");
            }
        }
    }
    printf("\n");

    return;
}

bool onboard(int r, int c) {
    return r >= 0 && r <= R && c >= 0 && c <= C;
}

void work(int r, int c) {
    if (r == R && c == C) {
        print();
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dirs[i][0], nc = c + dirs[i][1];
        if (onboard(nr, nc)) {
            ans[nr][nc] = 1;
            steps++;
            work(nr, nc);
            steps--;
            ans[nr][nc] = 0;
        }
    }

}

int main() {
    R = 4, C = 8;
    memset(ans, 0, sizeof(ans));
    ans[0][0] = 1;
    steps = 1;
    work(0, 0);


    return 0;
}