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
const int N = 20 + 2;
int n, r;
double p[N], prr[N], pr;
int kase;
int getBit(int s) {
  int cnt = 0;
  while (s) {
    s -= s & (-s);
    cnt++;
  }
  return cnt;
}
double getProb(int s) {
  double ret = 1.0;
  for (int i = 0; i < n; ++i) {
    if (s & (1 << i)) ret = ret * p[i + 1];
    else ret = ret * (1.0 - p[i + 1]);
  }
  return ret;
}
void solve() {
  pr = 0.0;
  for (int i = 1; i <= n; ++i) prr[i] = 0.0;
  
  for (int s = 0; s < (1 << n); ++s) {
    if (getBit(s) == r) {
      double t = getProb(s);
      pr += t;
      for (int i = 0; i < n; ++i) {
        if (s & (1 << i)) prr[i + 1] += t;
      }
    }
  }
  
  printf("Case %d:\n", kase);
  for (int i = 1; i <= n; ++i) {
    printf("%.6lf\n", prr[i] / pr);
  }
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  kase = 1;
  
  while (scanf("%d%d", &n, &r) == 2 && n) {
    for (int i = 1; i <= n; ++i) scanf("%lf", &p[i]);
    solve();
    kase++;
  }
  
  
  return 0;
  
  
}