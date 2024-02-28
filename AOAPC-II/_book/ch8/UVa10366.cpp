// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 4;
int L, R, LHs[N], RHs[N], LH, RH, LHi, RHi;

int solve() {
  if (LH == RH) {
    int lt = 0, rt = 0;
    for (int i = L, h = LHs[L]; i > LHi; i--) {
      lt += h, h = max(h, LHs[i - 1]);
    }
    for (int i = R, h = RHs[R]; i > RHi; i--) {
      rt += h, h = max(h, RHs[i - 1]);
    }
    
    return (LHi + RHi + 1) * LH * 2 + min(lt, rt) * 2 * 2;
  }
  
  int lt = 0, rt = 0, t = 0;
  int T = min(LH, RH), LTi = 0, RTi = 0;
  while (LTi <= L && LHs[LTi] < T) LTi++;
  while (RTi <= R && RHs[RTi] < T) RTi++;
  
  if (LH < RH) {
    for (int i = L, h = LHs[L]; i > LHi; i--) {
      lt += h, h = max(h, LHs[i - 1]);
    }
    for (int i = RTi, h = T; RHs[i] <= T; i++) {
      rt += h, h = max(h, RHs[i + 1]);
    }
    t = lt > rt ? (lt + rt) : 2 * lt;
  }
  
  if (LH > RH) {
    for (int i = R, h = RHs[R]; i > RHi; i--) {
      rt += h, h = max(h, RHs[i - 1]);
    }
    for (int i = LTi, h = T; LHs[i] <= T; i++) {
      lt += h, h = max(h, LHs[i + 1]);
    }
    t = rt > lt ? (rt + lt) : 2 * rt;
  }
  
  return t * 2 + (RTi + LTi + 1) * T * 2;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d %d", &L, &R) == 2 && L && R) {
    LH = 0, RH = 0;
    for (int i = -L; i > 0; i -= 2) {
      int x; scanf("%d", &x);
      LHs[i >> 1] = x;
      if (LH <= x) {
        LH = x;
        LHi = i >> 1;
      }
    }
    
    for (int i = 0; i < R; i += 2) {
      int x; scanf("%d", &x);
      RHs[i >> 1] = x;
      if (RH < x) {
        RH = x;
        RHi = i >> 1;
      }
    }
    L = (-L) >> 1;
    R = R >> 1;
    
    printf("%d\n", solve());
  }
  
  return 0;
}