// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100000 + 3;
int a[N], n, f[N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    ll s = 0, t = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      s += a[i];
    }
    
    if (s % 2) {
      puts("No");
      continue;
    }
    
    puts("Yes");
    for (int i = n - 1; ~i; i--) {
      f[i] = 1;
      if ((t + a[i]) * 2 <= s) {
        f[i] = -1;
        t += a[i];
      }
    }
    
    for (int i = 0; i < n; i++) printf("%d%s", f[i], i == n - 1 ? "\n" : " ");
  }
  
  
  return 0;
}