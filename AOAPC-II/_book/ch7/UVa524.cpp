// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 16 + 4;
int n, a[N];
unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
bool used[N];

void prime_circle(int idx) {
  if (idx == n + 1) {
    if (!primes.count(a[n] + a[1])) return;
    for (int i = 1; i <= n; i++) {
      if (i == 1) printf("%d", a[i]);
      else printf(" %d", a[i]);
    }
    printf("\n");
    return;
  }
  
  for (int i = 2; i <= n; i++) {
    if (used[i]) continue;
    if (!primes.count(i + a[idx - 1])) continue;
    used[i] = 1;
    a[idx] = i;
    prime_circle(idx + 1);
    used[i] = 0;
    a[idx] = 0;
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int kase = 1; scanf("%d", &n) == 1 && n; kase++) {
    if (kase > 1) printf("\n");
    printf("Case %d:\n", kase);
    memset(used, 0, sizeof(used));
    used[1] = 1; a[1] = 1;
    prime_circle(2);
  }
  
  
  return 0;
}