// Joker
#include <bits/stdc++.h>
using namespace std;

char s[256 + 2];

bool check(const char* buf) {
  int len = strlen(s);
  stack<char> stk;
  bool ok = true;
  for (int i = 0; i < len; i++) {
    char c = s[i];
    if (c == '(' || c == '[') stk.push(c);
    else {
      if (stk.empty()) return false;
      char t = stk.top();
      if (c == ')') {
        if (t == '(') stk.pop();
        else return false;
      } else if (c == ']') {
        if (t == '[') stk.pop();
        else return false;
      }
    }
  }
  return stk.empty();
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int T;
  scanf("%d\n", &T);
  while (T--) {
    gets(s); // 必须读取整行，因为会有空串
    if (check(s)) puts("Yes");
    else puts("No");
  }
  
  
  return 0;
}