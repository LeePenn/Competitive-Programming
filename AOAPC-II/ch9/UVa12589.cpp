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

#define LL long long
#define ULL unsigned long long
using namespace std;
struct Point {
    int x, y;
    Point(int x = 0, int y = 0): x(x), y(y) {}
    bool operator <(const Point &rhs) const {
        return atan2(y, x) > atan2(rhs.y, rhs.x);
    }
};
typedef Point Vector;
const int N = 50 + 3, Y = N * N;
int n, k, h, dp[N][N][Y];
vector<Vector> vs;
int DP(int i, int c, int y) {
    int &ans = dp[i][c][y];
    if (ans != -1) return ans;
    
    if (i == n || c == k) return 0;
    
    ans = DP(i + 1, c, y);
    const Vector &v = vs[i];
    ans = max(ans, DP(i + 1, c + 1, y + v.y) + (2 * y + v.y) * v.x);
    return ans;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  int t, T;
  Vector v;
  scanf("%d\n", &T);
  for (t = 1; t <= T; ++t) {
    h = 0;
    vs.clear();
    scanf("%d%d\n", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d\n", &v.x, &v.y);
        vs.push_back(v);
        h += v.y;
    }
    sort(vs.begin(), vs.end());
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int y = 0; y <= h; ++y) {
                dp[i][j][y] = -1;
            }
        }
    }
    int ans = DP(0, 0, 0);
    printf("Case %d: %d\n", t, ans);
  }
  
  

  return 0;
  
  
}