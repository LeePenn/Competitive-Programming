#include <bits/stdc++.h>

using namespace std;

int n, a[100], g[100][100];

int main() {    
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            g[i][j] = 0x7fffffff >> 1;
    
    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cin >> x >> y;
        g[i][i] = 0;
        if (x != 0) g[i][x] = g[x][i] = 1;
        if (y != 0) g[i][y] = g[y][i] = 1;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i != k) {
                for (int j = 1; j <= n; j++) {
                    if (i != j && k != j && g[i][k] + g[k][j] < g[i][j]) {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }
    }
    
    int mind = 0x7fffffff >> 1;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j && g[i][j] < 0x7fffffff >> 1) {
                cur += g[i][j] * a[j];
            }
        }
        mind = min(mind, cur);
    }
    cout << mind << endl;

    return 0;
}