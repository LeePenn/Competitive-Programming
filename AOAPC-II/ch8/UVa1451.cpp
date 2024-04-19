// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 3;
int T, n, L;
char s[N];
int sum[N], p[N];

int compare_average(int x1, int x2, int x3, int x4) {
  return (sum[x2] - sum[x1 - 1]) * (x4 - x3 + 1) - (sum[x4] - sum[x3 - 1]) * (x2 - x1 + 1);
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %s", &n, &L, s + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + (s[i] - '0');
    }
    
    int ansL = 1, ansR = L;
    int l = 0, r = 0;
    for (int i = L; i <= n; i++) {
      // i - L 当前要加入的点，即书中的 t‘，这里移除加入后可能出现的上凸点
      while (r - l > 1 && compare_average(p[r - 2], i - L, p[r - 1], i - L) >= 0) r--;
      // 第一个加入的点会是 1，随 i 增加，不会漏点
      p[r++] = i - L + 1;
      
      // 数形结合，随着加入的点增多，斜率只会越来越大
      while (r - l > 1 && compare_average(p[l], i, p[l + 1], i) <= 0) l++;
      
      int c = compare_average(p[l], i, ansL, ansR);
      if (c > 0 || (c == 0 && i - p[l] < ansR - ansL)) {
        ansL = p[l], ansR = i;
      }
    }
    
    printf("%d %d\n", ansL, ansR);
  }
  
  return 0;
}