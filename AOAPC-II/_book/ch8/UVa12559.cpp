// Joker
#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

struct circle {
  int r, x, y;
  circle(int _r, int _x, int _y) : r(_r), x(_x), y(_y) {};
  bool operator < (const circle& rhs) const {
    if (r != rhs.r) return r < rhs.r;
    if (x != rhs.x) return x < rhs.x;
    return y < rhs.y;
  }
};

vector<string> lines;
int T, w, h;
bool inRange(int x, int left, int right) {
  if (left > right) return inRange(x, right, left);
  return left <= x && x <= right;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  vector<circle> ans;
  for (int t = 1; t <= T; t++) {
    ans.clear();
    scanf("%d %d", &w, &h);
    lines.resize(h);
    for (int j = 0; j < h; j++) {
      cin >> lines[j];
    }
    
    for (int r = 5; r < 51; r++) {
      for (int x = r; x < w - r + 1; x++) {
        for (int y = r; y < h - r + 1; y++) {
          int all = 0, per = 0;
          for (int i = 0; i < 100; i++) {
            double th = rand() / (RAND_MAX + 1.0) * 2 * pi;
            int cx = (int)(x + r * cos(th) + 0.5), cy = (int)(y + r * sin(th) + 0.5);
            if (inRange(cx, 0, w - 1) && inRange(cy, 0, h - 1) && lines[cy][cx] == '1') per++;
            all++;
            if (all > 10 && 2 * per < all) break;
          }
          
          if (per / (double)all > 0.8) ans.push_back(circle(r, x, y));
        }
      }
    }
    
    cout << "Case " << t << ": " << ans.size();
    for (int i = 0; i < ans.size(); i++) cout << " (" << ans[i].r << ',' << ans[i].x << ',' << ans[i].y << ")";
    cout << endl;
  }
  
  return 0;
}