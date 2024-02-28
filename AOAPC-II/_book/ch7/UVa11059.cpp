// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 18 + 2;
int n, a[N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  
  int kase = 0;
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        ll ret = 1;
        for (int k = i; k <= j; k++) {
          ret = ret * a[k];
        }
        ans = max(ans, ret);
      }
    }
    printf("Case #%d: The maximum product is %lld.\n\n", ++kase, ans);
  }
  
  return 0;
}