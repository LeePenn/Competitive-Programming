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
int T, n;
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int V = 0, E = 0;
    for (int i = 0; i <= n - 2; ++i) {
      V += i * (n - 2 - i);
      E += i * (n - 2 - i) + 1;
    }
    V = V * n / 4 + n;
    E = E * n / 2 + n;
    printf("%d\n", E - V + 1);
  }

  return 0;
}