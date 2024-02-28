// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int ans[N + 1][N + 1][N + 1];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
struct Cell {
  int x, y;
  Cell(int x = 0, int y = 0):x(x), y(y) {};
  bool operator < (const Cell& rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
};
typedef set<Cell> Polyomino;
set<Polyomino> poly[N + 1];

Polyomino normalize(const Polyomino& p) {
  int minX = p.begin()->x, minY = p.begin()->y;
  for (Polyomino::const_iterator c = p.begin(); c != p.end(); c++) {
    minX = min(minX, c->x);
    minY = min(minY, c->y);
  }
  Polyomino p2;
  for (Polyomino::const_iterator c = p.begin(); c != p.end(); c++) {
    p2.insert(Cell(c->x - minX, c->y - minY));
  }
  return p2;
}

// clockwise rotate
Polyomino rotate(const Polyomino& p) {
  Polyomino p2;
  for (Polyomino::const_iterator c = p.begin(); c != p.end(); c++) {
    p2.insert(Cell(c->y, -(c->x)));
  }
  return normalize(p2);
}

// clockwise flip
Polyomino flip(const Polyomino& p) {
  Polyomino p2;
  for (Polyomino::const_iterator c = p.begin(); c != p.end(); c++) {
    p2.insert(Cell(c->x, -(c->y)));
  }
  return normalize(p2);
}

void check_polyomino(const Polyomino& p, const Cell& newc) {
  Polyomino p2 = p;
  p2.insert(newc);
  p2 = normalize(p2);
  
  int n = p2.size();
  for (int i = 0; i < 4; i++) {
    if (poly[n].count(p2) != 0) return;
    p2 = rotate(p2);
  }
  
  p2 = flip(p2);
  for (int i = 0; i < 4; i++) {
    if (poly[n].count(p2) != 0) return;
    p2 = rotate(p2);
  }
  poly[n].insert(p2);
}

void generate() {
  Polyomino s;
  s.insert(Cell(0, 0));
  poly[1].insert(s);
  
  for (int n = 2; n <= N; n++) {
    for (set<Polyomino>::const_iterator p = poly[n - 1].begin(); p != poly[n - 1].end(); p++) {
      for (Polyomino::const_iterator c = (*p).begin(); c != (*p).end(); c++) {
        for (int dir = 0; dir < 4; dir++) {
          Cell newc(c->x + dx[dir], c->y + dy[dir]);
          if (p->count(newc) == 0) check_polyomino(*p, newc);
        }
      }
    }
  }
  
  for (int n = 1; n <= N; n++) {
    for (int w = 1; w <= N; w++) {
      for (int h = 1; h <= N; h++) {
        int cnt = 0;
        for (set<Polyomino>::const_iterator p = poly[n].begin(); p != poly[n].end(); p++) {
          int maxX = 0, maxY = 0;
          for (Polyomino::const_iterator c = (*p).begin(); c != (*p).end(); c++) {
            maxX = max(maxX, c->x);
            maxY = max(maxY, c->y);
          }
          if (min(maxX, maxY) < min(w, h) && max(maxX, maxY) < max(w, h)) cnt++;
        }
        ans[n][w][h] = cnt;
      }
    }
  }
}


int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  generate();
  
  int n, w, h;
  while (scanf("%d %d %d", &n, &w, &h) == 3) {
    printf("%d\n", ans[n][w][h]);
  }
  
  
  return 0;
}