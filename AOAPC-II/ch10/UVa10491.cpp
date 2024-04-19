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
int a, b, c;
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (cin >> a >> b >> c) {
    printf("%.5lf\n", 1.0 * (a * b + b * (b - 1)) / ((a + b) * (a + b - c - 1)));
  }
  
  
  return 0;
  
  
}