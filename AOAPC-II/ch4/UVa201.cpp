// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 16;
int n, m, V[N][N], H[N][N], vExp[N][N], hExp[N][N], Squares[N];

int main() {
    int id = 0;
    char buf[2];
    int x, y;
    while (scanf("%d %d", &n, &m) == 2) {
        memset(V, 0, sizeof(V));
        memset(H, 0, sizeof(H));
        memset(vExp, 0, sizeof(vExp));
        memset(hExp, 0, sizeof(hExp));
        memset(Squares, 0, sizeof(Squares));
        for (int i = 1; i <= m; i++) {
            scanf("%s %d %d", buf, &x, &y);
            if (buf[0] == 'H') H[x][y] = 1;
            else V[y][x] = 1;
        }
        for (int i = n; i; i--) {
            for (int j = n; j; j--) {
                if (H[i][j]) hExp[i][j] = hExp[i][j + 1] + 1;
                if (V[i][j]) vExp[i][j] = vExp[i + 1][j] + 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int s = 1; s <= min(hExp[i][j], vExp[i][j]); s++) {
                    if (hExp[i + s][j] >= s && vExp[i][j + s] >= s) {
                        Squares[s]++;
                    }
                }
            }
        }
        if (id > 0) printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", ++id);
        bool found = false;
        for (int i = 1; i <= n; i++) {
            if (Squares[i]) {
                printf("%d square (s) of size %d\n", Squares[i], i);
                found = true;
            }
        }
        if (!found) puts("No completed squares can be found.");
    }
    return 0;
}