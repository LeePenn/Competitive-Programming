// Joker
#include <bits/stdc++.h>
using namespace std;

const int R = 15 + 2, N = 30 + 2;
int r, c;
char maze[R][R];
int v_cnt;
int v2id[N], id2v[N];
vector<int> G[N];
bool vis[N], vis2[N];
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

inline int encode(int i, int j) {
  return i * c + j;
}

bool inRange(int x, int l, int r) {
  if (l > r) return inRange(x, r, l);
  return x >= l && x < r;
}

void addEdge(int u, int v) {
  G[u].push_back(v); 
}

bool vector_cmp(const vector<int>& s1, const vector<int>& s2) {
  if (s1.size() > s2.size()) return true;
  if (s1.size() < s2.size()) return false;
  for (int i = 0; i < (int)s1.size(); i++) {
    if (s1[i] != s2[i]) return s1[i] > s2[i];
  }
  return false;
}

void bfs(int u, vector<int>& rs, vector<int>& ans) {
  memset(vis2, 0, sizeof(vis2));
  queue<int> q;
  q.push(u);
  vis2[u] = 1;
  while (q.size()) {
    int t = q.front(); q.pop();
    int id = v2id[t], num = maze[id / c][id % c] - '0';
    rs.push_back(num);
    
    for (const auto& v : G[t]) {
      if (vis[v] || vis2[v]) continue;
      vis2[v] = 1;
      q.push(v);
    }
  }
}

bool lessThan(const vector<int>& cur, vector<int>& rs, const vector<int>& ans) {
  int i = 0, a, b;
  for (i = 0; i < cur.size(); i++) {
    if (cur[i] < ans[i]) return true;
    if (cur[i] > ans[i]) return false;
  }
  sort(rs.begin(), rs.end(), greater<int>());
  for (; i < ans.size(); i++) {
    if (rs[i - cur.size()] < ans[i]) return true;
    if (rs[i - cur.size()] > ans[i]) return false;
  }
  return false;
}

void dfs(int u, vector<int>& cur, vector<int>& ans) {
  vector<int> rs;
  bfs(u, rs, ans);
  if (cur.size() + rs.size() < ans.size()) return;
  if (cur.size() + rs.size() == ans.size() && lessThan(cur, rs, ans)) return;
  
  vis[u] = 1;
  int id = v2id[u];
  int num = maze[id / c][id % c] - '0';
  cur.push_back(num);
  
  bool has_edge = false;
  for (const auto& v : G[u]) {
    if (vis[v]) continue;
    has_edge = true;
    dfs(v, cur, ans);
  }
  if (!has_edge) {
    if (vector_cmp(cur, ans)) {
      ans = cur;
    }
  }
  vis[u] = 0;
  cur.pop_back();
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d %d", &r, &c) == 2 && r && c) {
    v_cnt = 0;
    memset(v2id, -1, sizeof(v2id));
    memset(id2v, -1, sizeof(id2v));
    for (int i = 0; i < N; i++) G[i].clear();
    
    for (int i = 0; i < r; i++) {
      scanf("%s", maze[i]);
      for (int j = 0; j < c; j++) {
        if (maze[i][j] != '#') {
          v2id[++v_cnt] = encode(i, j);
          id2v[encode(i, j)] = v_cnt;
        }
      }
    }
    
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (maze[i][j] == '#') continue;
        for (int dir = 0; dir < 4; dir++) {
          int nx = i + dx[dir], ny = j + dy[dir];
          if (inRange(nx, 0, r) && inRange(ny, 0, c) && isdigit(maze[nx][ny])) {
            int u = id2v[encode(i, j)], v = id2v[encode(nx, ny)];
            //cout << u << ' ' << v << endl;
            addEdge(u, v);
          }
        }
      }
    }
    
    vector<int> ans;
    for (int u = 1; u <= v_cnt; u++) {
      vector<int> cur;
      memset(vis, 0, sizeof(vis));
      dfs(u, cur, ans);
    }
    for (const auto& v : ans) cout << v;
    cout << endl;
  }
  
  
  
  return 0;
}