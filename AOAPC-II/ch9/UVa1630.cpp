#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <queue>

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 100 + 50, INF = 1e8;
string str, dp[N][N];
int T, kase;
int calc(int l, int r) {
    int len = r - l + 1;
    for (int i = 1; i <= len / 2; ++i) {
        if (len % i) continue;
        bool can_fold = 1;
        for (int s = l; s <= r - i; ++s) {
            if (str[s] == str[s + i]) continue;
            can_fold = 0;
            break;
        }
        if (can_fold) {
            return i;
        }
        
    }
    return 0;
}
string &DP(int l, int r) {
    string &ans = dp[l][r];
    if (!ans.empty()) return ans;
    
    if (l == r) return ans = str[l];
    
    int minK, minLen = INF; 
    for (int i = l; i < r; ++i) {
        int len = DP(l, i).length() + DP(i + 1, r).length();
        if (minLen > len) {
            minLen = len;
            minK = i;
        }
    } 
    ans = DP(l, minK) + DP(minK + 1, r);
    // 这步是关键
    int cycle = calc(l, r);
    if (cycle) {
        string ss = to_string((r - l + 1) / cycle) + "(" + DP(l, l + cycle - 1) + ")";
        if (ss.length() < ans.length()) {
            ans = ss;
        }
    }
    
    return ans;
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  kase = 1;
  while (cin >> str) {
    for (int i = 0; i < str.length(); ++i) {
        for (int j = 0; j < str.length(); ++j) {
            dp[i][j].clear();
        }
    }
    cout << DP(0, str.length() - 1) << endl;
    kase++;
  }
  
  

  return 0;
}