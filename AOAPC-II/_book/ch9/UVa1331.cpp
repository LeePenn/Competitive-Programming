#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

const double eps = 1e-10;
int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
struct Point {
  double x, y;
  Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};
typedef Point Vector;

Vector operator + (const Vector &a, const Vector &b) {
  return Vector(a.x + b.x, a.y + b.y);
}
Vector operator - (const Vector &a, const Vector &b) {
  return Vector(a.x - b.x, a.y - b.y);
}
Vector operator * (const Vector &a, double p) {
  return Vector(a.x * p, a.y * p);
}
bool operator == (const Point &a, const Point &b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
bool operator < (const Point &a, const Point &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
double Dot(const Vector &a, const Vector &b) {
  return a.x * b.x + a.y * b.y;
}
double Cross(const Vector &a, const Vector &b) {
  return a.x * b.y - a.y * b.x;
}
double Length(const Vector &a) {
  return sqrt(Dot(a, a));
}

bool SegmentProperIntersection(const Point &a1, const Point &a2, const Point &b1, const Point &b2) {
  double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1);
  double c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
  return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
bool OnSegment(const Point &p, const Point &a1, const Point &a2) {
  return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

typedef vector<Point> Polygon;

int isPointInPolygon(const Point &p, const Polygon &poly) {
  int n = poly.size();
  int wn = 0;
  for (int i = 0; i < n; ++i) {
    const Point &p1 = poly[i];
    const Point &p2 = poly[(i + 1) % n];
    if (p1 == p || p2 == p || OnSegment(p, p1, p2)) return -1;
    int k = dcmp(Cross(p2 - p1, p - p1));
    int d1 = dcmp(p1.y - p.y);
    int d2 = dcmp(p2.y - p.y);
    if (k > 0 && d1 <= 0 && d2 > 0) wn++;
    if (k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  if (wn != 0) return 1;
  return 0;
}

bool isDiagonal(const Polygon &poly, int a, int b) {
  int n = poly.size();
  for (int i = 0; i < n; ++i) {
    if (i != a && i != b && OnSegment(poly[i], poly[a], poly[b])) return false;
  }
  for (int i = 0; i < n; ++i) {
    if (SegmentProperIntersection(poly[i], poly[(i + 1) % n], poly[a], poly[b])) return false;
  }
  Point midp = (poly[a] + poly[b]) * 0.5;
  return (isPointInPolygon(midp, poly) == 1);
}

const int N = 100 + 5;
const double INF = 1e9;
double dp[N][N];
double Solve(const Polygon &poly) {
  int n = poly.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) dp[i][j] = -1;
  }
  
  for (int l = 2; l <= n; ++l) {
    for (int i = 0; i + l - 1 < n; ++i) {
      int j = i + l - 1;
      if (i + 1 == j) dp[i][j] = 0;
      else if (!(i == 0 && j == n - 1) && !isDiagonal(poly, i, j)) dp[i][j] = INF;
      else {
        dp[i][j] = INF;
        for (int k = i + 1; k < j; ++k) {
          double m = max(dp[i][k], dp[k][j]);
          double area = fabs(Cross(poly[j] - poly[i], poly[k] - poly[i])) / 2.0;
          m = max(m, area);
          dp[i][j] = min(dp[i][j], m);
        }
      }
    }
  }
  return dp[0][n - 1];
  
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
    
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    double x, y;
    Polygon poly;
    for (int i = 1; i <= n; ++i) {
      scanf("%lf%lf", &x, &y);
      poly.push_back(Point(x, y));
    }
    printf("%.1lf\n", Solve(poly));
  }


  return 0;
}