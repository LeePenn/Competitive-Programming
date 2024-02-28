// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 4;
struct Candidate {
  int a, g;
  Candidate(int a, int g):a(a), g(g){};
  bool operator < (const Candidate& rhs) const {
    return a < rhs.a;
  }
};
set<Candidate> candidates;
int T, n, a[N], f[N], g[N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    candidates.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (n == 1) { printf("1\n"); continue; }
    
    g[1] = 1;
    for (int i = 2; i <= n; i++) {
      if (a[i] > a[i - 1]) g[i] = g[i - 1] + 1;
      else g[i] = 1;
    }
    
    f[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
      if (a[i] < a[i + 1]) f[i] = f[i + 1] + 1;
      else f[i] = 1;
    }
    
    int ans = 1;
    candidates.insert(Candidate(a[1], g[1]));
    for (int i = 2; i <= n; i++) {
      Candidate c(a[i], g[i]);
      set<Candidate>::iterator it = candidates.lower_bound(c);
      
      bool should_insert = true;
      if (it != candidates.begin()) {
        it--;
        Candidate l = *it;
        ans = max(ans, f[i] + l.g);
        if (l.g >= c.g) should_insert = false;
      }
      
      if (should_insert) {
        candidates.erase(c);
        candidates.insert(c);
        set<Candidate>::iterator it = candidates.find(c);
        it++;
        
        while (it != candidates.end() && c.a <= it->a && c.g >= it->g)
          candidates.erase(it++);
      }
    }
    
    printf("%d\n", ans);
  }
  
  return 0;
}