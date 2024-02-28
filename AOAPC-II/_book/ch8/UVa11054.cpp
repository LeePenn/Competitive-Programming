// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) && n) {
    ll ans = 0, sum = 0, x;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &x);
      sum += x;
      ans += abs(sum);
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}