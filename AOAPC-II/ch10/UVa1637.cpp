#include <bitset>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <queue>
#include <set>

typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

map<vector<int>, double> d;
char card[9][4][3];
double dp(vector<int> &cnt, int c) {
  if (c == 0) return 1;
  if (d.count(cnt) != 0) return d[cnt];
  
  double sum = 0;
  int tot = 0;
  for (int i = 0; i < 9; ++i) if (cnt[i] > 0) {
    for (int j = i + 1; j < 9; ++j) if (cnt[j] > 0) {
      if (card[i][cnt[i] - 1][0] == card[j][cnt[j] - 1][0]) {
        tot++;
        cnt[i]--; cnt[j]--;
        sum += dp(cnt, c - 2);
        cnt[i]++; cnt[j]++;
      }
    }
  }
  
  if (tot == 0) return d[cnt] = 0;
  
  return d[cnt] = sum / tot;
}
bool readInput() {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (scanf("%s", card[i][j]) != 1) return false;
    }
  }
  return true;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  while (readInput()) {
    vector<int> cnt(9, 4);
    d.clear();
    printf("%.6lf\n", dp(cnt, 36));
  }

  return 0;
}