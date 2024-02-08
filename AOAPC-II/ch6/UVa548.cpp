// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 10004;
int in_order[N], post_order[N], lch[N], rch[N];
int n, best, best_sum;

bool read_list(int* a) {
  string s;
  getline(cin, s);
  stringstream ss(s);
  n = 0;
  int x;
  while (ss >> x) {
    a[n++] = x;
  }
  return n > 0;
}

int build(int l1, int r1, int l2, int r2) {
  if (l1 > r1) return 0;
  int root = post_order[r2];
  int p = l1;
  while (in_order[p] != root) p++;
  int cnt = p - l1;
  lch[root] = build(l1, p - 1, l2, l2 + cnt - 1);
  rch[root] = build(p + 1, r1, l2 + cnt, r2 - 1);
  return root;
}

void dfs(int u, int sum) {
  if (!lch[u] && !rch[u]) {
    if (sum + u < best_sum || (sum + u == best_sum && u < best)) {
      best = u;
      best_sum = sum + u;
    }
    return;
  }
  if (lch[u]) dfs(lch[u], sum + u);
  if (rch[u]) dfs(rch[u], sum + u);
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (read_list(in_order)) {
    read_list(post_order);
    int root = build(0, n - 1, 0, n - 1);
    best_sum = 0x3f3f3f3f;
    dfs(root, 0);
    cout << best << endl;
  }
  
  
  
  return 0;
}