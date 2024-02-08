// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
struct Node {
  int l, r, face;
};

Node nodes[N];
int F[N], used[N];
int T, L, P, x, y;

void removeNode(int idx) {
  used[idx] = 1;
  nodes[nodes[idx].r].l = nodes[idx].l;
  nodes[nodes[idx].l].r = nodes[idx].r;
}
/**!SECTION
 * 用结构体模拟了一个圈，l表左边，r表右边，face表重叠，for循环删除没有重叠的边，根据重叠关系模拟即可
 * 此题解法极其经典
*/
int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  cin >> T;
  for (int kase = 1; kase <= T; kase++) {
    cin >> L >> P;
    for (int i = 0; i < L; i++) {
      nodes[i].l = i - 1, nodes[i].r = i + 1, F[i] = 0, used[i] = 0;
    }
    nodes[0].l = L - 1, nodes[L - 1].r = 0;
    
    for (int i = 0; i < P; i++) {
      cin >> x >> y;
      nodes[x].face = y;
      nodes[y].face = x;
      F[x] = 1, F[y] = -1;
    }
    
    int st = 0, listsize = 2 * P;
    for (int i = 0; i < L; i++) {
      if (!F[i]) removeNode(i);
    }
    
    while (listsize) {
      int update = 0;
      while (used[st]) st++;
      // 避免成环无限循环的情况
      for (int i = nodes[st].r; !update && i != st; i = nodes[i].r) {
        int x = i, y = nodes[i].r;
        // passing
        if (F[x] == F[y] && (nodes[nodes[y].face].r == nodes[x].face || nodes[nodes[x].face].r == nodes[y].face)) {
          removeNode(x); removeNode(nodes[x].face); removeNode(y); removeNode(nodes[y].face);
          listsize -= 4, update = 1;
        } else if (nodes[x].face == y) { // self loop
          removeNode(x); removeNode(y);
          listsize -= 2, update = 1;
        }
      }
      if (!update) break;
    }
    
    cout << "Case #" << kase << ": " << (listsize ? "NO" : "YES") << endl;
  }
  
  return 0;
}