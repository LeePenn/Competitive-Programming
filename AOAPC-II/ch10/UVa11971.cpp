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
const int N = 50 + 2;
int T, n, k;
LL fac2[N];
pair<LL, LL> ans[N];
LL gcd(LL a, LL b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void init() {
  fac2[0] = 1;
  for (int i = 1; i <= 50; ++i) {
    fac2[i] = fac2[i - 1] * 2;
  }
  
  for (int i = 2; i <= 50; ++i) {
    LL t1 = fac2[i] - i - 1;
    LL g = gcd(t1, fac2[i]);
    ans[i] = make_pair(t1 / g, fac2[i] / g);
  }  
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  init();
  scanf("%d", &T);
  int kase = 1;
  while (T--) {
    scanf("%d%d", &n, &k);
    if (k == 1) printf("Case #%d: 0/1\n", kase);
    else {
      printf("Case #%d: %lld/%lld\n", kase, ans[k].first, ans[k].second);
    }
    
    kase++;
  }

  return 0;
}