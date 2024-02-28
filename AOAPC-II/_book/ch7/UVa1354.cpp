// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 6;
struct Tree {
  double l, r;
  Tree(double l = 0, double r = 0):l(l), r(r) {}
};
vector<Tree> tree[1 << N];
bool vis[1 << N];
double R;
int s;
double w[N], sum[1 << N];

void dfs(int subset) {
  if (vis[subset]) return;
  vis[subset] = 1;
  bool have_children = false;
  for (int left = (subset - 1) & subset; left; left = (left - 1) & subset) {
    have_children = true;
    int right = subset ^ left;
    dfs(left); dfs(right);
    double lLen = sum[right] / sum[subset];
    double rLen = sum[left] / sum[subset];
    for (int i = 0; i < tree[left].size(); i++) {
      for (int j = 0; j < tree[right].size(); j++) {
        Tree t;
        t.l = max(lLen + tree[left][i].l, tree[right][j].l - rLen);
        t.r = max(rLen + tree[right][j].r, tree[left][i].r - lLen);
        if (t.l + t.r < R) tree[subset].push_back(t);
      }
    }
  }
  if (!have_children) tree[subset].push_back(Tree());
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lf %d", &R, &s);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < s; i++) scanf("%lf", &w[i]);
    for (int i = 0; i < (1 << s); i++) {
      tree[i].clear();
      sum[i] = 0;
      for (int j = 0; j < s; j++) {
        if (i >> j & 1) sum[i] += w[j];
      }
    }
    //for (int i = 0; i < (1 << s); i++) cout << sum[i] << endl;
    int root = (1 << s) - 1;
    dfs(root);
    double ans = -1;
    for (int i = 0; i < tree[root].size(); i++) {
      ans = max(ans, tree[root][i].l + tree[root][i].r);
    }
    printf("%.10lf\n", ans);
    
  }
  
  
  return 0;
}