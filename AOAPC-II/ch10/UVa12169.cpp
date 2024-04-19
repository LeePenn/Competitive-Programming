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
const int N = 100 + 3, M = 10000;
int T;
int x[N << 1];
void solve() {
  for (int a = 0; a <= M; ++a) {
    for (int b = 0; b <= M; ++b) {
      bool ok = true;
      for (int i = 2; i <= 2 * T; i += 2) {
        x[i] = (a * x[i - 1] + b) % 10001;
        if (i + 1 <= 2 * T && x[i + 1] != (a * x[i] + b) % 10001) {
          ok = false;
          break;
        }
      }
      if (ok) return;
    }
  }
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  cin >> T;
  for (int i = 1; i <= 2 * T; i += 2) cin >> x[i];
  solve();
  for (int i = 2; i <= 2 * T; i += 2) cout << x[i] << endl;
  
  

  return 0;
  
  
}