#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>

#define LL long long
using namespace std;
const int N = 16, LEN = 100 + 5;
int calc_overlap(const string &s1, const string &s2) {
    int n1 = s1.length(), n2 = s2.length();
    for (int i = 1; i < n1; ++i) {
        if (n2 + i <= n1) continue;
        
        bool ok = 1;
        for (int j = 0; i + j < n1; ++j) {
            if (s1[i + j] != s2[j]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            return n1 - i;
        }
    }
    return 0;
}

struct Item {
    string s, rev;
    bool operator <(const Item &rhs) const {
        return s.length() < rhs.s.length();
    }
};
int n;
string s[N][2];
int len[N];
int overlap[N][N][2][2];
void Init() {
    Item tmp[N];
    for (int i = 0; i < n; ++i) {
        cin >> tmp[i].s;
        tmp[i].rev = tmp[i].s;
        reverse(tmp[i].rev.begin(), tmp[i].rev.end());
    }
    
    int n2 = 0;
    sort(tmp, tmp + n);
    for (int i = 0; i < n; ++i) {
        bool need = 1;
        for (int j = i + 1; j < n; ++j) {
            if (tmp[j].s.find(tmp[i].s) != string::npos ||
                tmp[j].rev.find(tmp[i].s) != string::npos) {
                    need = 0;
                    break;
                }
        }
        if (need) {
            s[n2][0] = tmp[i].s; 
            s[n2][1] = tmp[i].rev;
            len[n2] = tmp[i].s.length();
            n2++;
        }
    }
    
    n = n2;
    // 只算无重合独立的字符串
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    overlap[i][j][x][y] = calc_overlap(s[i][x], s[j][y]);
                }
            }
        }
    }
}
int dp[1 << N][N][2];
inline void Update(int &x, int v) {
    if (x < 0 || v < x) x = v;
}
void Solve() {
    memset(dp, -1, sizeof(dp));
    dp[1][0][0] = len[0];
    int full = (1 << n) - 1;
    // 正推
    for (int s = 1; s < full; ++s) {
        for (int i = 0; i < n; ++i) {
            for (int x = 0; x < 2; ++x) if (dp[s][i][x] >= 0) {
                for (int j = 1; j < n; ++j) {
                    if (!(s & (1 << j))) {
                        for (int y = 0; y < 2; ++y) {
                            Update(dp[s | (1 << j)][j][y], dp[s][i][x] + len[j] - overlap[i][j][x][y]);
                        }
                    }
                }
            }
        }
    }
    
    int ans = -1;
    // 这种处理环的方式很重要
    for (int i = 0; i < n; ++i) {
        for (int x = 0; x < 2; ++x) if (dp[full][i][x] >= 0) {
            Update(ans, dp[full][i][x] - overlap[i][0][x][0]);
        }
    }
    
    if (ans <= 1) ans = 2;
    cout << ans << endl;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (cin >> n && n) {
    Init();
    Solve();
  }
  
  

  return 0;
}