#include <bits/stdc++.h>

using namespace std;

int n, m;
double a[1000][2];
int s, t;
double d[1000];
int e[1000][2];
double w[1000];


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    cin >> m;
    for (int i = 1; i <= n; i++) {
        d[i] = 0x7fffffff >> 1;
    }
    
    for (int i = 1; i <= m; i++) {
        cin >> e[i][0] >> e[i][1];
        w[i] = sqrt(
        (a[e[i][0]][0] - a[e[i][1]][0]) * (a[e[i][0]][0] - a[e[i][1]][0]) + 
        (a[e[i][0]][1] - a[e[i][1]][1]) * (a[e[i][0]][1] - a[e[i][1]][1])
        );
    }
    
    cin >> s >> t;
    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[e[j][0]] + w[j] < d[e[j][1]]) d[e[j][1]] = d[e[j][0]] + w[j];
            if (d[e[j][1]] + w[j] < d[e[j][0]]) d[e[j][0]] = d[e[j][1]] + w[j];
        }
    }
    printf("%.2lf\n", d[t]);
    

    return 0;
}