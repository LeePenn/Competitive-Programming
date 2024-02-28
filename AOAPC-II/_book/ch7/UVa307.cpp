// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 2;
int n, a[N];
int len;
bool used[N];

bool dfs(int idx, int sum, int cnt) {
  if (!cnt) return true;
  
  for (int i = idx; i <= n; i++) {
    if (used[i]) continue;
    if (sum + a[i] > len) continue;
    used[i] = true;
    if (sum + a[i] == len) {
      if (dfs(1, 0, cnt - 1)) return true;
    } else {
      if (dfs(i + 1, sum + a[i], cnt)) return true;
    }
    used[i] = false;
    if (sum + a[i] == len) return false;
    if (sum == 0 && idx == 1) return false;
    while (i + 1 <= n && a[i + 1] == a[i]) i++;
  }
  return false;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = a[1]; i <= sum; i++) {
      if (sum % i == 0) {
        memset(used, 0, sizeof(used));
        len = i;
        if (dfs(1, 0, sum / i)) break;
      }
    }
    printf("%d\n", len);
  }
  
  
  
  return 0;
}