#include <bits/stdc++.h>

using namespace std;

int n, px[155], py[155];
double dis[155][155];
long long MAX = 1000000000;
double maxx[155];
char x;

double get_dis(int i, int j) {
    return sqrt((px[i] - px[j]) * (px[i] - px[j]) + (py[i] - py[j]) * (py[i] - py[j]));
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> px[i] >> py[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = MAX;
            cin >> x;
            if (x == '1') {
                dis[i][j] = dis[j][i] = get_dis(i, j);
            }
        }
    }
    // Floyed-Warshall    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && i != k && j != k) {
                    if (dis[i][k] < MAX - 1 && dis[k][j] < MAX - 1 && dis[i][j] > dis[i][k] + dis[k][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
    }
    
    memset(maxx, 0, sizeof(maxx));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && dis[i][j] < MAX - 1) {
                maxx[i] = max(maxx[i], dis[i][j]);
            }
        }
    }
    
    double ans = MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && dis[i][j] > MAX - 1) {
                double temp = maxx[i] + maxx[j] + get_dis(i, j);
                if (temp < maxx[i]) temp = maxx[i];
                ans = min(ans, temp);
            }
        }
    }
    
    printf("%.6f\n", ans);
    

    return 0;
}