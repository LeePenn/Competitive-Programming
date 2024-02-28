// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 2;
struct Point {
  int x, y;
  double rad;
  bool operator < (const Point& rhs) const {
    return rad < rhs.rad;
  }
};
int n;
Point p[N], cp[N];
int colors[N];

bool Left(const Point& a, const Point& b) {
  return b.y * a.x - a.y * b.x >= 0;
}

int solve() {
  if (n <= 2) return 2;
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    
    int k = 0;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        cp[k].x = p[j].x - p[i].x;
        cp[k].y = p[j].y - p[i].y;
        if (colors[j]) { cp[k].x = -cp[k].x, cp[k].y = -cp[k].y; }
        cp[k].rad = atan2(cp[k].y, cp[k].x);
        k++;
      }
    }
    sort(cp, cp + k);
    
    int L = 0, R = 0, cnt = 1;
    while (L < k) {
      if (L == R) { R = (R + 1) % k; cnt++; }
      while (L != R && Left(cp[L], cp[R])) { R = (R + 1) % k; cnt++; }
      ans = max(ans, cnt);
      cnt--;
      L++;
      
    }
  }
  return ans;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &p[i].x, &p[i].y, &colors[i]);
    }
    printf("%d\n", solve());
    
  }
  
  return 0;
}