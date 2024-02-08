// Joker
#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<int> used;

bool check_dup1(int num) {
  used.clear();
  for (int i = 0; i < 5; i++) {
    int cur = num % 10;
    if (used.count(cur)) return false;
    used.insert(cur);
    num /= 10;
  }
  return true;
}

bool check_dup2(int num) {
  for (int i = 0; i < 5; i++) {
    int cur = num % 10;
    if (used.count(cur)) return false;
    used.insert(cur);
    num /= 10;
  }
  return num == 0;
}

void solve() {
  bool found = false;
  for (int i = 1234; i <= 99999; i++) {
    if (!check_dup1(i)) continue;
    int ret = i * n;
    if (check_dup2(ret)) {
      printf("%05d / %05d = %d\n", ret, i, n);
      found = true;
    }
  }
  if (!found) printf("There are no solutions for %d.\n", n);
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  
  int kase = 0;
  while (scanf("%d", &n) == 1 && n) {
    if (kase++) printf("\n");
    solve();
  }
  
  return 0;
}