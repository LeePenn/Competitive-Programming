#include <bits/stdc++.h>

using namespace std;

const int N = 1000004;
int n, m, k;
int x[N], y[N], d[N], c[N];
int *a[N];

int main() {
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= k; i++) {
        scanf("%d%d%d", &x[i], &y[i], &d[i]);
        c[y[i]]++;
    }

    for (int i = 1; i <= m; i++) {
        a[i] = new int[c[i]];
    }

    for (int i = 1; i <= k; i++) {
        *a[y[i]] = d[i];
        a[y[i]]++;
    }

    for (int i = 1; i <= m; i++) {
        a[i] -= c[i];
        for (int j = 1; j <= c[i]; j++, a[i]++) {
            printf("%d ", *a[i]);
        }
    }
    printf("\n");
    return 0;
}