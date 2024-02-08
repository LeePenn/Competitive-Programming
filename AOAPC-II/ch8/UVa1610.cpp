// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 3;
string names[N];
int n;

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) cin >> names[i];
    sort(names, names + n);
    int i = (n - 1) >> 1, j = n >> 1;
    int L = names[i].size();
    char ans[30 + 3];
    memset(ans, 0, sizeof(ans));
    for (int k = 0; k < L; k++) {
      ans[k] = 'A';
      while (ans[k] <= 'Z' && ans < names[i]) ++ans[k];
      if (ans[k] <= 'Z' && ans >= names[i] && ans < names[j]) break;
      if (ans[k] != names[i][k]) --ans[k];
    }
    
    cout << ans << endl;
    
  }
  
  
  
  return 0;
}