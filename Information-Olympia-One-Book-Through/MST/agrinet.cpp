#include <bits/stdc++.h>

using namespace std;

int n;
struct edge {
    int x, y, w;
};
edge e[10000];
int tot;
int f[10000];

bool cmp(const edge &e1, const edge &e2) {
    return e1.w < e2.w;
}

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void uni(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) f[fy] = fx;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a != 0) {
                e[++tot].x = i;
                e[tot].y = j;
                e[tot].w = a;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) f[i] = i;
    
    sort(e + 1, e + tot + 1, cmp);
    
    int k = 0;
    int ans = 0;
    for (int i = 1; i <= tot; i++) {
        if (find(e[i].x) != find(e[i].y)) {
            ans += e[i].w;
            uni(e[i].x, e[i].y);
            k++;
        }
        if (k == n - 1) break;
    }
    cout << ans << endl;
    
    return 0;
}