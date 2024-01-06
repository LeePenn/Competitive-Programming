#include <bits/stdc++.h>

using namespace std;

int n, m, a[10000], s[10000];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(s, 0, sizeof(s));
    int mi = 100000, k;
    for (int i = 1; i <= n; i++) {
        mi = 100000;
        for (int j = 1; j <= m; j++) {
            if (s[j] < mi) mi = s[j], k = j;
        }
        s[k] += a[i];
    }
    
    int mx = -100000;
    for (int i = 1; i <= m; i++) {
        if (s[i] > mx) mx = s[i];
    }
    printf("%d\n", mx);
    
    return 0;
}