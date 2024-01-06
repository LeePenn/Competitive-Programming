#include <bits/stdc++.h>

using namespace std;

const double MAX = 1e20;
int n, px[1000], py[1000];
int m, s, e;
double dis[1000][1000];
bool v[1000];
double f[1000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> px[i] >> py[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = MAX;
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dis[x][y] = dis[y][x] = sqrt((px[x] - px[y]) * (px[x] - px[y]) + (py[x] - py[y]) * (py[x] - py[y]));
    }
    cin >> s >> e;
    memset(v, 0, sizeof(v));
    f[s] = 0;
    for (int i = 1; i <= n; i++) f[i] = dis[s][i];
    for (int i = 1; i < n; i++) {
        int k = 0;
        double mins = MAX;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && f[j] < mins) {
                k = j;
                mins = f[j];
            }
        }
        if (k == 0) break;
        v[k] = true;
        for (int j = 1; j <= n; j++) {
            if (f[j] > f[k] + dis[k][j]) {
                f[j] = f[k] + dis[k][j];
            }
        }
    }
    printf("%.2lf\n", f[e]);

}