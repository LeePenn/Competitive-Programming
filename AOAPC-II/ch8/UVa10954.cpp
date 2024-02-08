// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
priority_queue<ll, vector<ll>, greater<ll> > heap;

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 1; i <= n; i++) {
      ll x; scanf("%lld", &x);
      heap.push(x);
    }
    
    ll ans = 0;
    while (heap.size() > 1) {
      int a = heap.top(); heap.pop();
      int b = heap.top(); heap.pop();
      ans += a + b;
      heap.push(a + b);
    }

    heap.pop();
    printf("%lld\n", ans);
  }
  
  return 0;
}