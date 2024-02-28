// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 50 + 3;
const int C = 1000 + 3;
int n, X0[N], Y0[N], Z0[N], X1[N], Y1[N], Z1[N];
int xs[N << 1], ys[N << 1], zs[N << 1], nx, ny, nz;
int blocks[N << 1][N << 1][N << 1];
const int dx[] = {-1, 0, 1, 0, 0, 0};
const int dy[] = {0, 1, 0, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

struct Cell {
  int x, y, z;
  Cell(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
  bool isValid() {
    return x >= 0 && x < nx - 1 && y >= 0 && y < ny - 1 && z >= 0 && z < nz - 1;
  }
  bool isBlock() {
    return blocks[x][y][z] == 1;
  }
  int getVolume() {
    return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
  }
  void setVis() {
    blocks[x][y][z] = 2;
  }
  bool getVis() {
    return blocks[x][y][z] == 2;
  }
  int getArea(int dir) {
    if (dx[dir] != 0) return (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
    else if (dy[dir] != 0) return (xs[x + 1] - xs[x]) * (zs[z + 1] - zs[z]);
    else return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]);
  }
};

void discretize(int* x, int& nx) {
  sort(x, x + nx);
  nx = unique(x, x + nx) - x;
}

int getID(int* x, int nx, int y) {
  return lower_bound(x, x + nx, y) - x;
}

void floodfill(int& v, int& s) {
  v = s = 0;
  Cell c(getID(xs, nx, 0), getID(ys, ny, 0), getID(zs, nz, 0));
  c.setVis();
  queue<Cell> q;
  q.push(c);
  while (q.size()) {
    Cell cur = q.front(); q.pop();
    v += cur.getVolume();
    for (int i = 0; i < 6; i++) {
      Cell nc(cur.x + dx[i], cur.y + dy[i], cur.z + dz[i]);
      if (!nc.isValid()) continue;
      if (nc.isBlock()) s += nc.getArea(i);
      else if (!nc.getVis()) {
        q.push(nc);
        nc.setVis();
      }
    }
  }
  v = C * C * C - v;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int T;
  scanf("%d", &T);  
  while (T--) {
    scanf("%d", &n);
    nx = ny = nz = 2;
    xs[0] = ys[0] = zs[0] = 0;
    xs[1] = ys[1] = zs[1] = C;
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d %d %d", &X0[i], &Y0[i], &Z0[i], &X1[i], &Y1[i], &Z1[i]);
      X1[i] += X0[i]; Y1[i] += Y0[i]; Z1[i] += Z0[i];
      xs[nx++] = X0[i]; xs[nx++] = X1[i];
      ys[ny++] = Y0[i]; ys[ny++] = Y1[i];
      zs[nz++] = Z0[i]; zs[nz++] = Z1[i];
    }
    
    discretize(xs, nx);
    discretize(ys, ny);
    discretize(zs, nz);
    
    memset(blocks, 0, sizeof(blocks));
    for (int i = 0; i < n; i++) {
      int IDX0 = getID(xs, nx, X0[i]), IDX1 = getID(xs, nx, X1[i]);
      int IDY0 = getID(ys, ny, Y0[i]), IDY1 = getID(ys, ny, Y1[i]);
      int IDZ0 = getID(zs, nz, Z0[i]), IDZ1 = getID(zs, nz, Z1[i]);
      for (int x = IDX0; x < IDX1; x++) {
        for (int y = IDY0; y < IDY1; y++) {
          for (int z = IDZ0; z < IDZ1; z++) {
            blocks[x][y][z] = 1;
          }
        }
      }
    }
    
    int v, s;
    floodfill(v, s);
    printf("%d %d\n", s, v);
  }
  
  
  return 0;
}