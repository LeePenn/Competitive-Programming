#include <bits/stdc++.h>

using namespace std;

int f[25][3], n;

int main() {
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    f[1][0] = f[1][1] = f[1][2] = 1; // f[n][i]走n步，且第n步是左/右/上的方案数
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            f[i][0] = f[i - 1][0] + f[i - 1][2];
            f[i][1] = f[i - 1][1] + f[i - 1][2];
            f[i][2] = f[i - 1][0] + f[i - 1][1] + f[i - 1][2];
        }
    }
    printf("%d\n", f[n][0] + f[n][1] + f[n][2]);


    return 0;
}