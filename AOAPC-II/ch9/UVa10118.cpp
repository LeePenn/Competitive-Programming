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
const int N = 40 + 5, INF = 0x3f3f3f3f;
int piles[4][N], n;
int dp[N][N][N][N], states[N][N][N][N];
int bcnt[N * N * N * N];

struct Basket {
    int color[20 + 4], size;
    Basket(): size(0) {
        memset(color, 0, sizeof(color));
    }
    bool isFull() {
        return size == 5;
    }
    void take(int c) {
        color[c] = 0;
        size--;
    }
    void put(int c) {
        color[c] = c;
        size++;
    }
};
int DP(int n1, int n2, int n3, int n4, Basket &bkt) {
    int &ans = dp[n1][n2][n3][n4];
    if (ans >= 0) return ans;
    
    ans = 0;
    if (bkt.isFull()) return ans;
    
    if (n1 > 0) {
        int c = piles[0][n1];
        if (bkt.color[c]) {
            bkt.take(c);
            ans = max(ans, DP(n1 - 1, n2, n3, n4, bkt) + 1);
            bkt.put(c);
        } else {
            bkt.put(c);
            ans = max(ans, DP(n1 - 1, n2, n3, n4, bkt));
            bkt.take(c);
        }
    }
    if (n2 > 0) {
        int c = piles[1][n2];
        if (bkt.color[c]) {
            bkt.take(c);
            ans = max(ans, DP(n1, n2 - 1, n3, n4, bkt) + 1);
            bkt.put(c);
        } else {
            bkt.put(c);
            ans = max(ans, DP(n1, n2 - 1, n3, n4, bkt));
            bkt.take(c);
        }
    }
    if (n3 > 0) {
        int c = piles[2][n3];
        if (bkt.color[c]) {
            bkt.take(c);
            ans = max(ans, DP(n1, n2, n3 - 1, n4, bkt) + 1);
            bkt.put(c);
        } else {
            bkt.put(c);
            ans = max(ans, DP(n1, n2, n3 - 1, n4, bkt));
            bkt.take(c);
        }
    }
    if (n4 > 0) {
        int c = piles[3][n4];
        if (bkt.color[c]) {
            bkt.take(c);
            ans = max(ans, DP(n1, n2, n3, n4 - 1, bkt) + 1);
            bkt.put(c);
        } else {
            bkt.put(c);
            ans = max(ans, DP(n1, n2, n3, n4 - 1, bkt));
            bkt.take(c);
        }
    }
    return ans;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    Basket bkt;
    printf("%d\n", DP(n, n, n, n, bkt));
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &piles[j][n - i + 1]);
        }
    }
    
    solve();
  }
  
  

  return 0;
}