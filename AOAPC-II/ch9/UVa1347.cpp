#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};
const int MAXN = 1000 + 4;
double dist[MAXN][MAXN], dp[MAXN][MAXN], INF = 1e9;
Point p[MAXN];
int n;

double getDist(int i, int j) {
    double a = p[i].x - p[j].x, b = p[i].y - p[j].y;
    return sqrt(a * a + b * b);
}


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> p[i].x >> p[i].y;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = getDist(i, j);
            }
        }
        
        for (int i = n - 1; i >= 2; i--) {
            for (int j = 1; j < i; j++) {
                if (i == n - 1) {
                    dp[i][j] = dist[i][n] + dist[j][n];
                } else {
                    dp[i][j] = min(dp[i + 1][j] + dist[i][i + 1], dp[i + 1][i] + dist[j][i + 1]);
                }
            }
        }
        
        printf("%.2lf\n", dist[1][2] + dp[2][1]);
        
    }
    


    return 0;
}