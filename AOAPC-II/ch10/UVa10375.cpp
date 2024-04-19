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
const int N = 10000 + 4;
int p, q, r, s;
bool vis[N];
int prime[N], tot;
int ans[N];
void Init() {
  tot = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 2; i < N; ++i) {
    if (vis[i]) continue;
    prime[++tot] = i;
    for (int j = i * i; j < N; j += i) {
      vis[j] = 1;
    }
  }
}
void add_integer(int n, int d) {
  for (int i = 1; i <= tot; ++i) {
    if (prime[i] > n) break;
    
    if (n % prime[i] == 0) {
      while (n % prime[i] == 0) {
        n /= prime[i];
        ans[i] += d;
      }
    }
  }
}
void add_factorial(int m, int d) {
  for (int i = 1; i <= m; ++i) {
    add_integer(i, d);
  }
}
double solve() {
  memset(ans, 0, sizeof(ans));
  
  add_factorial(p, 1);
  add_factorial(q, -1);
  add_factorial(p - q, -1);
  add_factorial(s, 1);
  add_factorial(r - s, 1);
  add_factorial(r, -1);
  
  double ret = 1.0;
  for (int i = 1; i <= tot; ++i) {
    if (ans[i] != 0) {
      ret *= pow(prime[i], ans[i]);
    }
  }
  
  return ret;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  Init();
  
  // for (int i = 2; i < 100; ++i) {
  //   if (!vis[i]) printf("%d ", i);
  // }
  
  while (scanf("%d%d%d%d", &p, &q, &r, &s) == 4) {
    printf("%.5f\n", solve());
  }
  

  return 0;
  
  
}