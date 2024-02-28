// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 3;
int T, n, a[N], pre[N], nxt[N];
map<int, int> pos;

bool unique(int idx, int st, int ed) {
  return pre[idx] < st && nxt[idx] > ed;
}

bool check(int st, int ed) {
  if (st >= ed) return true;
  
  for (int i = 0; st + i <= ed - i; i++) {
    if (unique(st + i, st, ed)) { // check left
      return check(st, st + i - 1) && check(st + i + 1, ed);
    }
    
    if (st + i == ed - i) break;
    
    if (unique(ed - i, st, ed)) { // check right
      return check(ed - i + 1, ed) && check(st, ed - i - 1);
    }
  }
  
  return false;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    pos.clear();
    for (int i = 0; i < n; i++) {
      int cur = a[i];
      if (pos.count(cur)) pre[i] = pos[cur];
      else pre[i] = -1;
      pos[cur] = i;
    }
    
    pos.clear();
    for (int i = n - 1; i >= 0; i--) {
      int cur = a[i];
      if (pos.count(cur)) nxt[i] = pos[cur];
      else nxt[i] = n;
      pos[cur] = i;
    }
    
    if (check(0, n - 1)) printf("non-boring\n");
    else printf("boring\n");
  }
  
  return 0;
}