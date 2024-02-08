// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 4;
int n, d;
int num[N];
int nxt[N][10];

void init() {
  for (int i = 0; i < 10; i++) {
    int pos = n;
    for (int j = n - 1; ~j; j--) {
      if (num[j] == i) pos = j;
      nxt[j][i] = pos;
    }
  }
}

void find_max(int start, int end, int& pos) {
  for (int i = 9; ~i; i--) {
    if (nxt[start][i] < end) {
      pos = nxt[start][i];
      break;
    }
  }
}

void solve(int tot, int left) {
  vector<int> ans;
  int start = 0;
  while (left--) {
    int pos;
    find_max(start, tot - left, pos);
    printf("%d", num[pos]);
    start = pos + 1;
  }
  printf("\n");
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (cin >> n >> d && n && d) {
    string line;
    cin >> line;
    for (int i = 0; i < n; i++) num[i] = line[i] - '0';
    init();
    
    solve(n, n - d);
  }
  
  
  
  return 0;
}