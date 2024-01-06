#include <bits/stdc++.h>

using namespace std;

int k, w, s;
struct gold {
    int n;
    double all, money;
} g[100];

bool cmp(const gold &g1, const gold &g2) {
    return g1.money > g2.money;
}

int main() {
    cin >> k;
    while (k--) {
        cin >> w >> s;
        for (int i = 1; i <= s; i++) {
            cin >> g[i].n >> g[i].all;
            g[i].money = g[i].all / (g[i].n * 1.0);
        }
        double ans = 0;
        sort(g + 1, g + s + 1, cmp);
        int i;
        for (i = 1; i <= s; i++) {
            if (w < g[i].n) {
                break;
            }
            w -= g[i].n;
            ans += g[i].all;
        }
        if (i <= s && w < g[i].n) {
            ans += w * g[i].money;
        }
        
        printf("%.2lf\n", ans);
    }

    return 0;
}