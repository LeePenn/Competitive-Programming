// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 300 + 3;
int n;


int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  // 等价思考，输入序列有序，正常有序序列无序，从值比较->索引比较（映射比较）
  string ans;
  deque<int> A, T;
  int L[N];
  while (scanf("%d", &n) == 1 && n) {
    ans.clear(), A.resize(n, 0), T.resize(n, 0); 
    for (int i = 1; i <= n; i++) {
      A[i - 1] = i;
      scanf("%d", &T[i - 1]);
      L[T[i - 1]] = i;
    }
    
    while (A != T) {
      int a0 = A[0], a1 = A[1], l0 = L[a0], l1 = L[a1];
      if (l0 < l1 || (l0 == n && l1 == 1)) {
        ans += '2';
        A.push_back(A.front()); A.pop_front();
      } else {
        ans += '1';
        swap(A[0], A[1]);
      }
    }
    cout << ans << endl;
  }
  
  
  return 0;
}