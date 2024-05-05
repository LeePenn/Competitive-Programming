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
int pow10[10], cnt[10];
int a, b;
void init() {
  pow10[0] = 1;
  for (int i = 1; i <= 8; ++i) {
    pow10[i] = pow10[i - 1] * 10;
    cnt[i] = pow10[i - 1] * i;
  }
}
int f(int d, int n) {
  string s = to_string(n);
  // printf("%s\n", s.c_str());
  int len = s.length();
  int ans = 0;
  
  for (int i = 1; i < len; ++i) {
    if (i == 1) ans++;
    else {
      ans += 9 * cnt[i - 1];
      if (d > 0) ans += pow10[i - 1];
    }
  }
  
  int pre[10];
  for (int i = 0; i < len; ++i) {
    pre[i] = (s[i] - '0' == d ? 1 : 0);
    if (i > 0) pre[i] += pre[i - 1];
  }
  
  for (int i = 0; i < len; ++i) {
    int maxd = s[i] - '0' - 1;
    int mind = 0;
    if (i == 0 && len > 1) mind = 1;
    for (int digit = mind; digit <= maxd; ++digit) {
      ans += cnt[len - i - 1];
      if (i > 0) ans += pre[i - 1] * pow10[len - i - 1];
      if (digit == d) ans += pow10[len - i - 1];
    }
  }
  
  return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  init();
  
  while (scanf("%d%d", &a, &b) == 2 && a && b) {
    if (a > b) swap(a, b);
    for (int d = 0; d < 10; ++d) {
      if (d) printf(" ");
      printf("%d", f(d, b + 1) - f(d, a));
    }
    printf("\n");
  }

  return 0;
}