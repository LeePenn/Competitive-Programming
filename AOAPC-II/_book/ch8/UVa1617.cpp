// Joker
#include <bits/stdc++.h>
using namespace std;


const int N = 100000 + 4;
struct Seg {
  int a, b;
  bool operator < (const Seg& rhs) const {
    return b < rhs.b || (b == rhs.b && a < rhs.a);
  }
} segs[N];
int T, n;

void solve() {
  int ans = 0, p = -1;
  for (int i = 0; i < n; i++) {
    const Seg& s = segs[i];
    if (s.b == p) continue;
    if (s.a > p) {
      ans++;
      p = s.b;
    } else p++;
  }
  printf("%d\n", ans - 1);
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      Seg& s = segs[i];
      scanf("%d %d", &s.a, &s.b);
    }
    sort(segs, segs + n);
    solve();
  }
  
  
  return 0;
}