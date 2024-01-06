#include <bits/stdc++.h>

using namespace std;

int f[10000][10000];
char a[10000], b[10000], aa[10000], bb[10000];

int main() {
    scanf("%s %s", a, b);
    int n = strlen(a), m = strlen(b);
    for (int i = 1; i <= n; i++) aa[i] = a[i - 1];
    for (int i = 1; i <= m; i++) bb[i] = b[i - 1];
    f[0][m] = f[n][0] = f[0][1] = f[1][0] = f[0][0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
            ans = max(ans, f[i][j]);
        }
    }
    
    cout << ans << endl;

    return 0;
}