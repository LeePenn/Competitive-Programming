#include <bits/stdc++.h>

using namespace std;

int m, n, k;
int a[10000], b[10000], h1, h2, t1, t2;

int main() {
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) a[i] = i;
    for (int i = 1; i <= n; i++) b[i] = i;
    h1 = 1, h2 = 1, t1 = m, t2 = n;
    int i = 1;
    while (i <= k) {
        printf("%d %d\n", a[h1], b[h2]);
        a[++t1] = a[h1]; b[++t2] = b[h2];
        h1++, h2++;
        i++;
    }

    return 0;
}