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
int n, D, p, L, v, kase;
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  kase = 1;
  while (scanf("%d%d", &n, &D) == 2 && D) {
    double ans = 0;
    while (n--) {
      scanf("%d%d%d", &p, &L, &v);
      D -= L;
      ans += 2.0 * L / v;
    }
    printf("Case %d: %.3lf\n\n", kase, ans + D);
    kase++;
  }
  

  return 0;
}