// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 104;
struct Point {
  int x, y;
  bool operator < (const Point& rhs) const {
    return x < rhs.x;
  }
};

Point Ps[N];
int T, n, w, h;
set<int> Ys;

int solve(Point& ans) {
  sort(Ps, Ps + n);
  vector<int> Y(Ys.begin(), Ys.end());
  
  int len = 0;
  for (int a = 0; a < Y.size(); a++) {
    for (int b = a + 1; b < Y.size(); b++) {
      int minY = Y[a], maxY = Y[b];
      int maxLen = maxY - minY;
      if (maxLen <= len) continue;
      
      int left = 0;
      for (int i = 0; i < n; i++) {
        const Point& p = Ps[i];
        if (p.y <= minY || p.y >= maxY) continue;
        int curLen = min(maxLen, p.x - left);
        if (curLen > len) {
          ans.x = left;
          ans.y = minY;
          len = curLen;
        }
        
        left = p.x;
      }
      
      if (len < min(maxLen, w - left)) {
        ans.x = left;
        ans.y = minY;
        len = min(maxLen, w - left);
      }
    }
  }
  
  return len;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  Point ans;
  for (int t = 0; t < T; t++) {
    if (t) puts("");
    
    scanf("%d %d %d", &n, &w, &h);
    Ys.clear(); Ys.insert(0); Ys.insert(h);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &Ps[i].x, &Ps[i].y);
      Ys.insert(Ps[i].y);
    }
    int len = solve(ans);
    printf("%d %d %d\n", ans.x, ans.y, len);
  }
  
  return 0;
}