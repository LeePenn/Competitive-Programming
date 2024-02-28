// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 2;
struct Rec {
  int c, h;
  Rec(int c = 0, int h = 0):c(c), h(h) {}
};
int T, n, m;
Rec recs[N];
int h[N], ans[N << 1];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    memset(h, 0, sizeof(h));
    memset(ans, 0, sizeof(ans));
    
    char line[N];
    for (int i = 0; i < n; i++) {
      scanf("%s", line);
      int top = -1;
      for (int j = 0; j < m; j++) {
        if (line[j] == '#') {
          h[j] = 0;
          top = -1;
        } else {
          h[j]++;
          Rec r(j, h[j]);
          if (top < 0) recs[++top] = r;
          else {
            while (top >= 0 && r.h <= recs[top].h) r.c = recs[top--].c;
            if (top < 0 || (r.h - r.c > recs[top].h - recs[top].c)) recs[++top] = r;
          }
          ans[j - recs[top].c + 1 + recs[top].h]++;
        }
      }
    }
    
    for (int i = 1; i <= n + m; i++) {
      if (ans[i]) printf("%d x %d\n", ans[i], i * 2);
    }
  }
  
  
  return 0;
}