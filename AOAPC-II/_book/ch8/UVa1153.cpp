// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 800000 + 3;

struct Order {
  int st, ed;
  Order(int st = 0, int ed = 0):st(st), ed(ed) {}
} orders[N];

struct order_cmp {
  bool operator () (const Order& o1, const Order& o2) {
    return o1.ed < o2.ed;
  }
};

int T, n;

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    if (t) puts("");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", &orders[i].st, &orders[i].ed);
    }
    
    sort(orders + 1, orders + n + 1, order_cmp());
    
    int prev = 0;
    priority_queue<int> heap;
    for (int i = 1; i <= n; i++) {
      if (prev + orders[i].st <= orders[i].ed) {
        prev += orders[i].st;
        heap.push(orders[i].st);
      } else if (!heap.empty() && heap.top() > orders[i].st) {
        prev = prev - heap.top() + orders[i].st;
        heap.pop();
        heap.push(orders[i].st);
      }
    }
    printf("%lu\n", heap.size());
  }
  
  
  return 0;
}