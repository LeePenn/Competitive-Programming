// Joker
#include <bits/stdc++.h>
using namespace std;

const int M = 200000 + 2;
int n, m;
struct Gates {
  int a, b, o;
} gates[M];
int T;

int output(int k) {
  for (int i = 1; i <= m; i++) {
    int a = gates[i].a, b = gates[i].b;
    int va = a < 0 ? -a > k : gates[a].o;
    int vb = b < 0 ? -b > k : gates[b].o;
    gates[i].o = !(va && vb);
  }
  
  return gates[m].o;
}

int solve(int vn) {
  int l = 1, r = n;
  while (l < r) {
    int mid = l + ((r - l) >> 1);
    if (output(mid) == vn) r = mid;
    else l = mid + 1;
  }
  return l;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m); 
    for (int i = 1; i <= m; i++) 
      scanf("%d %d", &gates[i].a, &gates[i].b);
    
    int v0 = output(0);
    int vn = output(n);
    if (v0 == vn) {
      for (int i = 1; i <= n; i++) printf("0");
    } else {
      int x = solve(vn);
      for (int i = 1; i < x; i++) printf("0");
      printf("x");
      for (int i = x + 1; i <= n; i++) printf("1");
    }
    printf("\n");
  }
  
  return 0;
}