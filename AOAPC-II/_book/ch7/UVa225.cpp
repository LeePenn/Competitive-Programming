// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 512;
int n, k;
struct Point {
  int x, y;
  Point(int x = 0, int y = 0):x(x), y(y) {};
};

Point operator * (const Point& p, int t) { return Point(p.x * t, p.y * t); }
Point operator + (const Point& p1, const Point& p2) { return Point(p1.x + p2.x, p1.y + p2.y); }

char dirs[] = "ensw";
const Point dirVs[4] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
unordered_map<char, int> dirsID = {{'e', 0}, {'n', 1}, {'s', 2}, {'w', 3}};
vector<Point> blocks;
bool vis[N][N];
int cnt;

bool check(int d, const Point& st) {
  int dist = abs(st.x) + abs(st.y);
  if ((n - d) * (d + 1 + n) / 2 < dist) return false;
  return true;
}

bool inRange(int m, int s, int e) {
  if (s > e) return inRange(m, e, s);
  return m >= s && m <= e;
}

bool isBlocked(const Point& st, const Point& ed) {
  for (const auto& blk : blocks) {
    if (st.x == ed.x) {
      if (st.x == blk.x && inRange(blk.y, st.y, ed.y)) return true;
    } else if (st.y == ed.y) {
      if (st.y == blk.y && inRange(blk.x, st.x, ed.x)) return true;
    }
  }
  return false;
}

void dfs(int d, const Point& st, int dir, vector<char>& path) {
  if (d == n) {
    if (st.x == 0 && st.y == 0) {
      for (int i = 0; i < path.size(); i++) printf("%c", path[i]);
      printf("\n");
      cnt++;
    }
    return;
  }
  
  if (!check(d, st)) return;
  
  vis[st.x + 256][st.y + 256] = 1;
  for (int i = 0; i < 4; i++) {
    if (dir == i) continue;
    if (dir + i == 3) continue;
    Point nxt = st + dirVs[i] * (d + 1);
    if (isBlocked(st, nxt)) continue;
    if (vis[nxt.x + 256][nxt.y + 256]) continue;
    path.push_back(dirs[i]);
    dfs(d + 1, nxt, i, path);
    path.pop_back();
  }
  vis[st.x + 256][st.y + 256] = 0;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    blocks.clear();
    for (int i = 0; i < k; i++) {
      Point b;
      scanf("%d %d", &b.x, &b.y);
      blocks.push_back(b);
    }
    
    cnt = 0;
    for (int i = 0; i < 4; i++) {
      memset(vis, 0, sizeof(vis));
      vector<char> path;
      path.push_back(dirs[i]);
      Point start(dirVs[i].x, dirVs[i].y);
      dfs(1, start, i, path);
    }
    printf("Found %d golygon(s).\n\n", cnt);
  }
  
  
  
  return 0;
}