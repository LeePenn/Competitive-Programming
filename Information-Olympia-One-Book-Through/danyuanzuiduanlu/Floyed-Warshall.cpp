#include <bits/stdc++.h>

using namespace std;

int n, m, px[100], py[100];
double w[100][100], dis[100][100];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> px[i] >> py[i];
    }
    cin >> m;
    memset(dis, 0x7f, sizeof(dis));
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        dis[a][b] = dis[b][a] = sqrt((px[a] - px[b]) * (px[a] - px[b]) + (py[a] - py[b]) * (py[a] - py[b]));
    }
    int s, t;
    cin >> s >> t;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && i != k && j != k) {
                    if (dis[i][k] < 1000000 && dis[k][j] < 1000000 && dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
                
            }
        }
    }
    printf("%.2lf\n", dis[s][t]);

}