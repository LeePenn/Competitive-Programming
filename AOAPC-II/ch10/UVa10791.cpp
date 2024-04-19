#include <bitset>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <queue>
#include <set>

typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
const int N = 100000;
LL n;
bool vis[N];
LL prime[N], tot;
LL p[N], p_cnt[N], cnt;
LL sum;
void init() {
  memset(vis, 0, sizeof(vis));
  memset(prime, 0, sizeof(prime));
  tot = 0;
  
  for (LL i = 2; i < N; ++i) {
    if (vis[i]) continue;
    
    prime[++tot] = i;
    
    for (LL j = i * i; j < N; j += i) {
      vis[j] = 1;
    }
  }
}
void pre_init() {
  cnt = 0;
  LL nn = n;
  for (int i = 1; i <= tot; ++i) {
    if (nn % prime[i] == 0) {
      int t = 0;
      p[++cnt] = prime[i];
      while (nn % prime[i] == 0) {
        t++;
        nn /= prime[i];
      }
      p_cnt[cnt] = t;
    }
  }
  if (nn > 1) {
    p[++cnt] = nn;
    p_cnt[cnt] = 1;
  }
}
LL solve() {
  if (cnt == 1 || n == 1) return n + 1;
  
  sum = 0;
  for (int i = 1; i <= cnt; ++i) {
    LL t = 1;
    for (int j = 1; j <= p_cnt[i]; ++j) {
      t = t * p[i];
    }
    sum += t;
  }
  
  return sum;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  init();
  
  int kase = 1;
  while (cin >> n && n) {
    pre_init();
    cout << "Case " << kase << ": " << solve() << endl;
    kase++;
  }
  

  return 0;
  
  
}