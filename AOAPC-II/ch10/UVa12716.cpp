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
const int N = 30000000;
LL a, b, c;
int T;
LL n;
LL sum[N + 2], cnt[N + 2];
void init() {
  for (int c = 1; c <= N; ++c) {
    for (int a = 2 * c; a <= N; a += c) {
      b = a ^ c;
      if (a - b == c) {
        cnt[a]++;
      }
    }
  }
  for (int i = 1; i <= N; ++i) sum[i] = sum[i - 1] + cnt[i];
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  init();
  cin >> T;
  int kase = 1;
  while (T--) {
    cin >> n;
    cout << "Case " << kase << ": " << sum[n] << endl;
    kase++;
  }
  
  return 0;
  
  
}