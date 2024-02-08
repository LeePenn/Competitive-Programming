// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 3;
char buf[N][N];
int T, n;

void dfs(int r, int c) {
  printf("%c(", buf[r][c]);
  if (r + 1 < n && buf[r + 1][c] == '|') {
    int i = c;
    while (i - 1 >= 0 && buf[r + 2][i - 1] == '-') i--;
    while (buf[r + 2][i] == '-' && buf[r + 3][i] != '\0') {
      if (!isspace(buf[r + 3][i])) dfs(r + 3, i);
      i++;
    }
  }
  printf(")");
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  fgets(buf[0], N, stdin);
  sscanf(buf[0], "%d", &T);
  while (T--) {
    n = 0;
    for (;;) {
      fgets(buf[n], N, stdin);  
      if (buf[n][0] == '#') break;
      else n++;
    }
    printf("(");
    if (n) {
      for (int i = 0; i < strlen(buf[0]); i++) {
        if (buf[0][i] != ' ') {
          dfs(0, i);
          break;
        }
      }
    }
    printf(")\n");
  }
  
  
  return 0;
}