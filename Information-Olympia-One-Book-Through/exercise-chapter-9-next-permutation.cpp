#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1024 + 10;

int a[MAX_N];
int t, n, k;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= k; i++) {
            next_permutation(a + 1, a + n + 1);
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}