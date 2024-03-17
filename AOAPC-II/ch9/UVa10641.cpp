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
const double EPS = 1e-10;
int dcmp(double x) {
    if (fabs(x) < EPS) return 0;
    return x < 0 ? -1 : 1;
}
struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};
typedef Point Vector;
Vector operator + (const Vector &A, const Vector &B) {
    return Point(A.x + B.x, A.y + B.y);
}
Vector operator - (const Vector &A, const Vector &B) {
    return Point(A.x - B.x, A.y - B.y);
}
Vector operator * (const Vector &A, double p) {
    return Vector(A.x * p, A.y * p);
}
Vector operator / (const Vector &A, double p) {
    return Vector(A.x / p, A.y / p);
}
bool operator <(const Point &A, const Point &B) {
    return A.x < B.x || (A.x == B.x && A.y < B.y);
}
bool operator ==(const Point &A, const Point &B) {
    return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}
double Dot(const Vector &A, const Vector &B) {
    return A.x * B.x + A.y * B.y;
}
double Cross(const Vector &A, const Vector &B) {
    return A.x * B.y - A.y * B.x;
}
double Length(const Vector &A) {
    return sqrt(Dot(A, A));
}
const int N = 30 + 2, M = 1000 + 3, INF = INT_MAX;
int n, m, c[M];
Point V[N << 1], LT[M], O;
int L[M], R[M], D[N << 1];
// 画图理解，O 和 lt 在 AB 线段的两边
bool canCover(const Point &lt, const Point &A, const Point &B) {
    return dcmp(Cross(B - A, lt - A) * Cross(B - A, O - A)) < 0;
}
void init() {
    for (int i = 0; i < m; ++i) {
        auto lt = LT[i];
        int &l = L[i], &r = R[i];
        l = -1, r = -1;
        for (int j = 0; j < n; ++j) {
            bool c1 = canCover(lt, V[(j - 1 + n) % n], V[j]),
                 c2 = canCover(lt, V[j], V[j + 1]);
            if (!c1 && c2) l = j;
            if (c1 && !c2) r = j;
        }
        if (r < l) r += n;
    }
}
int solve() {
    int ans = INF;
    // 类似防卫线，但不同的是，防卫线是贪心，这里是决策 DP
    for (int i = 0; i < n; ++i) {
        fill_n(D, 2 * n + 1, INF);
        // 一个光源不可能只照射到一个点
        D[i] = 0;
        for (int j = i; j < i + n; ++j) {
            if (D[j] < INF) {
                for (int li = 0; li < m; ++li) {
                    if (j >= L[li] && j <= R[li]) {
                        // 光照到所有点不够，还要照到所有的边，所以最后要照到 i + n
                        int r = min(R[li], i + n);
                        D[r] = min(D[r], D[j] + c[li]);
                    }
                }
            }
        }
        ans = min(ans, D[i + n]);
    }
    
    return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    O = {0, 0};
    for (int i = 0; i < n; ++i) {
        auto &v = V[i];
        scanf("%lf%lf", &(v.x), &(v.y));
        O = O + v, V[i + n] = v;
    }
    O = O / n;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        auto &lt = LT[i];
        scanf("%lf%lf", &(lt.x), &(lt.y));
        scanf("%d", &c[i]);
    }
    
    init();
    int ans = solve();
    if (ans == INF) printf("Impossible.\n");
    else printf("%d\n", ans);
  }
  
  

  return 0;
  
  
}