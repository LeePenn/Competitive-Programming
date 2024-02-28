// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 2;
int T, a, b, c, d, cap[3];
struct Node {
  int v[3], dist;
  bool operator < (const Node& rhs) const {
    return dist > rhs.dist;
  }  
};
bool vis[N][N];
int ans[N];

void update_ans(Node u) {
  for (int i = 0; i < 3; i++) {
    if (ans[u.v[i]] < 0) ans[u.v[i]] = u.dist;
  }
}

void solve() {
  memset(vis, 0, sizeof(vis));
  memset(ans, -1, sizeof(ans));
  cap[0] = a, cap[1] = b, cap[2] = c;
  vis[0][0] = 1;
  Node st;
  st.v[0] = st.v[1] = 0, st.v[2] = c, st.dist = 0;
  priority_queue<Node> heap;
  heap.push(st);
  while (heap.size()) {
    Node u = heap.top(); heap.pop();
    update_ans(u);
    if (ans[d] >= 0) break;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) if (i != j) {
        if (!u.v[i] || u.v[j] == cap[j]) continue;
        int amount = min(u.v[i], cap[j] - u.v[j]);
        Node u2 = u;
        memcpy(&u2, &u, sizeof(u));
        u2.v[i] -= amount, u2.v[j] += amount, u2.dist += amount;
        if (vis[u2.v[0]][u2.v[1]]) continue;
        vis[u2.v[0]][u2.v[1]] = 1;
        heap.push(u2);
      }
    }
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    solve();
    while (d >= 0) {
      if (ans[d] >= 0) {
        printf("%d %d\n", ans[d], d);
        break;
      }
      d--;
    }
  }
  
  
  return 0;
}