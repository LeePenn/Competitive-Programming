#include <bits/stdc++.h>

using namespace std;

int n, k;
char s[15];
long long f[15][15];

long long calc(int l, int r) {
    long long ret = 0;
    for (int i = l; i <= r; i++) {
        ret = ret * 10 + (s[i] - '0');
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for (int i = n; i >= 1; i--) s[i] = s[i - 1];
    for (int i = 1; i <= n; i++) {
        f[i][0] = calc(1, i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            for (int m = j; m <= i - 1; m++) {
                f[i][j] = max(f[i][j], f[m][j - 1] * calc(m + 1, i));
            }
        }
    }
    printf("%lld\n", f[n][k]);
    return 0;
}