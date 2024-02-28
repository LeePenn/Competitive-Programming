// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 22;
int n, k, m, a[N];

int get(int p, int d, int cnt) {
    while (cnt--) {
        do {p = (p - 1 + d + n) % n + 1;} while (!a[p]);
    }
    return p;
}

int main() {
    while (scanf("%d %d %d", &n, &k, &m) == 3 && (n + k + m)) {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) a[i] = i;
        int left = n, p1 = n, p2 = 1;
        while (left) {
            p1 = get(p1, 1, k);
            p2 = get(p2, -1, m);
            printf("%3d", p1);
            left--;
            if (p1 != p2) printf("%3d", p2), left--;
            if (left) printf(",");
            a[p1] = a[p2] = 0;
        }
        printf("\n");
    }
    
    return 0;
}