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
// ostream& operator<<(ostream& os, const vector<char> &v) {
  
// } 
const int N = 6;
int T;
char grid1[N][N], grid2[N][N];
vector<vector<char> > can_choose;
int k;
vector<char> output;
void ReadInput() {
  scanf("%d", &k);
  for (int i = 0; i < N; ++i) {
    scanf("%s", grid1[i]);
    // printf("%s\n", grid1[i]);
  }
  // printf("\n\n");
  for (int i = 0; i < N; ++i) {
    scanf("%s", grid2[i]);
    // printf("%s\n", grid2[i]);
  }
  // printf("\n\n");
}
int calc(int i) {
  if (i >= 5) return 0;
  
  int ans = 1;
  for (int j = i; j < 5; ++j) {
    ans *= (int)can_choose[j].size();
  }
  
  return ans;
}
void solve(int i, int k) {
  if (i >= 5) return;
  if (i == 4) {
    output.push_back(can_choose[i][k - 1]);
    return;
  }
  
  int pt = 0;
  while (calc(i + 1) < k) {
    k -= calc(i + 1);
    pt++;
  }
  // cout << "i: " << i << ", k: " << k << ", pt: " << pt << endl;
  // choose the pt character
  if (calc(i + 1) > k) {
    output.push_back(can_choose[i][pt]);
    solve(i + 1, k);
    return;
  }
  
  if (calc(i + 1) == k) {
    output.push_back(can_choose[i][pt]);
    for (int j = i + 1; j < 5; ++j) {
      output.push_back(can_choose[j][can_choose[j].size() - 1]);
    }
    return;
  }
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  cin >> T;
  while (T--) {
    ReadInput();
        
    can_choose.clear();
    output.clear();
    bool ok = 1;
    for (int j = 0; j < N - 1; ++j) {
      set<char> s;
      for (int k = 0; k < N; ++k) s.insert(grid1[k][j]);
      
      vector<char> cur;
      for (int k = 0; k < N; ++k) {
        if (s.count(grid2[k][j])) {
          cur.push_back(grid2[k][j]);
          s.erase(grid2[k][j]);
        }
      }
      if (cur.empty()) {
        ok = 0;
        break;
      }
      sort(cur.begin(), cur.end());
      can_choose.push_back(cur);
    }
    
    // for (size_t i = 0; i < can_choose.size(); ++i) {
    //   for (size_t j = 0; j < can_choose[i][j]; ++j) {
    //     cout << can_choose[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    
    if (!ok) {
      printf("NO\n");
      continue;
    }
    
    if (calc(0) < k) {
      printf("NO\n");
      continue;
    }
    
    solve(0, k);
    
    for (size_t i = 0; i < output.size(); ++i) printf("%c", output[i]);
    printf("\n");
  }
  
  
  return 0;
  
  
}