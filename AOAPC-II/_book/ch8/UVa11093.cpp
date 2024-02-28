// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 2;
int T, n, p[N], q[N];

int go(int st) {
  int fuel = p[st] - q[st];
  for (int i = (st + 1) % n; i != st; i = (i + 1) % n) {
    
    if (fuel < 0) return i;
    fuel += p[i] - q[i];
  }
  if (fuel < 0) return -1;
  return st;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    
    int st = 0;
    int ans;
    for (;;) {
      int finish = go(st);
      if (finish < st) { ans = -1; break; }
      if (finish == st) { ans = st; break; }
      st = finish;
    }
    
    if (ans == -1) 
      printf("Case %d: Not possible\n", kase);
    else printf("Case %d: Possible from station %d\n", kase, ans + 1);
  }
  
  return 0;
}