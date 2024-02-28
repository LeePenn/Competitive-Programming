// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 3;
int T, s, n, x[N * 3];
int cnt[N], ok[N << 1];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &s, &n);
    fill(x, x + n + 2 * s, -1);
    for (int i = 0; i < n; i++) cin >> x[i + s];
    
    fill(cnt + 1, cnt + s + 1, 0);
    fill(ok, ok + n + s + 1, 0);
    
    int tot = 0;
    for (int i = 0; i <= n + s; i++) {
      if (tot == s) ok[i] = 1;
      if (i < s && tot == i) ok[i] = 1;
      if (i > n && tot == n + s - i) ok[i] = 1;
      if (i < s && i > n && tot == n) ok[i] = 1;
      
      if (i == n + s) break;
      if (x[i] != -1 && --cnt[x[i]] == 0) tot--;
      if (x[i + s] != -1 && cnt[x[i + s]]++ == 0) tot++;
    }
    
    int ans = 0;
    for (int i = 0; i < s; i++) {
      bool valid = true;
      for (int j = i; j < n + s + 1; j += s) {
        if (!ok[j]) valid = false;
      }
      if (valid) ans++;
    }
    
    //if (ans == n + 1) { cout << s << 'a' << (n + 1) << endl; ans = s; }
    cout << ans << endl;
  }
  
  return 0;
}