// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 3;
int T, n, a[N], vis[N];
/**
 * 结论题，直接求逆序对。
 * 长度为L的序列，顺序和逆序的逆序对总数为(L^2-L)/2是显然的，那么每次操作，设初始逆序对数目为x，那么操作完后，
 * 逆序对数目变为6-x，可知奇偶性不变。
 * 如果想把数字1放到位置1，那么1可以在位置2、4，也可以在位置3、5，以此类推，1在任何位置都能变为位置1。
 * 由于操作后逆序对奇偶性不变，那么就要求初始状态的逆序对数量为偶数。
 * 设题目给出序列的长度为n，在第一个位置的数字为k，那么k贡献的逆序对数目为k-1，把k放到序列尾部，k贡献的逆序对数目为n-k，
 * Δ=n-2*k+1。如果n为偶数，则Δ为奇数，说明逆序对的奇偶性可以变化，如果n为奇数则不可以变化。
 * 所以当且仅当n为奇数且逆序对数为奇数时，无法通过操作得出1,2,…,n的序列。
*/
int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  while (T--) {
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      for (int j = n; j > a[i]; j--) {
        if (vis[j]) tot++;
      }
      vis[a[i]] = 1;
    }
    if ((n & 1) && (tot & 1)) puts("impossible");
    else puts("possible");
  }
  
  return 0;
}