#include <bits/stdc++.h>

using namespace std;

int n, m, a[100], b[100], r[100], p[100];

int main() {    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        r[a[i]]++;
        p[b[i]]++;
    }
    for (int i = 1; i <= n; i++) if (p[i] == 0) printf("%d\n", i);
    int max1 = 0, maxn = -1;
    for (int i = 1; i <= n; i++) if (r[i] > max1) {
        max1 = r[i];
        maxn = i;
    }
    printf("%d\n", maxn);
    for (int i = 1; i <= m; i++) if (a[i] == maxn) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}