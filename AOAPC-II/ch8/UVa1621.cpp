// Joker
#include <bits/stdc++.h>
using namespace std;

int n, A[4], cur;

void move(int step) {
  int ci = abs(step);
  cur += step;
  printf(" %d", cur);
  A[ci]--;
}

void move(int step, int cnt) {
  for (int i = 0; i < cnt; i++) move(step);
}

void solve() {
  printf("0");
  cur = 0;
  
  int c3 = A[3] / 3, cm3 = A[3] % 3;
  if (cm3 == 0) {
    move(3, c3), move(1);
    move(-3, c3), move(1);
    move(3, c3);
  }
  
  if (cm3 == 1) {
    move(3, c3 + 1), move(-2);
    move(-3, c3), move(1);
    move(3, c3), move(2);
  }
  
  if (cm3 == 2) {
    move(3, c3 + 1), move(-1);
    move(-3, c3), move(-1);
    move(3, c3 + 1);
  }
  
  move(1, A[1] - 1);
  int b2 = A[2] / 2, bm2 = A[2] % 2;
  if (bm2 == 0) 
    move(2, b2), move(1), move(-2, b2);
  else 
    move(2, b2 + 1), move(-1), move(-2, b2);
  puts("");
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int t;
  scanf("%d", &t); 
  while (t--) {
    scanf("%d %d %d", &A[1], &A[2], &A[3]);
    n = A[1] + A[2] + A[3] + 1;
    solve();
  }
  
  return 0;
}