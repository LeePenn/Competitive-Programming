// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T;
ll n, s1, v1, s2, v2;


int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T); 
  for (int kase = 1; kase <= T; kase++) {
    scanf("%lld %lld %lld %lld %lld", &n, &s1, &v1, &s2, &v2);
    if (s1 > s2) { swap(s1, s2); swap(v1, v2); }
    int limit = 1 << 16;
    ll ans = 0;
    if (n / s2 <= limit) {
      for (ll i = 0; i * s2 <= n; i++) {
        ll tot = v2 * i + v1 * ((n - s2 * i) / s1);
        ans = max(ans, tot);
      }
    } else {
      // s2 * v1 > s1 * v2
      for (ll i = 0; i < s1; i++) {
        ll tot = v2 * i + v1 * ((n - s2 * i) / s1);
        ans = max(ans, tot);
      }
      // s2 * v1 < s1 * v2
      for (ll i = 0; i < s2; i++) {
        ll tot = v1 * i + v2 * ((n - s1 * i) / s2);
        ans = max(ans, tot);
      }
    }
    printf("Case #%d: %lld\n", kase, ans);
  } 
  
  
  return 0;
}