// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t, n, m;
/**
 * 给出n*m个格子，每个格子里有一个机器人，可以执行东南西北四种指令，但是移动出格就会爆炸。给出四种指令的个数，
 * 求最多完成多少次指令。
 * 首先对输入数据进行处理，使得cw≥ce、cn≥cs且先执行东西方向的来回移动比先执行南北方向来回移动更佳。
 * 然后执行东西移动，再用类似于UVa-1610 Party Game的排序方法，对比每次向西移动还是开始南北移动更好。
 * 当仅剩西和北两个方向后，模拟至结束。每个样例的复杂度为O(n)。
*/
int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  t = 0;
  while (cin >> n >> m && (n || m)) {
    ll cn, cs, cw, ce, ans = 0;
    cin >> cn >> cs >> cw >> ce;
    if (cn < cs) swap(cn, cs);
    if (cw < ce) swap(cw, ce);
    // 只是判断是否需要交换
    ll t1 = n + (m - 1) * n * ce * 2 + (m - 1) + (m - 1) * (n - 1) * cs * 2, 
       t2 = m + m * (n - 1) * cs * 2 + (n - 1) + (m - 1) * (n - 1) * ce * 2;
    if (cw - ce) t1 += (m - 1) * n, t2 += (m - 1) * (n - 1);
    if (cn - cs) t1 += (m - 1) * (n - 1), t2 += (n - 1) * m;
    if (t1 < t2) swap(n, m), swap(cn, cw), swap(cs, ce);
    
    // 判断是否m已经--
    bool flag = true;
    if (ce) {
      ans += n + (m - 1) * n * ce * 2;
      cw -= ce, ce = 0, m--;
      flag = false;
    } 
    if (cw) {
      ans += m * n;
      cw--;
      if (flag) m--;
    }
    
    cw = min(m, cw);
    while (cw || cn) {
      if (cs) {
        ll t1 = m * n + (n - 1) * m * 2 * cs, // ns来回移动，再w移动
           t2 = m * n + (m - 1) * n + (m - 1) * (n - 1) * (2 * cs - 1); // 先w移动，再ns来回移动
        if (cn - cs) {
          t1 = m * n + (n - 1) * m * (2 * cs + 1);
          t2 = m * n + (m - 1) * n + (m - 1) * (n - 1) * 2 * cs;
        }
        if (t1 > t2 || !cw) {
          ans += m + m * (n - 1) * cs * 2;
          cn -= cs, cs = 0, n--;
          if (cn) ans += m * n, cn--;
          cn = min(n, cn);
        } else {
          ans += m * n;
          m--;
          cw--;
        }
      } else if (!cw) ans += m * cn * (2 * n - cn + 1) / 2, cn = 0;
      else if (!cn) ans += n * cw * (2 * m - cw + 1) / 2, cw = 0;
      else {
        ans += m * n;
        if (m > n) m--, cw--;
        else n--, cn--;
      }
      
    }
    
    cout << "Case " << ++t << ": " << ans << endl;
  }
  
  return 0;
}