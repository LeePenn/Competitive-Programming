// Joker
#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x, y;
  Point(double x = 0, double y = 0):x(x), y(y) {}
};

const double eps = 1e-4;
double dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}

typedef Point Segment;
const int N = 100000 + 10;
int l, d, n;
Point points[N];
vector<Segment> segs;

Segment getInterSeg(const Point& p) {
  double m = sqrt(d * d - p.y * p.y), x = p.x - m, y = p.x + m;
  if (dcmp(x) < 0) x = 0;
  if (dcmp(y - l) > 0) y = l;
  return Segment(x, y);
}

bool segcmp(const Segment& sl, const Segment& sr) {
  double yd = dcmp(sl.y - sr.y);
  return yd < 0 || (yd == 0 && dcmp(sl.x - sr.x) > 0);
}

void solve() {
  segs.clear();
  for (int i = 0; i < n; i++) segs.push_back(getInterSeg(points[i]));
  sort(segs.begin(), segs.end(), segcmp);
  int ans = 1;
  double p = segs[0].y;
  for (size_t i = 1; i < segs.size(); i++) {
    const Segment& prev = segs[i - 1], &cur = segs[i];
    if (dcmp(cur.x - p) > 0) {
      p = cur.y;
      ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (cin >> l >> d >> n) {
    for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;
    solve();
  }
  
  
  return 0;
}