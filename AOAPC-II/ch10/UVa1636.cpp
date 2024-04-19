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
const int N = 100 + 4;
char gun[N];
int n;
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (scanf("%s", gun) == 1) {
    n = strlen(gun);
    int cnt1 = 0, cnt2 = 0, tot = 0;
    for (int i = 0; i < n; ++i) {
      int n1 = i, n2 = i + 1;
      if (n2 == n) n2 = 0;
      
      if (gun[n1] == '0' && gun[n2] == '0') cnt1++;
      else if (gun[n1] == '0' && gun[n2] == '1') cnt2++;
      
      if (gun[n1] == '0') tot++;
    }
    
    double p1 = 1.0 * cnt1 / (cnt1 + cnt2), p2 = 1.0 * tot / n;
    if (p1 > p2) printf("SHOOT");
    else if (p1 < p2) printf("ROTATE");
    else printf("EQUAL");
    printf("\n");
  }  
  
  
  return 0;
  
  
}