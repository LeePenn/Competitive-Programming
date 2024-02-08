// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int nxt[N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  char s[N];
  while (scanf("%s", s + 1) == 1) {
    int n = strlen(s + 1);
    memset(nxt, 0, sizeof(nxt));
    int cur = 0, last = 0;
    nxt[cur] = 0; // 虚拟头结点和尾结点都是0，是两个不同的0
    for (int i = 1; i <= n; i++) {
      if (s[i] == '[') cur = 0;
      else if (s[i] == ']') cur = last;
      else {
        nxt[i] = nxt[cur];
        nxt[cur] = i;
        if (cur == last) last = i; // 只有s[i] == ']'后才可能
        cur = i;
      }
    }
    for (int i = nxt[0]; i; i = nxt[i]) // 头结点和尾结点都是0
      cout << s[i];
    cout << endl;
  }
  
  
  
  return 0;
}