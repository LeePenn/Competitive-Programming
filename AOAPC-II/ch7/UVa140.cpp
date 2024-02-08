// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 8 + 2;
int id[256];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  char s[1000];
  while (scanf("%s", s) == 1 && s[0] != '#') {
    int n = 0;
    char letter[10];
    for (char ch = 'A'; ch <= 'Z'; ch++) {
      if (strchr(s, ch) != NULL) {
        id[ch] = n++;
        letter[id[ch]] = ch;
      }
    }
    
    int p = 0, q = 0, len = strlen(s);
    vector<int> u, v;
    for (;;) {
      while (p < len && s[p] != ':') p++;
      if (p == len) break;
      while (q < len && s[q] != ';') q++;
      for (int i = p + 1; i < q; i++) {
        u.push_back(id[s[p - 1]]);
        v.push_back(id[s[i]]);
      }
      p++; q++;
    }
    
    int P[N], bestP[N], pos[N], ans = n;
    for (int i = 0; i < n; i++) P[i] = i;
    do {
      int bandwidth = 0;
      for (int i = 0; i < n; i++) pos[P[i]] = i;
      for (int i = 0; i < (int)u.size(); i++) {
        bandwidth = max(bandwidth, abs(pos[u[i]] - pos[v[i]]));
      }
      if (bandwidth < ans) {
        ans = bandwidth;
        memcpy(bestP, P, sizeof(P));
      }
    } while (next_permutation(P, P + n));
    
    for (int i = 0; i < n; i++) {
      printf("%c ", letter[bestP[i]]);
    }
    printf("-> %d\n", ans);
  }
  
  
  return 0;
}