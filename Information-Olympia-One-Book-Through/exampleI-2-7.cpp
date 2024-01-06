#include <bits/stdc++.h>

using namespace std;

const int N = 104;
int a[N][N], b[N][N], c[N][N];

int main() {
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int t = 1; t <= m; t++) {
                c[i][j] += a[i][t] * b[t][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}