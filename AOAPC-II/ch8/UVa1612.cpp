// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 16384 + 3;
vector<int> PS[N], IDs;
int n;

int solve() {
  int lastScore, lastId = -1;
  for (auto& id : IDs) {
    const auto& p = PS[id];
    if (lastId == -1) {
      lastScore = p.front();
    } else {
      bool found = false;
      for (auto& s: p) {
        if (s < lastScore || (s == lastScore && id > lastId)) {
          found = true;
          lastScore = s;
          break;
        }
      }
      if (!found) return -1;
    }
    lastId = id;
  }
  return lastScore;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int kase = 1; scanf("%d", &n) == 1 && n; kase++) {
    for (int i = 0; i < n; i++) {
      auto& p = PS[i];
      p.clear(); p.push_back(0);
      for (int j = 0; j < 3; j++) {
        char buf[8];
        int a, b = 0;
        scanf("%s", buf);
        sscanf(buf, "%d", &a);
        char *pp = strchr(buf, '.');
        if (pp) sscanf(++pp, "%d", &b);
        p.push_back(a * 100 + b);
      }
      p.push_back(p[1] + p[2]); p.push_back(p[1] + p[3]);
      p.push_back(p[2] + p[3]); p.push_back(p[1] + p[2] + p[3]);
      sort(p.begin(), p.end(), greater<int>());
    }
    
    IDs.clear(); 
    for (int i = 0; i < n; i++) {
      int x; scanf("%d", &x);
      IDs.push_back(x - 1);
    }
    int ans = solve();
    if (ans == -1) printf("Case %d: No solution\n", kase);
    else printf("Case %d: %d.%02d\n", kase, ans / 100, ans % 100);
  }
  
  
  return 0;
}