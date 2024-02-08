#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 10;
int n, m;
char board[N][N];
struct Grid {
    int bits[4];
    void clear() {
        memset(bits, 0, sizeof(bits));
    }
    
    void set(int x, int y) {
        int u = x * m + y;
        bits[u >> 5] |= (1 << (u & 31));
    }
    
    bool canCover(const Grid &g) const {
        return (bits[0] & g.bits[0]) == g.bits[0] 
        && (bits[1] & g.bits[1]) == g.bits[1] 
        && (bits[2] & g.bits[2]) == g.bits[2];
    }
    
    Grid() {
        clear();
    }
};
Grid cover[N * N + 5], target;
const int dirs[8][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
};
int maxd;

bool inBoard(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool dfs(int d, const Grid &g, int cur) {
    if (d > maxd) {
        return false;
    }
    if (g.canCover(target)) {
        return true;
    }
    if (d + 1 > maxd) {
        return false;
    }
    if (cur > m * n) {
        return false;
    }
    
    if (dfs(d, g, cur + 1)) return true;
    
    Grid ng = g;
    int *b = cover[cur].bits;
    ng.bits[0] |= b[0]; ng.bits[1] |= b[1]; ng.bits[2] |= b[2];
    if (dfs(d + 1, ng, cur + 1)) return true;
    
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int kase = 1;
    string line;
    while (scanf("%d", &n) && n) {
        printf("Case %d: ", kase);
        kase++;
        
        scanf("%d", &m);
        getline(cin, line);
        char t[10];
        target.clear();
        memset(cover, 0, sizeof(cover));
        for (int i = 0; i < n; ++i) {
            scanf("%s", t);
            for (int j = 0; j < m; ++j) {
                board[i][j] = t[j];
                if (t[j] == 'X') {
                    target.set(i, j);
                }
                for (int k = 0; k < 8; ++k) {
                    int nx = i, ny = j;
                    while (inBoard(nx, ny)) {
                        cover[i * m + j].set(nx, ny);
                        nx += dirs[k][0];
                        ny += dirs[k][1];
                    }
                }
            }
        }
        
        Grid g;
        for (maxd = 0; ; ++maxd) {
            g.clear();
            if (dfs(0, g, 0)) {
                printf("%d\n", maxd);
                break;
            }
        }
    }

    return 0;
}