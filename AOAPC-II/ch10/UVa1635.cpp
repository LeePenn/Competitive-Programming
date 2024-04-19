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
const int N = 100000 + 3;
bool bad[N];
int n, m;
void prime_factors(int n, vector<int> &primes) {
  int m = floor(sqrt(n) + 0.5);
  for (int i = 2; i <= m; ++i) {
    if (n % i == 0) {
      primes.push_back(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) primes.push_back(n);
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (cin >> n >> m) {
    vector<int> primes;
    prime_factors(m, primes);
    memset(bad, 0, sizeof(bad));
    n--;
    
    for (int i = 0; i < primes.size(); ++i) {
      int p = primes[i];
      int min_e = 0, x = m;
      while (x % p == 0) {
        x /= p;
        min_e++;
      }
      int e = 0;
      for (int k = 1; k < n; ++k) {
        x = n - k + 1;
        while (x % p == 0) {
          e++;
          x /= p;
        }
        x = k;
        while (x % p == 0) {
          e--;
          x /= p;
        }
        if (e < min_e) bad[k] = 1;
      }
    }
    
    vector<int> ans;
    for (int k = 1; k < n; ++k) {
      if (!bad[k]) ans.push_back(k + 1);
    }
    
    cout << ans.size() << endl;
    if (!ans.empty()) {
      cout << ans[0];
      for (size_t i = 1; i < ans.size(); ++i) {
        cout << " " << ans[i];
      }
    }
    cout << endl;
  }
  
  return 0;
  
  
}