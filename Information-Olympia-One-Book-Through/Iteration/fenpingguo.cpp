#include <bits/stdc++.h>

using namespace std;

int m, n, T, f[100][100];

int main() {
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            if (j == 0 || i == 1) f[i][j] = 1;
            else if (i > j) f[i][j] = f[j][j];
            else f[i][j] = f[i - 1][j] + f[i][j - i];
        }
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m, &n);
        printf("%d\n", f[n][m]);
    }



    return 0;
}