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
int n;
LL gcd(LL a, LL b) {
  if (!b) return a;
  return gcd(b, a % b);
}
LL lcm(LL a, LL b) {
  return a / gcd(a, b) * b;
}
int LL_len(LL x) {
  stringstream ss;
  ss << x;
  return ss.str().length();
}
void print_chars(int cnt, char ch) {
  while (cnt--) cout << ch;
}
void output(LL a, LL b, LL c) {
  if (b == 0) {
    cout << a << endl;
    return;
  }
  
  LL L1 = LL_len(a);
  print_chars(L1 + 1, ' '); cout << b << endl;
  cout << a << " "; print_chars(LL_len(c), '-'); cout << endl;
  print_chars(L1 + 1, ' '); cout << c << endl;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (cin >> n && n) {
    if (n == 1) {
      output(1, 0, 0);
      continue;
    }
    
    LL x = 1;
    for (int i = 2; i <= n - 1; ++i) {
      x = lcm(x, i);
    }
    
    LL c = x, b = 0;
    for (int i = 2; i <= n - 1; ++i) {
      b += x / i;
    }
    b *= n;
    LL g = gcd(b, c);
    b /= g; c /= g;
    
    LL a = 1 + n + b / c;
    b %= c;
    output(a, b, c);
  }
  

  return 0;
}