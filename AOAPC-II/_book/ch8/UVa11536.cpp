// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 3;
int T, n, m, k, a[N];

bool in_range(int x) { return x >= 1 && x <= k; }

void safe_insert(int i, unordered_map<int,int>& s) {
    if(in_range(i))  s[i] = s[i] + 1; 
}

void safe_del(int i, unordered_map<int,int>& s) {
    if(!s.count(i)) return;
    s[i] = s[i] - 1; 
    if(s[i] < 1) s.erase(i);
}

int solve() {
  int ans = 0,
      L = 0,
      R = 0;
  for (int i = 0; i < n; i++) {
    if (i < 3) a[i] = i + 1;
    else a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
  }
  
  unordered_map<int, int> s;
  safe_insert(a[R], s);
  while (L < n && R < n) {
    while (s.size() < k) {
      safe_insert(a[++R], s);
      if (R >= n) break;
    }
    
    if (s.size() == k) {
      while (!s.count(a[L]) || s[a[L]] > 1) safe_del(a[L++], s);
      int len = R - L + 1;
      if (ans) ans = min(ans, len);
      else ans = len;
    }
    
    safe_del(a[L], s);
    L++;
    
  }
  return ans;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    printf("Case %d: ", kase);
    scanf("%d %d %d", &n, &m, &k);
    int ans = solve();
    if (ans) printf("%d\n", ans);
    else printf("sequence nai\n");
  }
  
  
  return 0;
}