#include <bits/stdc++.h>

using namespace std;

int n, m;
struct edge {
    int u, v, c;
};
edge e[1000000];
int tot;
int f[1000000];

inline int get_num(int i, int j) {
    return (i - 1) * n + j;
}

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
    for (int i = 1; i <= n * m; i++) f[i] = i;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            int a = get_num(i, j), b = get_num(i, j + 1);
            e[++tot].u = a;
            e[tot].v = b;
            e[tot].c = 2;
        }
    }
    
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i < n; i++) {
            int a = get_num(i, j), b = get_num(i + 1, j);
            e[++tot].u = a;
            e[tot].v = b;
            e[tot].c = 1;
        }
    }
    
    sort(e + 1, e + tot + 1, cmp);
    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        uni(get_num(x1, y1), get_num(x2, y2));
    }
    
    int ans = 0;
    for (int i = 1; i <= tot; i++) {
        int uu = e[i].u, vv = e[i].v;
        if (find(uu) != find(vv)) {
            uni(uu, vv);
            ans += e[i].c;
        }
    }
    cout << ans << endl;
    

    return 0;
}