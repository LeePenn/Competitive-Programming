// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 3;
int n, a[N], b[N], pos[N];

int solve() {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int p = pos[i];
    if (p == i) continue;
    pos[b[i]] = p, pos[i] = i;
    swap(b[i], b[p]);
    ans++;
  }
  return ans;
}

void copy(int st, int step) {
  for (int i = 0; i < n; i++) {
    int cur = (b[i] = a[(st + step * i + n) % n]);
    pos[cur] = i;
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      a[i]--;
    }
    
    int ans = N;
    for (int i = 0; i < n; i++) {
      copy(i, 1);
      ans = min(ans, solve());
      copy(i, -1);
      ans = min(ans, solve());
    }
    printf("%d\n", ans);
  }
  
  
  return 0;
}