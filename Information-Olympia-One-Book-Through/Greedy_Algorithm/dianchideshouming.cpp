#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    while (scanf("%d", &n) == 1) {
        int max = -1, x;
        double tot = 0.0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x > max) max = x;
            tot += x;
        }
        tot -= max;
        if (tot < max) printf("%.1lf\n", tot);
        else printf("%.1lf\n", (tot + max) / 2.0);
    }

    return 0;
}