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
const int N = 200000 + 4;
long double logF[(N << 1) + 1];
int n;
double p;
long double logC(int n, int m) {
  return logF[n] - logF[m] - logF[n - m];
}
double solve(int n, double p) {
  double ans = 0;
  for (int i = 0; i <= n; ++i) {
    long double c = logC(n * 2 - i, n);
    long double v1 = c + (n + 1) * log(p) + (n - i) * log(1 - p);
    long double v2 = c + (n + 1) * log(1 - p) + (n - i) * log(p);
    long double x = exp(v1) + exp(v2);
    ans += i * x;
  }
  return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  logF[0] = 0;
  for (int i = 1; i <= N; ++i) {
    logF[i] = logF[i - 1] + log(i);
  }
  
  int kase = 1;
  while (scanf("%d%lf", &n, &p) == 2) {
    printf("Case %d: %.6lf\n", kase, solve(n, p));
    kase++;
  }

  return 0;
}