#include <bitset>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <queue>

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 50;
const double PI = acos(-1);
double dist(double p1, double p2) {
    double a = fabs(p2 - p1);
    if (a > 0.5) a = 1 - a;
    return 2 * sin(a * PI);
}
double calArea(double a, double b, double c) {
    double x = (a + b + c) / 2;
    return sqrt(x * (x - a) * (x - b) * (x - c));
}
int n, m;
double p[N], d[N][N], area[N][N][N], dp[N][N][N];
double DP() {
    memset(dp, 0, sizeof(dp));
    for (int k = 3; k <= m; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int x = i + 1; x < n; ++x) {
                for (int j = x + 1; j < n; ++j) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][x][k - 1] + area[i][j][x]);
                }
            }
        }
    }
    
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) ans = max(ans, dp[i][j][m]);
    }
    return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (scanf("%d%d", &n, &m) == 2 && n) {
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &p[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            d[i][j] = d[j][i] = dist(p[i], p[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                area[i][j][k] = area[i][k][j] = 
                area[j][i][k] = area[j][k][i] = 
                area[k][i][j] = area[k][j][i] = 
                calArea(d[i][j], d[j][k], d[k][i]);
            }
        }
    }
    
    printf("%.6lf\n", DP());
  }
  
  

  return 0;
  
  
}