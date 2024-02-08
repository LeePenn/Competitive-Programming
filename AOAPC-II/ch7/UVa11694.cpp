// Joker
#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x, y;
  Point(int x = 0, int y = 0):x(x), y(y) {};
  Point& operator = (const Point& p) {
    x = p.x; y = p.y;
    return *this;
  }
};
typedef Point Vector;
bool operator == (const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
bool operator<(const Point& p1, const Point& p2) {
  return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

const int N = 8 + 2;
const int CDX[] = {-1, -1, 0, 0}, CDY[] = {-1, 0, -1, 0}, CG[] = {1, -1, -1, 1};
int n, G[N][N], Deg[N][N], Done[N][N];
vector<Point> pts, PtConn[N][N];

bool inRangeP(int x, int l, int r) {
  if (l > r) return inRangeP(x, r, l);
  return x >= l && x <= r;
}

bool inRangeG(int x, int l, int r) {
  if (l > r) return inRangeG(x, r, l);
  return x >= l && x < r;
}

void connect(const Point& p1, const Point& p2) {
  if (!inRangeP(p1.x, 0, n) || !inRangeP(p1.y, 0, n)) return;
  if (!inRangeP(p2.x, 0, n) || !inRangeP(p2.y, 0, n)) return;
  
  PtConn[p1.x][p1.y].push_back(p2); PtConn[p2.x][p2.y].push_back(p1);
  int xc = min(p1.x, p2.x), yc = min(p1.y, p2.y), &g = G[xc][yc];
  g = (p1.x - p2.x) / (p1.y - p2.y);
}

void connect(const Point& p, int g) {
  if (g == 1) 
    connect({p.x, p.y}, {p.x + 1, p.y + 1});
  else if (g == -1) 
    connect({p.x + 1, p.y}, {p.x, p.y + 1});
}

bool connected(const Point& p1, const Point& p2) {
  if (p1 == p2) return true;
  
  set<Point> vis;
  queue<Point> Q;
  vis.insert(p1); Q.push(p1);
  while (!Q.empty()) {
    auto p = Q.front(); Q.pop();
    if (p == p2) return true;
    
    for (const auto& v : PtConn[p.x][p.y]) {
      if (!vis.count(v)) { Q.push(v); vis.insert(v); }
    }
  }
  return false;
}

bool dfs(int x, int y) {
  if (x >= n) {
    for (const auto& pt : pts) {
      if (PtConn[pt.x][pt.y].size() != Deg[pt.x][pt.y]) return false;
    }
    return true;
  }
  
  // 这个是已经填好，后续填线不会再影响到的格子，其实x y - 1也对，主要是用于剪枝
  if (inRangeP(x - 1, 0, n) && inRangeP(y - 1, 0, n) && Deg[x - 1][y - 1] != -1 && 
      PtConn[x - 1][y - 1].size() != Deg[x - 1][y - 1])
      return false;
      
  int nx = x + (y + 1) / n, ny = (y + 1) % n;
  if (G[x][y] != 0) return dfs(nx, ny);
  
  auto ok = [](int i, int j) {
    return Deg[i][j] == -1 || Deg[i][j] >= PtConn[i][j].size() + 1;
  };
  if (ok(x, y) && ok(x + 1, y + 1) && !connected({x, y}, {x + 1, y + 1})) {
    G[x][y] = 1, PtConn[x][y].push_back({x + 1, y + 1}), PtConn[x + 1][y + 1].push_back({x, y});
    if (dfs(nx, ny)) return true;
    G[x][y] = 0, PtConn[x][y].pop_back(), PtConn[x + 1][y + 1].pop_back();
  }
  
  if (ok(x + 1, y) && ok(x, y + 1) && !connected({x + 1, y}, {x, y + 1})) { /*  /  */
    G[x][y] = -1, PtConn[x + 1][y].push_back({x, y + 1}), PtConn[x][y + 1].push_back({x + 1, y});
    if (dfs(nx, ny)) return true;
    G[x][y] = 0, PtConn[x + 1][y].pop_back(), PtConn[x][y + 1].pop_back();
  }

  return false;
}

void printLayout() {
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      char c = ' ';
      if (G[x][y] == 1) c = '\\';
      if (G[x][y] == -1) c = '/';
      putchar(c);
    }
    puts("");
  }
}

void solve() {
  bool change = true;
  while (change) {
    change = false;
    for (const auto& pt : pts) {
      if (Done[pt.x][pt.y]) continue;
      
      int x = pt.x, y = pt.y, d = Deg[x][y], c = 0, free = 0;
      for (int cd = 0; cd < 4; cd++) {
        int cx = x + CDX[cd], cy = y + CDY[cd];
        if (!inRangeG(cx, 0, n) || !inRangeG(cy, 0, n)) continue;
        
        if (G[cx][cy] == CG[cd]) c++;
        if (!G[cx][cy]) free++;
      }
      // free 还没填
      if (c == d && free) {
        for (int cd = 0; cd < 4; cd++) {
          int cx = x + CDX[cd], cy = y + CDY[cd];
          if (!inRangeG(cx, 0, n) || !inRangeG(cy, 0, n)) continue;
          
          if (!G[cx][cy]) connect({cx, cy}, -CG[cd]);
        }
        Done[x][y] = 1, change = true;
      } else if (c + free == d) {
        for (int cd = 0; cd < 4; cd++) {
          int cx = x + CDX[cd], cy = y + CDY[cd];
          if (!inRangeG(cx, 0, n) || !inRangeG(cy, 0, n)) continue;
          
          if (!G[cx][cy]) connect({cx, cy}, CG[cd]);
        }
        Done[x][y] = 1, change = true;
      }
    }
  }
  dfs(0, 0); // dfs的是cell
}



int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  char buf[N];
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &n);
    pts.clear();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) PtConn[i][j].clear();
    }
    
    memset(Deg, -1, sizeof(Deg)); memset(G, 0, sizeof(G)); memset(Done, 0, sizeof(Done));
    for (int x = 0; x <= n; x++) {
      scanf("%s", buf);  
      for (int y = 0; y <= n; y++) {
        if (isdigit(buf[y])) {
          Deg[x][y] = buf[y] - '0';
          pts.emplace_back(x, y);
        }
      }
    }
    
    solve();
    printLayout();
  }
  
  
  return 0;
}