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

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 50000 + 4, M = 500000 + 4;
int T;
int n, m;
int BIT[N];
int x, y;
void modify(int i, int v, int l) {
  while (i <= l) {
    BIT[i] = min(BIT[i], v);
    i += i & -i;
  }
}
int query(int i) {
  int ret = 0x3f3f3f3f;
  while (i > 0) {
    ret = min(BIT[i], ret);
    i -= i & -i;
  }
  
  return ret;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    memset(BIT, 0x3f, sizeof(BIT));
    BIT[n] = 0;
    
    for (int i = 1; i <= m; ++i) {
      scanf("%d%d", &x, &y);
      int v = query(n - x + 1) + 1;
      modify(n - y + 1, v, n);
    }
    
    printf("%d\n", query(1));
    if (T) printf("\n");
  }
  
  

  return 0;
  
  
}