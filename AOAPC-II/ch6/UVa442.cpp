// Joker
#include <bits/stdc++.h>
using namespace std;

int n;
map<char, pair<int, int> > matrix;

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  cin >> n;
  char m;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> m >> x >> y;
    matrix[m] = make_pair(x, y);
  } 
  
  string line;
  getline(cin, line);
  while (getline(cin, line) && line.size()) {
    stack<pair<int, int> > stk;
    int ans = 0;
    bool ok = true;
    for (int i = 0; i < line.size(); i++) {
      char cur = line[i];
      if (cur == '(') stk.push(make_pair(0, 0));
      else if (isalpha(cur)) stk.push(matrix[cur]);
      else {
        pair<int, int> t1 = stk.top(); stk.pop();
        while (!stk.empty() && stk.top().first != 0) {
          pair<int, int> t2 = stk.top(); stk.pop();
          if (t2.second != t1.first) {
            ok = false;
            break;
          } else {
            ans += t2.first * t2.second * t1.second;
            t1 = make_pair(t2.first, t1.second);
          }
        }
        stk.pop(); stk.push(t1);
      }
      if (!ok) break;
    }
    while (stk.size() > 2) {
      pair<int, int> t1 = stk.top(); stk.pop();
      pair<int, int> t2 = stk.top(); stk.pop();
      if (t2.second != t1.first) {
        ok = false;
        break;
      } else {
        ans += t2.first * t2.second * t1.second;
        stk.push(make_pair(t2.first, t1.second));
      }
    }
    if (!ok) puts("error");
    else printf("%d\n", ans);
  }
  
  return 0;
}