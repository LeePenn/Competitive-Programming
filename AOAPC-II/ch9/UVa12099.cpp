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
const int N = 70 + 4, W = 30, INF = 1e9;
struct Book {
    int h, w;
    bool operator <(const Book &rhs) const {
        return h > rhs.h || (h == rhs.h && w > rhs.w);
    }
} books[N];
int dp[2][N * W][N * W];
int sumw[N];

inline int f(int w, int h) {
    return w == 0 ? h : 0;
}
void update(int &x, int v) {
    if (x < 0 || x > v) x = v;
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &books[i].h, &books[i].w);
    }
    sort(books, books + n);
    
    sumw[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sumw[i] = sumw[i - 1] + books[i - 1].w;
    }
    
    dp[0][0][0] = 0;
    int t = 0;
    // 从dp定义上， 第一本书一定会放在level1
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= sumw[i + 1]; ++j) {
            for (int k = 0; k <= sumw[i + 1] - j; ++k) {
                dp[t ^ 1][j][k] = -1;
            }
        }
        // put ith book
        for (int j = 0; j <= sumw[i]; ++j) {
            for (int k = 0; k <= sumw[i] - j; ++k) if (dp[t][j][k] >= 0) {
                update(dp[t ^ 1][j][k], dp[t][j][k]);
                update(dp[t ^ 1][j + books[i].w][k], dp[t][j][k] + f(j, books[i].h));
                update(dp[t ^ 1][j][k + books[i].w], dp[t][j][k] + f(k, books[i].h));
            }
        }
        t ^= 1;
    }
    
    int ans = INF;
    for (int j = 1; j <= sumw[n]; ++j) {
        for (int k = 1; k <= sumw[n] - j; ++k) if (dp[t][j][k] >= 0) {
            int w = max(max(j, k), sumw[n] - j - k);
            int h = books[0].h + dp[t][j][k];
            ans = min(ans, h * w);
        }
    }
    printf("%d\n", ans);
  }
  

  return 0;
}