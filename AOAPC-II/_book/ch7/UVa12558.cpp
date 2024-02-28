// Joker
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
ll A, B;
unordered_set<ll> forbid;
int maxd;

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

bool better(const vector<ll>& cur, const vector<ll>& ans) {
  if (ans.empty()) return true;
  
  for (size_t i = cur.size() - 1; i >= 0; i--) {
    if (cur[i] != ans[i]) return cur[i] < ans[i];
  }
  return false;
}

ll get_first(ll a, ll b, ll last) {
  return max(b * B / (A * b - a * B), last + 1);
}

// 用累加而不是剩余，处理简单很多
void dfs(ll a, ll b, vector<ll>& cur, vector<ll>& ans) {
  if (cur.size() > maxd) return;
  if (a * B > b * A) return;
  
  if (a == A && b == B) {
    if (better(cur, ans)) ans = cur;
    return;
  }
  
  ll first = get_first(a, b, cur.empty() ? 1ll : cur.back());
  
  for (ll i = first;; i++) {
    int d = maxd - (int)cur.size();
    if (a * B * i + d * b * B < A * b * i) break;
    
    if (!forbid.count(i)) {
      ll na = a * i + b, nb = b * i, g = gcd(na, nb);
      cur.push_back(i);
      dfs(na / g, nb / g, cur, ans);
      cur.pop_back();
    }
  }
  return;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int T;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    int k;
    forbid.clear();
    scanf("%lld %lld %d", &A, &B, &k);
    for (int i = 0; i < k; i++) {
      ll x;
      scanf("%lld", &x);
      forbid.insert(x);
    }
    
    for (maxd = 2;; maxd++) {
      vector<ll> cur, ans;
      dfs(0, 1, cur, ans);
      if (!ans.empty()) {
        printf("Case %d: %lld/%lld=", kase, A, B);
        for (int i = 0; i < (int)ans.size(); i++) {
          if (!i) printf("1/%lld", ans[i]);
          else printf("+1/%lld", ans[i]);
        }
        printf("\n");
        break;
      }
    }
    
  }
  
  
  
  return 0;
}