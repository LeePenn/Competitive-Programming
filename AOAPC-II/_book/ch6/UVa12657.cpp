// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, m;
int L[N], R[N];

void link(int x, int y) {
  R[x] = y, L[y] = x;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int kase = 1;
  while (scanf("%d %d", &n, &m) == 2) {
    
    for (int i = 1; i <= n; i++) {
      L[i] = i - 1;
      R[i] = (i + 1) % (n + 1);
    }
    R[0] = 1, L[0] = n;
    bool inv = 0;
    for (int i = 1; i <= m; i++) {
      int op;
      cin >> op;
      if (op == 4) { inv = !inv; continue; }
      int x, y;
      cin >> x >> y;
      if (op != 3 && inv) op = 3 - op;
      if (op == 1 && L[y] == x) continue;
      if (op == 2 && R[y] == x) continue;
      
      int LX = L[x], RX = R[x], LY = L[y], RY = R[y];
      if (op == 1) {
        link(LX, RX); link(LY, x); link(x, y);
      } else if (op == 2) {
        link(LX, RX); link(y, x); link(x, RY);
      } else {
        if (RX == y) { link(LX, y); link(y, x); link(x, RY); }
        else if (RY == x) { link(LY, x); link(x, y); link(y, RX); }
        else {
          link(LX, y); link(y, RX); link(LY, x); link(x, RY);
        }
      }
    }
    
    long long ans = 0;
    int b = 0;
    for (int i = 1; i <= n; i++) {
      b = R[b];
      if (i & 1) ans += b;
    }
    if (inv && !(n & 1)) ans = (long long) n * (n + 1) / 2 - ans;
    printf("Case %d: %lld\n", kase++, ans);
  }
  
  
  
  return 0;
}