#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>

#define LL long long
using namespace std;

const int N = 1000 + 4;
const double INF = 1e30;
struct Section {
  double x, c, dt;
  bool operator <(const Section& rhs) const {
    return x < rhs.x;
  }
}s[N];
int kase, n;
int vis[N][N][2];
double v, x, dp[N][N][2];
double psdt[N];
double cost(double x1, double x2, int i, int j) {
  double finished_dt = 0;
  if (i >= 0 && j >= 0) {
    finished_dt += psdt[j] - psdt[i - 1];
  }
  return (psdt[n] - finished_dt) * fabs(x1 - x2) / v;
}
double DP(int i, int j, int p) {
  if (i == 1 && j == n) return 0;
  double &ans = dp[i][j][p];
  if (vis[i][j][p] == kase) return ans;
  vis[i][j][p] = kase;
  
  ans = INF;
  double x = (p == 0 ? s[i].x : s[j].x);
  if (i > 1) ans = min(ans, DP(i - 1, j, 0) + cost(x, s[i - 1].x, i, j));
  if (j < n) ans = min(ans, DP(i, j + 1, 1) + cost(x, s[j + 1].x, i, j));
  return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  memset(vis, 0, sizeof(vis));
  while (scanf("%d%lf%lf", &n, &v, &x) == 3 && n) {
    kase++;
    double sumc = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lf%lf%lf", &s[i].x, &s[i].c, &s[i].dt);
      sumc += s[i].c;
    }
    
    sort(s + 1, s + n + 1);
    
    psdt[0] = 0;
    for (int i = 1; i <= n; ++i) {
      psdt[i] = psdt[i - 1] + s[i].dt;
    }
    
    s[0].x = -INF;
    s[n + 1].x = INF;
    double ans = INF;
    for (int i = 0; i <= n; ++i) {
      if (x > s[i].x && x < s[i + 1].x) {
        if (i < n) ans = min(ans, DP(i + 1, i + 1, 0) + cost(x, s[i + 1].x, -1, -1));
        if (i > 0) ans = min(ans, DP(i, i, 0) + cost(x, s[i].x, -1, -1));
      }
    }
    printf("%.0lf\n", floor(ans + sumc));
  }
  
  

  return 0;
}