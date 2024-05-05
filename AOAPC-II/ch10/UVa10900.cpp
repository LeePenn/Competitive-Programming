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
const int N = 30 + 4;
double dp[N];
int n;
double t;

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (scanf("%d%lf", &n, &t) == 2 && n) {
    dp[n] = 1 << n;
    for (int i = n - 1; i >= 0; --i) {
      double p0 = (double)(1 << i) / dp[i + 1]; 
      if (p0 < t) p0 = t;
      double p1 = (p0 - t) / (1 - t);
      dp[i] = (double)(1 << i) * p1 + (1 + p0) / 2 * dp[i + 1] * (1 - p1);
    }
    printf("%.3lf\n", dp[0]);
  }  

  return 0;
}