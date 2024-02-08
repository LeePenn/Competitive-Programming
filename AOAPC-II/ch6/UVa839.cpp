// Joker
#include <bits/stdc++.h>
using namespace std;

bool solve(int& w) {
  int wl, wr, dl, dr;
  cin >> wl >> dl >> wr >> dr;
  bool bl = true, br = true;
  if (!wl) bl = solve(wl);
  if (!wr) br = solve(wr);
  w = wl + wr;
  return bl && br && wl * dl == wr * dr;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int T;
  cin >> T;
  while (T--) {
    int w;
    puts(solve(w) ? "YES" : "NO");
    if (T) puts("");
  }
  
  
  
  
  return 0;
}