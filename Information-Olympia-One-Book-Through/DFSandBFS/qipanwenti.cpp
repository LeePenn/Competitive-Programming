#include <bits/stdc++.h>

using namespace std;

int n, a[10][10], k, r[10], c[10], ans;
char str[10];

void work(int m, int cnt) {
    if (cnt == k + 1) {
        ans++;
        return;
    }
    for (int i = m; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '#' && !r[i] && !c[j]) {
                r[i] = 1, c[j] = 1;
                work(i + 1, cnt + 1);
                r[i] = 0, c[j] = 0;
            }
        }
    }
    
    return;
}

int main() {
    while (scanf("%d%d", &n, &k) == 2 && n != -1) {
        for (int i = 1; i <= n; i++) {
            scanf("%s", str);
            for (int j = 1; j <= n; j++) a[i][j] = str[j - 1];
        }
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        ans = 0;
        work(1, 1);
        printf("%d\n", ans);
    }

    return 0;
}