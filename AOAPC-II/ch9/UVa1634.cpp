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
struct Point {
    int x, y;
    Point(int x = 0, int y = 0): x(x), y(y) {}
    Point &operator =(const Point &p) {
        x = p.x, y = p.y;
        return *this;
    }
    bool operator <(const Point &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};
typedef Point Vector;
Vector operator +(const Vector &a, const Vector &b) {
    return Vector(a.x + b.x, a.y + b.y);
}
Vector operator -(const Vector &a, const Vector &b) {
    return Vector(a.x - b.x, a.y - b.y);
}
Vector operator *(const Vector &a, int k) {
    return Vector(a.x * k, a.y * k);
}
bool operator ==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}
bool operator !=(const Point &a, const Point &b) {
    return !(a == b);
}
int Dot(const Vector &a, const Vector &b) {
    return a.x * b.x + a.y * b.y;
}
int Cross(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}
int Area(const Point &a, const Point &b, const Point &c) {
    return abs(Cross(b - a, c - a));
}
bool inTriangle(const Point &p, const Point &a, const Point &b, const Point &c) {
    int s = Area(a, b, c), s0 = Area(p, a, b), s1 = Area(p, b, c), s2 = Area(p, a, c);
    return s0 && s1 && s2 && s == (s0 + s1 + s2);
}
const int N = 100 + 4, INF = 0x7f7f7f7f;
int n, dp[N][N];
Point d[N], q[N];
int DP(const int m) {
    int ans = 0;
    memset(dp, 0, sizeof(dp));
    // 第一个点已经选定了
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j < i; ++j) {
            for (int k = j + 1; k < i; ++k) {
                if (q[k] != q[i] && q[k] != q[j] && inTriangle(q[k], Point(0, 0), q[j], q[i])) {
                    dp[j][i] = -INF;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j < i; ++j) if (0 == dp[j][i]) {
            int &t = dp[j][i], s = Cross(q[j], q[i]);
            t = s;
            for (int k = j - 1; k > 0; --k) {
                if (Cross(q[j] - q[k], q[i] - q[j]) >= 0) {
                    t = max(t, s + dp[k][j]);
                }
                if (Cross(q[k], q[j]) == 0) break;
            }
            ans = max(ans, t);
        }
    }
    return ans;
}
int solve() {
    int m, ans = 0;
    sort(d + 1, d + n + 1);
    auto cmp = [](const Point &a, const Point &b) {
        return Cross(a, b) > 0 || (Cross(a, b) == 0 && Dot(a, a) < Dot(b, b));
    };
    for (int i = 0; i <= n; ++i) {
        m = 0;
        for (int j = i + 1; j <= n; ++j) {
            q[++m] = d[j] - d[i];
        }
        sort(q + 1, q + m + 1, cmp);
        ans = max(ans, DP(m));
    }
    return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &d[i].x, &d[i].y);
    }
    double ans = 0.5 * solve();
    printf("%.1lf\n", ans);
  }
  
  

  return 0;
  
  
}