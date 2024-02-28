// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100000 + 4;
int n, a[N], L[N], R[N];
ll sum[N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  sum[0] = 0;
  for (int kase = 0; scanf("%d", &n) == 1; kase++) {
    if (kase) puts("");
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum[i] = sum[i - 1] + (ll)a[i];
    }
    
    stack<int> s1;
    for (int i = 1; i <= n; i++) {
      while (!s1.empty() && a[s1.top()] >= a[i]) s1.pop();
      L[i] = s1.empty() ? 0 : s1.top();
      s1.push(i);
    }
    
    stack<int> s2;
    for (int i = n; i; i--) {
      while (!s2.empty() && a[s2.top()] >= a[i]) s2.pop();
      R[i] = s2.empty() ? n + 1 : s2.top();
      s2.push(i);
    }
    
    ll ans = -1;
    int ans_i;
    for (int i = 1; i <= n; i++) {
      ll v = (sum[R[i] - 1] - sum[L[i]]) * (ll)a[i];
      if (v > ans) ans = v, ans_i = i;
    }
    
    if (ans == 0) printf("0\n1 1\n");
    else printf("%lld\n%d %d\n", ans, L[ans_i] + 1, R[ans_i] - 1);
  }
  
  return 0;
}