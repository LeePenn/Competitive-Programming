// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 4;
int T, n, m, ans[N], pre[N], rain[N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  cin >> T;
  while (T--) {
    cin >> n >> m;
    memset(ans, 0, sizeof(ans)); memset(pre, 0, sizeof(pre));
    set<int> drink;
    bool fill = false;
    for (int i = 0; i < m; i++) cin >> rain[i];
    for (int i = 0; i < m; i++) {
      if (rain[i] == 0) {
        drink.insert(i);
        continue;
      }
      
      ans[i] = -1;
      auto it = drink.lower_bound(pre[rain[i]]);
      if (it == drink.end()) {
        fill = true;
        break;
      }
      
      pre[rain[i]] = i;
      ans[*it] = rain[i];
      drink.erase(it);
    }
    
    if (fill) {
      cout << "NO" << endl;
      continue;
    } 
    
    cout << "YES" << endl;
    bool first = true;
    for (int i = 0; i < m; i++) {
      if (ans[i] == -1) continue;
      if (first) { cout << ans[i]; first = false; }
      else cout << ' ' << ans[i];
    }
    cout << endl;
  }
  
  return 0;
}