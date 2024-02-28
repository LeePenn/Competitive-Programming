// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 3;
int t;
string S, T;

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &t);
  for (int kase = 1; kase <= t; kase++) {
    cin >> S >> T;
    int s01 = 0, s10 = 0, p0 = 0, p1 = 0, len = S.size();
    for (int i = 0; i < len; i++) {
      char cs = S[i], ct = T[i];
      if (cs != ct) {
        if (cs == '0') s01++;
        if (cs == '1') s10++;
        if (cs == '?' && ct == '0') p0++;
        if (cs == '?' && ct == '1') p1++;
      }
    }
    
    int ans = 0;
    int minSwap = min(s01, s10);
    ans += minSwap + p0;
    s01 -= minSwap, s10 -= minSwap;
    if (s10 > p1) ans = -1;
    else ans += s01 + s10 + p1;
    printf("Case %d: %d\n", kase, ans);
  }
  
  
  
  return 0;
}