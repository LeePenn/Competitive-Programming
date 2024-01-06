#include <bits/stdc++.h>

using namespace std;

int n, m;
struct edge {
    int u, v, c;
};
edge e[1000];
int tot;
int f[1000];
int x, y, z;

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
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        e[++tot].u = x;
        e[tot].v = y;
        e[tot].c = z;
    }
    
    sort(e + 1, e + tot + 1, cmp);
    int k = 0;
    int maxx = 0;
    for (int i = 1; i <= tot; i++) {
        int uu = e[i].u, vv = e[i].v;
        if (find(uu) != find(vv)) {
            uni(uu, vv);
            k++;
            maxx = e[i].c;
        }
        if (k == n - 1) break;
    }
    
    cout << k << ' ' << maxx << endl;

    return 0;
}