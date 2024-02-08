// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 10000 + 3;
int T, n, a[N];


int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  vector<pair<int, int> > ans;
  auto swapSeg = [&ans](int st, int l) {
    for (int i = 0; i < l; i++) swap(a[st + i], a[st + l + i]);
    ans.push_back(make_pair(st, st + 2 * l - 1));
  };
  
  while (T--) {
    ans.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      int p = find(a + i, a + n + i, i) - a, l = p - i;
      if (a[i] == i) continue;
      
      if (2 * l > n - i + 1) {
        int sl = (n - i + 1) >> 1;
        swapSeg(n - 2 * sl + 1, sl);
      }
      p = find(a + i, a + n + i, i) - a;
      swapSeg(i, p - i);
    }
    printf("%lu\n", ans.size());
    for (auto p : ans) printf("%d %d\n", p.first, p.second);
  }
  
  
  return 0;
}