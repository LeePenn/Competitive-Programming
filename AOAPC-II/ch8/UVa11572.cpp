// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 2;
unordered_set<int> seen;
int T, n, a[N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 1, r = 1, ans = 0;
    seen.clear();
    while (r <= n) {
      int cur = a[r];
      if (seen.count(cur)) {
        while (l < r && seen.count(cur)) {
          seen.erase(a[l++]);
        }
      }
      
      seen.insert(cur);
      ans = max(ans, r - l + 1);
      r++;
    }
    printf("%d\n", ans);
  }
  
  return 0;
}