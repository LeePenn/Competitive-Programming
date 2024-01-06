#include <bits/stdc++.h>

using namespace std;

int f[1000][2], n;

int main() {
    scanf("%d", &n);
    memset(f, 0, sizeof(f));
    f[1][0] = 9, f[1][1] = 1;
    int x;
    for (int i = 2; i <= n; i++) {
        x = f[1][0];
        if (i == n) x--;
        f[i][0] = (f[i - 1][0] * x + f[i - 1][1]) % 12345;
        f[i][1] = (f[i - 1][1] * x + f[i - 1][0]) % 12345;
    }
    cout << f[n][0] << endl;

    return 0;
}