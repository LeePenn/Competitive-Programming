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
const int N = 50000 + 3;
int n; 
int phi[N];
void init() {
  memset(phi, 0, sizeof(0));
  phi[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (!phi[i]) {
      for (int j = i; j < N; j += i) {
        if (!phi[j]) phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}
LL solve() {
  LL ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = ans + phi[i] * 2;
    if (i == 1) ans--;
  }
  return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  init();
  while (cin >> n && n) {
    // for (int i = 1; i <= n; ++i) cout << i << ": " << phi[i] << endl;
    cout << solve() << endl;
  }
  
  
  return 0;
  
  
}