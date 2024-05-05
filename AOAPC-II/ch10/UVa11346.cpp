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
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  int T;
  scanf("%d", &T);
  while (T--) {
    double a, b, s, ans;
    scanf("%lf%lf%lf", &a, &b, &s);
    double m = a * b;
    if (fabs(s) < 1e-6) ans = 1;
    else if (s > m) ans = 0;
    else ans = (m - s - s * log(m / s)) / m;
    printf("%.6lf%%\n", ans * 100);
  }
  

  return 0;
}