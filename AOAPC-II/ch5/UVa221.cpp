// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 102;
struct Building {
    double x, y, w, d, h;
    int id;
    bool operator < (const Building& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
}b[N];
double x[N << 1];
int n;

bool cover(int i, double t) {
    return b[i].x <= t && b[i].x + b[i].w >= t;
}

bool visible(int i, double t) {
    if (!cover(i, t)) return false;
    for (int k = 1; k <= n; k++) {
        if (b[k].y < b[i].y && cover(k, t) && b[k].h >= b[i].h) return false;
    }
    return true;
}

int main() {
    int t = 0;
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%lf %lf %lf %lf %lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
            b[i].id = i;
            int k = i << 1;
            x[k - 1] = b[i].x, x[k] = b[i].x + b[i].w;
            
        }
        sort(b + 1, b + n + 1);
        sort(x + 1, x + 2 * n + 1);
        int m = unique(x + 1, x + 2 * n + 1) - (x + 1);
        if (t) puts("");
        printf("For map #%d, the visible buildings are numbered as follows:\n%d", ++t, b[1].id);
        for (int i = 2; i <= n; i++) {
            bool can = false;
            for (int j = 1; j < m; j++) {
                double t = (x[j + 1] + x[j]) / 2;
                if (visible(i, t)) {
                    can = true;
                    break;
                }
            }
            if (can)
                printf(" %d", b[i].id);
        }
        puts("");
    }
    
    return 0;
}