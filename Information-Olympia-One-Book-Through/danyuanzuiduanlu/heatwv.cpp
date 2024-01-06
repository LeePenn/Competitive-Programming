#include <bits/stdc++.h>

using namespace std;

const int MAX = 0x7fffffff >> 1;
int t, c, ts, te;
int dis[2500][2500];
int d[2500];
bool v[2500];

int main() {
    cin >> t >> c >> ts >> te;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= t; j++) 
            dis[i][j] = MAX;
    }
    for (int i = 1; i <= c; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        dis[x][y] = z;
    }
    
    memset(v, 0, sizeof(v));
    d[ts] = 0;
    v[ts] = true;
    for (int i = 1; i <= t; i++) {
        if (!v[i]) d[i] = dis[ts][i];
    }
    
    for (int i = 1; i < t; i++) {
        int k = 0;
        int maxx = MAX;
        for (int j = 1; j <= t; j++) {
            if (!v[j] && d[j] < maxx) {
                k = j;
                maxx = d[j];
            }
        }
        if (k == 0 || k == te) break;
        v[k] = true;
        for (int j = 1; j <= t; j++) {
            if (!v[j] && d[j] > d[k] + dis[k][j]) {
                d[j] = d[k] + dis[k][j];
            }
        }
    }
    cout << d[te] << endl;
    return 0;
}