// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int n, a[N];

void solve() {
  int stk[N];
  int i = 0, j = 1, num = 1;
  while (num <= n + 1 && j <= n) {
    if (!i || stk[i] != a[j]) stk[++i] = num++;
    else if (stk[i] == a[j]) {
      i--; j++;
    }
  }
  if (!i && j == n + 1) puts("Yes");
  else puts("No");
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (cin >> n && n) {
    
    while (cin >> a[1] && a[1]) {
      for (int i = 2; i <= n; i++) cin >> a[i];
      solve();
    }
    cout << endl;
  }
  return 0;
}