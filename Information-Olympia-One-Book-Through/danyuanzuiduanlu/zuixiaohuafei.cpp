#include <bits/stdc++.h>

using namespace std;

int n, m, s, e, x, y, z;
double a[1000][1000] = {0};
double d[1000] = {0};
bool v[1000];

void dijkstra() {
    memset(v, 0, sizeof(v));
    v[s] = true;
    d[s] = 1;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            d[i] = d[s] * a[s][i];
        }
    }
    
    for (int i = 1; i < n; i++) {
        int k = 0;
        double maxx = 0;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && d[j] > maxx) {
                k = j;
                maxx = d[j];
            }
        }
        if (k == e || k == 0) break;
        v[k] = true;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && d[j] < d[k] * a[k][j]) {
                d[j] = d[k] * a[k][j];
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        a[x][y] = a[y][x] = (100.0 - z) / 100;
    }
    cin >> s >> e;
    
    dijkstra();
    printf("%.8lf\n", 100 / d[e]);

    return 0;
}