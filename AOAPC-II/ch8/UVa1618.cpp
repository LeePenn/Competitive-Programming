// Joker
#include <bits/stdc++.h>
using namespace std;


const int N = 5000 + 4;
int T, n, a[N];
vector<int> H[N], L[N];

bool find2(int p) { 
  for (auto q : L[p]) {
    auto rit = upper_bound(H[p].begin(), H[p].end(), q);
    if (rit == H[p].end()) continue;
    int r = *rit;
    auto sit = upper_bound(L[p].begin(), L[p].end(), r);
    while (sit != L[p].end()) {
      int s = *sit++;
      if (binary_search(H[q].begin(), H[q].end(), s)) return true;
    }
  }
  
  return false;
}

bool find1(int p) {
  for (auto q : H[p]) {
    auto rit = upper_bound(L[p].begin(), L[p].end(), q);
    if (rit == L[p].end()) continue;
    int r = *rit;
    auto sit = upper_bound(H[p].begin(), H[p].end(), r);
    while (sit != H[p].end()) {
      int s = *sit++;
      if (binary_search(L[q].begin(), L[q].end(), s)) return true;
    }
  }
  return false;
}

bool solve() {
  for (int i = 0; i < n; i++) {
    if (find1(i) || find2(i)) return true;
  }
  return false;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      H[i].clear(); L[i].clear();
    }
    
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[j] > a[i]) H[i].push_back(j);
        else if (a[j] < a[i]) L[i].push_back(j);
      }
    }
    
    if (solve()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  
  
  return 0;
}