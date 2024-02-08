// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 9 + 2;
int n, a[N];
int maxd;

bool check() {
  for (int i = 1; i <= n; i++) if (a[i] != i) return 0;
  return 1;
}

int h() {
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] + 1 != a[i + 1]) cnt++;
  }
  cnt += a[n] != n;
  return cnt;
} 

bool dfs(int d) {
  if (3 * d + h() > 3 * maxd) return 0;
  if (check()) return 1;
  
  int b[N], c[N];
  memcpy(b, a, sizeof(a));
  
  for (int i = 1; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = j + 1; k <= n; k++) {
        int st = 1;
        while (st < i) { c[st] = a[st]; st++; }
        int st2 = j + 1;
        while (st2 <= k) { c[st] = a[st2]; st++; st2++; }
        st2 = i;
        while (st2 <= j) { c[st] = a[st2]; st++; st2++; }
        st2 = k + 1;
        while (st2 <= n) { c[st] = a[st2]; st++; st2++; }
        memcpy(a, c, sizeof(c));
        if (dfs(d + 1)) return 1;
        memcpy(a, b, sizeof(b));
      }
    }
  }
  
  return 0;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int kase = 1; scanf("%d", &n) == 1 && n; kase++) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    maxd = 0;
    while (!dfs(0)) maxd++;
    printf("Case %d: %d\n", kase, maxd);
  }
  
  
  return 0;
}