// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 4;
int T, n, p[N], s[N], h[N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    for (int i = 0; i < n; i++) scanf("%d", &s[i]);
    
    int level = s[0];
    for (int i = 0; i < n; i++) {
      if (p[i] > level) level = p[i];
      if (s[i] < level) level = s[i];
      h[i] = level;
    }
    
    level = s[n - 1];
    int ans = 0;
    for (int i = n - 1; ~i; i--) {
      if (p[i] > level) level = p[i];
      if (s[i] < level) level = s[i];
      ans += min(h[i], level) - p[i];
    }
    
    printf("%d\n", ans);
  }
  
  
  return 0;
}