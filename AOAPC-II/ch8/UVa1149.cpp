// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 3;
int T, n, L, a[N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  bool first = true;
  while (T--) {
    if (first) first = false;
    else printf("\n");

    scanf("%d %d", &n, &L);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    
    int l = 1, r = n, ans = 0;
    while (l <= r) {
      if (l == r) { ans++; break; }
      
      if (a[l] + a[r] <= L) { l++, r--, ans++; }
      else { r--, ans++; }
    }
    
    printf("%d\n", ans);
  }
  
  
  return 0;
}