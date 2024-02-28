// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 16 + 4;
int c, r, n;
int s[3], t[3];
char maze[N][N];
int G[150][5], cnt, deg[150];
const int dx[] = {-1, 0, 1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};
int d[150][150][150];

int ID(int a, int b, int c) {
  return (a << 16) | (b << 8) | c;
}

bool conflict(int a, int a1, int b, int b1) {
  return a1 == b1 || (a1 == b && b1 == a);
}

// 巨坑，d数组不能开在调用函数里，因为数组太大，执行会报segmentation fault
int bfs() {
  memset(d, -1, sizeof(d));
  queue<int> q;
  q.push(ID(s[0], s[1], s[2]));
  d[s[0]][s[1]][s[2]] = 0;
  while (q.size()) {
    int u = q.front(); q.pop();
    int a = (u >> 16) & 0xff, b = (u >> 8) & 0xff, c = u & 0xff;
    if (a == t[0] && b == t[1] && c == t[2]) return d[a][b][c];
    for (int i = 0; i < deg[a]; i++) {
      int na = G[a][i];
      for (int j = 0; j < deg[b]; j++) {
        int nb = G[b][j];
        if (conflict(a, na, b, nb)) continue;
        for (int k = 0; k < deg[c]; k++) {
          int nc = G[c][k];
          if (conflict(a, na, c, nc) || conflict(b, nb, c, nc)) continue;
          if (d[na][nb][nc] != -1) continue;
          d[na][nb][nc] = d[a][b][c] + 1;
          q.push(ID(na, nb, nc));
        }
      }
    }
  }
  return -1;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d %d %d\n", &c, &r, &n) == 3 && c && r && n) {
    
    cnt = 0;
    int x[150], y[150], id[N][N];
    for (int i = 0; i < r; i++) {
      fgets(maze[i], N, stdin);
      for (int j = 0; j < c; j++) {
        if (maze[i][j] == '#') continue;
        x[cnt] = i, y[cnt] = j, id[i][j] = cnt;
        if (islower(maze[i][j])) s[maze[i][j] - 'a'] = cnt;
        if (isupper(maze[i][j])) t[maze[i][j] - 'A'] = cnt;
        cnt++;
      }
    }
    for (int i = 0; i < cnt; i++) {
      deg[i] = 0;
      int x1 = x[i], y1 = y[i];
      for (int j = 0; j < 5; j++) {
        int x2 = x1 + dx[j], y2 = y1 + dy[j];
        if (maze[x2][y2] != '#') {
          G[i][deg[i]] = id[x2][y2];
          deg[i]++;
        }
      }
    }
    if (n <= 2) { deg[cnt] = 1; G[cnt][0] = cnt; s[2] = t[2] = cnt; cnt++; }
    if (n <= 1) { deg[cnt] = 1; G[cnt][0] = cnt; s[1] = t[1] = cnt; cnt++; }
    //assert(cnt == 9);
    //for (int i = 0; i < 3; i++) cout << s[i] << ' ' << s[1] << ' ' << s[2] << endl;
    printf("%d\n", bfs());
  }
  
  
  return 0;
}