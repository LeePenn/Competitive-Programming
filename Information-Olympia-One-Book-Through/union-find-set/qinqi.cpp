#include <bits/stdc++.h>

using namespace std;

int n, m, f[100000], sz[100000];
char c[3];
int a, b;

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void uni(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        f[fy] = fx;
        sz[fx] += sz[fy];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        sz[i] = 1;
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%s", c);
        if (c[0] == 'M') {
            cin >> a >> b;
            uni(a, b);
        } else {
            cin >> a;
            int fa = find(a);
            cout << sz[fa] << endl;
        }
    }

    return 0;
}