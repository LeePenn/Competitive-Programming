// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 50 + 2;
int n;
char G[2][N][N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  bool first = true;
  while (scanf("%d", &n) == 1) {
    if (first) first = false;
    else puts("");
    printf("%d %d %d\n", 2, n, n);
    char ch = 'A';
    for (int c = 0; c < n; c++) {
      for (int r = 0; r < n; r++) {
        putchar(ch);
      }
      cout << endl;
      if (ch == 'Z') ch = 'a';
      else ch++;
    }
    cout << endl;
    
    
    for (int r = 0; r < n; r++) {
      ch = 'A';
      for (int c = 0; c < n; c++) {
        putchar(ch);
          if (ch == 'Z') ch = 'a';
        else ch++;
      }
      cout << endl;
      
    }
  }
  
  return 0;
}