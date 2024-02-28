// Joker
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

const double eps = 1e-7;
int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
int dcmp(double x, double y) {
  return dcmp(x - y);
}

struct Seg {
  int a, b;
};
struct segCmp {
  bool operator() (const Seg& lhs, const Seg& rhs) {
    return lhs.a < rhs.a;
  }
};
const int N = 100000 + 4;
int n;
Seg segs[N];

bool tryLen(const double m) {
  double l = 0;
  for (int i = 0; i < n; i++) {
    const Seg& s = segs[i];
    l = max(l, (double)s.a) + m;
    if (l > s.b) return false;
  }
  return true;
}

void output(double l) {
  double ip = floor(l + eps);
  if (dcmp(l, ip) == 0) {
    printf("%.0lf/1\n", ip);
    return;
  }
  
  int p = 1,
      q = 1;
  double ans = 1;
  for (int i = 1; i <= n; i++) {
    int cp = (int)floor(l * (double)i + 0.5);
    double x = (double)cp / i;
    if (fabs(x - l) < fabs(ans - l)) {
      p = cp, q = i;
      ans = x;
    }
  }
  int g = gcd(p, q);
  printf("%d/%d\n", p / g, q / g);
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) {
      Seg& s = segs[i];
      scanf("%d %d", &s.a, &s.b);
    }
    sort(segs, segs + n, segCmp());
    
    double l = 1, 
           r = (double)1000000.0 / n,
           m;
    for (int i = 0; i < 50; i++) {
      m = (l + r) / 2;
      if (tryLen(m)) l = m;
      else r = m;
    }
    output((l + r) / 2);
  }
  
  
  return 0;
}