// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 500 + 4;
int a, b, m, n, d[N][N], dep[N];
ll ans, V, S;
/**!SECTION
 * 分析：暴力可以过，但是有很多其他解法，
 * 比如二分体积，枚举位置；或者是以深度为搜索对象，相同的深度格子连接起来，这种方法要要考虑一些细节。
*/
int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%d %d %d %d", &a, &b, &m, &n) == 4) {
    ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &d[i][j]);
      }
    }
    
    if (b < a) swap(a, b);
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        memset(dep, 0x3f, sizeof(dep));
        for (int p = i; p < m; p++) {
          int aa = p - i + 1;
          if (aa > b) break;
          for (int q = j; q < n; q++) {
            int bb = q - j + 1;
            if (bb > b || min(aa, bb) > a) break;
            
            dep[q] = min(dep[q], d[p][q]);
            if (q) dep[q] = min(dep[q - 1], dep[q]);
            V = 1ll * aa * bb * dep[q];
            S = 1ll * aa * bb;
            // 设箱子高度x，列出公式求出x
            // (abx / mn + dep[q]) * ab = abx
            // 向下取整
            ans = max(ans, 1ll * (V / (n * m - S) + dep[q] - (V % (n * m - S) == 0)) * S);
          }
        }
      }
    }
    
    printf("%lld\n", ans);
  }
  
  return 0;
}