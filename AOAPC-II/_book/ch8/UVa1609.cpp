// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1024 + 4;
int n;
char table[N][N];

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; i++) {
      scanf("%s", table[i] + 1);
    }
    
    vector<int> win, lose;
    for (int i = 2; i <= n; i++) {
      if (table[1][i] == '1') win.push_back(i);
      else lose.push_back(i);
    }
    
    while (n > 1) {
      vector<int> win2, lose2, Final;
      // phase 1
      for (int i = 0; i < lose.size(); i++) {
        int tlose = lose[i];
        bool match = false;
        for (int j = 0; j < win.size(); j++) {
          int& twin = win[j];
          if (twin > 0 && table[twin][tlose] == '1') {
            printf("%d %d\n", twin, tlose);
            win2.push_back(twin);
            twin = 0;
            match = true;
            break;
          }
        }
        if (!match) Final.push_back(tlose);
      }
      
      // phase 2
      bool match = false;
      for (int i = 0; i < win.size(); i++) {
        int twin = win[i];
        if (twin > 0) {
          if (!match) { printf("1 %d\n", twin); match = true; }
          else Final.push_back(twin);
        }
      }
      
      for (int i = 0; i < Final.size(); i += 2) {
        printf("%d %d\n", Final[i], Final[i + 1]); // 前半段全是黑色，所以可以合并phase 3 4
        int keep = Final[i];
        if (table[keep][Final[i + 1]] == '0') keep = Final[i + 1];
        if (table[1][keep] == '1') win2.push_back(keep);
        else lose2.push_back(keep);
      }
      win = win2; lose = lose2;
      n >>= 1;
    }
    
  }
  
  
  return 0;
}