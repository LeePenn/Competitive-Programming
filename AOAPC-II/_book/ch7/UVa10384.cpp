// Joker
#include <bits/stdc++.h>
using namespace std;

const int R = 4, C = 6;
int sx, sy;
bool vis[R][C];
int maxd;
int rooms[R][C];
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
char dirs[] = "WNES";
const int REV[] = {2, 3, 0, 1};

bool getBit(int x, int b) {
  return (x >> b & 1) > 0;
}

bool inRange(int x, int l, int r) {
  if (l > r) return inRange(x, r, l);
  return x >= l && x < r;
}

bool can_out(int x, int y, vector<char>& ans) {
  if (x == 0 && !getBit(rooms[x][y], 1)) { ans.push_back(dirs[1]); return true; }
  if (x == R - 1 && !getBit(rooms[x][y], 3)) { ans.push_back(dirs[3]); return true; }
  if (y == 0 && !getBit(rooms[x][y], 0)) { ans.push_back(dirs[0]); return true; }
  if (y == C - 1 && !getBit(rooms[x][y], 2)) { ans.push_back(dirs[2]); return true; }
  return false;
}

void setBit(int& x, int b, bool flag) {
  if (flag) x |= (1 << b);
  else x &= ~(1 << b);
}

bool dfs(int x, int y, vector<char>& ans) {
  if (can_out(x, y, ans)) return true;
  if (ans.size() >= maxd) return false;
  
  int& p = rooms[x][y];
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if (!inRange(nx, 0, 4) || !inRange(ny, 0, 6) || vis[nx][ny]) continue;
    int& np = rooms[nx][ny];
    ans.push_back(dirs[dir]);
    vis[nx][ny] = 1;
    // this dir has no wall
    if (!getBit(p, dir)) {
      if (dfs(nx, ny, ans)) return true;
    } else if (!getBit(np, dir)) { // this dir has one wall
      setBit(p, dir, 0); setBit(np, dir, 1); setBit(np, REV[dir], 0);
      int nnx = nx + dx[dir], nny = ny + dy[dir];
      if (inRange(nnx, 0, 4) && inRange(nny, 0, 6)) setBit(rooms[nnx][nny], REV[dir], 1);
      
      if (dfs(nx, ny, ans)) return true;
      
      if (inRange(nnx, 0, 4) && inRange(nny, 0, 6)) setBit(rooms[nnx][nny], REV[dir], 0);
      setBit(p, dir, 1); setBit(np, dir, 0); setBit(np, REV[dir], 1);
    }
    
    ans.pop_back();
    vis[nx][ny] = 0;
  }
  return false;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d %d", &sy, &sx) == 2 && sx && sy) {
    sx--, sy--;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) scanf("%d", &rooms[i][j]);
    }
    
    vector<char> ans;
    for (maxd = 1;; maxd++) {
      memset(vis, 0, sizeof(vis));
      vis[sx][sy] = 1;
      ans.clear();
      if (dfs(sx, sy, ans)) break;
    }
    
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i];
    cout << endl;
  }
  
  
  return 0;
}