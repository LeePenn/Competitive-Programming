// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 3;
int n, B[N], D[N], BIdx[N];
vector<int> ans[N];

void solve(int l, int r) {
  if (l == r) return;
  int i = l + 1, lasti = i, u = D[l]; 
  ans[u].push_back(D[i++]);
  while (i <= r) {
    int lastv = ans[u].back(), v = D[i];
    if (v > lastv && BIdx[lastv] + 1 == BIdx[v]) { // lastv 和 v 是u下的孩子
      solve(lasti, i - 1);
      ans[u].push_back(v);
      lasti = i;
    }
    i++;
  }
  solve(lasti, r);
} 

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &B[i]);
      BIdx[B[i]] = i;
      ans[i].clear();
    }
    
    for (int i = 1; i <= n; i++) scanf("%d", &D[i]);
    
    solve(1, n);
    for (int i = 1; i <= n; i++) {
      printf("%d:", i);
      for (auto v : ans[i]) printf(" %d", v);
      printf("\n");
    }
  }
  
  return 0;
}