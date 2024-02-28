// Joker
#include <bits/stdc++.h>
using namespace std;

char s[1030];
int buf[32][32];
int cnt;

void draw(const char* s, int& p, int r, int c, int w) {
  char cur = s[p++];
  if (cur == 'p') {
    int t = w >> 1;
    draw(s, p, r, c + t, t);
    draw(s, p, r, c, t);
    draw(s, p, r + t, c, t);
    draw(s, p, r + t, c + t, t);
  } else if (cur == 'f') {
    for (int i = r; i < r + w; i++) {
      for (int j = c; j < c + w; j++) {
        if (!buf[i][j]) {
          buf[i][j] = 1;
          cnt++;
        }
      }
    }
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int T;
  cin >> T;
  while (T--) {
    memset(buf, 0, sizeof(buf));
    cnt = 0;
    for (int i = 0; i < 2; i++) {
      scanf("%s", s);
      int p = 0;
      draw(s, p, 0, 0, 32);
    }
    printf("There are %d black pixels.\n", cnt);
  }
  
  
  return 0;
}