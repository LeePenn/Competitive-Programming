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
const int N = 100 + 4, M = 3000 + 4;
int n, m;
int dp[N][M], p[N][M];
int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
/**!SECTION
 * dp[i][j]对应了一个这样的状态，其中i表示此时还剩下多少火柴，它是考虑剩下还没摆的部分的，
 * j表示已摆数对m的余数，它是考虑已经摆了的部分的（在前例中j就是123对m的余数），
 * 而dp[i][j]表示此时没摆的数最多可能有多少位，需要保证摆完之后能被m整除，它是考虑剩下还没摆的部分。
 * 
 * 对d[i][j]而言，已经写好的部分具体是多少是无所谓的，只需要知道它对m的余数是j，
 * 并且用掉了n-i根火柴。我们关心的是没有写的部分最长位数是多少，那么决策就来了，
 * 没有写的部分的首位只可能是0~9，容易理解，假如最优解里没有写的部分的首位是x，
 * 那么d[i][j]=d[i-k[x]][(10*j+x)%m]+1
*/
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  int kase = 0;
  while (scanf("%d", &n) == 1 && n) {
    scanf("%d", &m);
    kase++;
    
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < m; ++j) {
        int &ans = dp[i][j];
        ans = p[i][j] = -1;
        if (j == 0) ans = 0;
        for (int d = 9; d >= 0; --d) {
          if (cost[d] <= i) {
            int t = dp[i - cost[d]][(j * 10 + d) % m];
            if (t >= 0 && t + 1 > ans) {
              ans = t + 1;
              p[i][j] = d;
            }
          }
        }
      }
    }
    
    printf("Case %d: ", kase);
    if (p[n][0] == -1) {
      printf("-1\n");
      continue;
    } 
    
    int i = n, j = 0;
    for (int d = p[i][j]; d >= 0; d = p[i][j]) {
      printf("%d", d);
      i -= cost[d];
      j = (10 * j + d) % m;
    }
    printf("\n");
  }
  
  

  return 0;
}