#include <bits/stdc++.h>

using namespace std;

int n, a[100][100], f[100][100][100];

int main() {
    memset(a, 0, sizeof(a));
    cin >> n;
    int x, y, z;
    while (scanf("%d%d%d", &x, &y, &z) == 3 && x && y && z) {
        a[x][y] = z;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= n; l++) {
                int temp = a[i][j];
                // 重复只取1格
                if (i != l) temp += a[l][i + j - l];
                int temp1 = max(f[i - 1][j][l - 1], f[i - 1][j][l]);
                int temp2 = max(f[i][j - 1][l - 1], f[i][j - 1][l]);
                f[i][j][l] = max(temp1, temp2) + temp;
            }
        }
    }
    cout << f[n][n][n] << endl;
    
    return 0;
}