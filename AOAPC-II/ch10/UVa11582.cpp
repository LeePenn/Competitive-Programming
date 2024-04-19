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
const int N = 1000 + 3;
int T;
ULL a, b;
int n;
int f[N][N * 6];
int period[N];
int ksm(ULL a, ULL b, int n) {
  int r = 1;
  while (b) {
    if (b & 1) r = (r * a) % n;
    a = (a * a) % n;
    b >>= 1;
  }
  return r;
}
int solve() {
  if (a == 0 || n == 1) return 0;
  return f[n][ksm(a % period[n], b, period[n])];
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  for (int i = 2; i <= 1000; ++i) {
    f[i][0] = 0, f[i][1] = 1;
    for (int j = 2; ; ++j) {
      f[i][j] = (f[i][j - 2] + f[i][j - 1]) % i;
      if (f[i][j - 1] == 0 && f[i][j] == 1) {
        period[i] = j - 1;
        break;
      }
    }
  }
  
  cin >> T;
  while (T--) {
    cin >> a >> b >> n;
    // cout << a << b << n << endl;
    cout << solve() << endl;
  } 
    
  
  

  return 0;
  
  
}