#include <bits/stdc++.h>

using namespace std;

int n, m;
struct edge {
    int u, v, c;
};
edge e[10000];
int tot;
int f[10000];

bool cmp(const edge &a, const edge &b) {
    return a.c < b.c;
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
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i;
    
    int ans = 0;
    int k = 0;
    for (int i = 1; i <= m; i++) {
        int p, x, y, z;
        cin >> p >> x >> y >> z;
        if (p == 1) {
            ans += z;
            if (find(x) != find(y)) k++;
            uni(x, y);
        } else {
            e[++tot].u = x;
            e[tot].v = y;
            e[tot].c = z;
        }
    }
    
    if (k == n - 1) cout << ans << endl;
    else {
        sort(e + 1, e + tot + 1, cmp);
        for (int i = 1; i <= tot; i++) {
            int uu = e[i].u, vv = e[i].v;
            if (find(uu) != find(vv)) {
                ans += e[i].c;
                uni(uu, vv);
                k++;
            }
            if (k == n - 1) break;
        }
        cout << ans << endl;
    }


    return 0;
}