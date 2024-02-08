// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 4000 + 2;
unordered_map<int, int> vals;
int T;
int n, a[N], b[N], c[N], d[N];

void readSet(int* a, int* b, int* c, int* d, int n) {
  for (int i = 1; i <= n; i++) {
    int x, y, m, n; scanf("%d %d %d %d", &x, &y, &m, &n);
    *(a + i) = x; *(b + i) = y; *(c + i) = m; *(d + i) = n;
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    vals.clear();
    scanf("%d", &n);
    readSet(a, b, c, d, n);
    
    
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        vals[a[i] + b[j]]++;
      }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int v = -(c[i] + d[j]);
        if (vals.count(v)) {
          ans += vals[v];
        }
      }
    }
    
    printf("%d\n", ans);
    if (T) printf("\n");
  }
  
  return 0;
}