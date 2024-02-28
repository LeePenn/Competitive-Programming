// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 30 + 2;
int n, a[N];

bool prework() {
  string buf;
  getline(cin, buf);
  stringstream ss(buf);
  bool has_value = false;
  int x, i = 1;
  while (ss >> x && x > 0) {
    has_value = true;
    a[i] = x;
    n = i++;
  }
  if (has_value)
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
  cout << endl;
  return has_value;
}

void solve() {
  
  int lastFlip = n;
  while (lastFlip) {
    int maxPos = max_element(a + 1, a + lastFlip + 1) - a;
    int maxVal = a[maxPos];
    if (maxPos == lastFlip) { lastFlip--; continue; }
    if (maxPos == 1) {
      for (int i = 1; i <= lastFlip / 2; i++) {
        swap(a[i], a[lastFlip - i + 1]);
      }
      printf("%d ", n - lastFlip + 1);
      lastFlip--;
      continue;
    }
    
    for (int i = 1; i <= maxPos / 2; i++) {
      swap(a[i], a[maxPos - i + 1]);
    }
    for (int i = 1; i <= lastFlip / 2; i++) {
      swap(a[i], a[lastFlip - i + 1]);
    }
    printf("%d %d ", n - maxPos + 1, n - lastFlip + 1);
    lastFlip--;
    
  }
  printf("0\n");
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (prework()) { solve(); }
  
  
  return 0;
}