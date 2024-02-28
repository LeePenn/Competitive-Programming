// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m;
int a[N];

int main() {
    int id = 0;
    while (cin >> n >> m && (n + m)) {
        printf("CASE# %d:\n", ++id);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= m; i++) {
            int q;
            cin >> q;
            int x = lower_bound(a + 1, a + n + 1, q) - a;
            if (x > n || a[x] != q) printf("%d not found\n", q);
            else printf("%d found at %d\n", q, x);
        }
    }
    
    return 0;
}