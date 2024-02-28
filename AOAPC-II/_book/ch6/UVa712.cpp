// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 8;
char leaf[1 << N];
int order[N];
int n, m;

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  
  for (int t = 1; scanf("%d", &n) == 1 && n; t++) {
    printf("S-Tree #%d:\n", t);
    char s[4];
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      order[i] = s[1] - '1';
    }
    scanf("%s", leaf);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      char seq[N];
      scanf("%s", seq);
      int d = 0, u = 0;
      while (d < n) {
        u = (u << 1) + (seq[order[d++]] - '0');
      }
      printf("%c", leaf[u]);
    }
    printf("\n\n");
  }
  
  
  return 0;
}