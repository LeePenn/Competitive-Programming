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
      // i - L 上一个加入的点，但没有移除上凸点，这里移除
      while (r - l > 1 && compare_average(p[r - 2], i - L, p[r - 1], i - L) >= 0) r--;
      
      p[r++] = i - L + 1;
      
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