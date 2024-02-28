// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 10003;
int kase, sum[N];

void build(int pos) {
  int x;
  cin >> x;
  if (x == -1) return;
  sum[pos] += x;
  build(pos - 1); build(pos + 1);
}

bool read_list() {
  int x;
  cin >> x;
  if (x == -1) return false;
  memset(sum, 0, sizeof(sum));
  int pos = N >> 1;
  sum[pos] += x;
  build(pos - 1); build(pos + 1);
  return true;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  kase = 0;
  while (read_list()) {
    printf("Case %d:\n", ++kase);
    bool first = true;
    for (int i = 0; i < N; i++) {
      if (sum[i]) {
        if (first) {
          first = false;
          cout << sum[i];
        } else cout << ' ' << sum[i];
      }
    }
    cout << endl << endl;
    
  }
  
  
  
  
  return 0;
}