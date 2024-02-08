// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 2;
int n;
int X1[N], Y1[N], X2[N], Y2[N], ansX[N], ansY[N];

bool solve(int* a, int* b, int* c, int n) {
  
  fill(c + 1, c + n + 1, -1);
  for (int r = 1; r <= n; r++) {
    int rook = -1, minb = n + 1;
    for (int i = 1; i <= n; i++) {
      if (c[i] == -1 && r >= a[i] && b[i] < minb) { rook = i; minb = b[i]; }
    }
    if (rook == -1 || r > minb) return false;
    c[rook] = r;
  }
  return true;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 1; i <= n; i++) {
      scanf("%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
    }
    
    if (solve(X1, X2, ansX, n) && solve(Y1, Y2, ansY, n)) {
      for (int i = 1; i <= n; i++) printf("%d %d\n", ansX[i], ansY[i]);
    } else printf("IMPOSSIBLE\n");
  }
  
  return 0;
}