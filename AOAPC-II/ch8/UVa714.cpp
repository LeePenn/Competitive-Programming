// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 500 + 2;
int T, n, k;
int a[N];

bool solve(ll m) {
  ll sum = 0;
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (sum + a[i] <= m) 
      sum = sum + a[i];
    else {
      cnt++;
      sum = (ll)a[i];
    }
  }
  
  return cnt <= k;
}

int last[N];

void print(ll ans) {
  ll sum = 0;
  int remain = k;
  memset(last, 0, sizeof(last));
  for (int i = n; i >= 1; i--) {
    if (sum + a[i] > ans || i < remain) {
      sum = a[i];
      last[i] = 1;
      remain--;
    } else sum = sum + a[i];
  }
  
  for (int i = 1; i < n; i++) {
    printf("%d ", a[i]);
    if (last[i]) printf("/ ");
  }
  
  printf("%d\n", a[n]);
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    ll l = -1, r = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      l = max(l, (ll)a[i]);
      r = r + a[i];
    }
    
    while (l < r) {
      ll m = l + ((r - l) >> 1);
      if (solve(m)) r = m;
      else l = m + 1;
    }
    
    print(l);
  }
  
  return 0;
}