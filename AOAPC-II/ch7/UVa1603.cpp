// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 60 + 2;
int n, m;
vector<vector<int> > squares;
int cnt;
bool complete[N];
int maxd;

// cnt是从小到大的正方形，所以删除边是从小到大的
void prework() {
  scanf("%d", &n);
  squares.clear();
  cnt = 0;
  int d = 2 * n + 1;
  for (int len = 1; len <= n; len++) {
    for (int x = 1; x + len - 1 <= n; x++) { // the most left-upper len
      for (int t = 0; t + len <= n; t++) { // interval
        vector<int> s;
        for (int i = 0; i < len; i++) {
          s.push_back(x + t * d + i);
          s.push_back(x + t * d + i + len * d);
          s.push_back(x + t * d + n + i * d);
          s.push_back(x + t * d + n + i * d + len);
        }
        squares.push_back(s);
        cnt++;
      }
    }
  }
  
  memset(complete, 0, sizeof(complete));
  for (int i = 0; i < cnt; i++) complete[i] = 1;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x; scanf("%d", &x);
    for (int j = 0; j < cnt; j++) {
      for (const auto& v : squares[j]) {
        if (v == x) { complete[j] = 0; break; }
      }
    }
  }
}

bool check() {
  for (int i = 0; i < cnt; i++) {
    if (complete[i]) return 0;
  }
  return 1;
}

void Remove(int l) {
  for (int i = 0; i < cnt; i++) if (complete[i]) {
    for (const auto& v : squares[i]) {
      if (v == l) { complete[i] = 0; break; }
    }
  }
}

bool dfs(int d) {
  
  if (check()) return 1;
  if (d >= maxd) return 0;
  
  bool complete_bak[N];
  memcpy(complete_bak, complete, sizeof(complete));
  for (int i = 0; i < cnt; i++) if (complete[i]) {
    for (const auto& v : squares[i]) {
      Remove(v);
      if (dfs(d + 1)) return 1;
      memcpy(complete, complete_bak, sizeof(complete_bak));
    }
    return 0;
  }
  return 0;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int T;
  scanf("%d", &T);
  while (T--) {
    prework();
    maxd = 0;
    while (!dfs(0)) maxd++;
    printf("%d\n", maxd);
    
  }
  
  
  
  return 0;
}