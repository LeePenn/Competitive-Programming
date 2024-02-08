// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int K = 30;
int T, k, a, b;
ll c[K + 1];

ll f(int k, int x) {
  if (x == 0) return 0;
  if (k == 0) return 1;
  
  ll p = 1 << (k - 1);
  if (x <= p) return f(k - 1, x) * 2;
  
  return f(k - 1, x - p) + c[k - 1] * 2;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  c[0] = 1;
  for (int i = 1; i <= 30; i++) c[i] = 3 * c[i - 1];
  
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    
    scanf("%d %d %d", &k, &a, &b);
    printf("Case %d: %lld\n", kase, f(k, b) - f(k, a - 1));
  }
  
  return 0;
}