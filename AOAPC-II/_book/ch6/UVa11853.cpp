// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 2;
const double W = 1000.0;
int n;
double x[N], y[N], r[N];
bool vis[N];
double Left, Right;

bool intersect(int u, int v) {
  return sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v])) < r[u] + r[v];
}

void calc_circle(int u) {
  if (x[u] - r[u] < 0) {
    Left = min(Left, y[u] - sqrt(r[u] * r[u] - x[u] * x[u]));
  }
  if (x[u] + r[u] > W) {
    Right = min(Right, y[u] - sqrt(r[u] * r[u] - (W - x[u]) * (W - x[u])));
  }
}

bool dfs(int u) {
  vis[u] = true;
  if (y[u] - r[u] < 0) return true;
  for (int v = 0; v < n; v++) {
    if (vis[v]) continue;
    if (intersect(u, v) && dfs(v)) return true;
  }
  calc_circle(u);
  return false;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1) {
    bool ok = true;
    Left = Right = W;
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf %lf", &x[i], &y[i], &r[i]);
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      if (y[i] + r[i] >= W && dfs(i)) {
        ok = false;
        break;
      }
    }
    if (ok) printf("0.00 %.2lf 1000.00 %.2lf\n", Left, Right);
    else puts("IMPOSSIBLE");
  }
  
  
  return 0;
}