#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;
const int UP = 0, LEFT = 1, RIGHT = 2, DOWN = 3, N = 70 + 5;
int dp[N][4][4][3];
int action[N][4][4][3];
char seq[N], pos[256], footch[] = ".LR";
int energy(int a, int ta) {
  if (a == ta) return 3;
  if (a + ta == 3) return 7;
  return 5;
}
// 第i 步，当前左脚在 a，右脚在 b，上一步移动的是 s，当前移动的是 f，目标到 t，当前步走完左脚位置 ta，右脚位置 tb
int energy(int i, int a, int b, int s, int f, int t, int &ta, int &tb) {
  ta = a; tb = b;
  if (f == 1) ta = t;
  else if (f == 2) tb = t;
  
  if (ta == tb) return -1;
  if (ta == RIGHT && tb == LEFT) return -1;
  if (a == RIGHT && tb != b) return -1;
  if (b == LEFT && ta != a) return -1;
  
  int e;
  if (f == 0) e = 0;
  else if (f != s) e = 1;
  else if (f == 1) {
    e = energy(a, ta);
  } else {
    e = energy(b, tb);
  }
  return e;
}
void Update(int i, int a, int b, int s, int f, int t) {
  int ta, tb;
  int e = energy(i, a, b, s, f, t, ta, tb);
  
  if (e < 0) return;
  int cost = dp[i + 1][ta][tb][f] + e;
  int &ans = dp[i][a][b][s];
  if (ans > cost) {
    ans = cost;
    action[i][a][b][s] = f * 4 + t;
  }
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
      
  pos['U'] = 0; pos['L'] = 1; pos['R'] = 2; pos['D'] = 3;
  
  while (scanf("%s", seq) == 1) {
    if (seq[0] == '#') break;
    
    int n = strlen(seq);
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; --i) {
      for (int a = 0; a < 4; ++a) {
        for (int b = 0; b < 4; ++b) if (a != b) {
          for (int s = 0; s < 3; ++s) {
            dp[i][a][b][s] = 10 * n;
            if (seq[i] == '.') {
              Update(i, a, b, s, 0, 0);
              for (int t = 0; t < 4; ++t) {
                Update(i, a, b, s, 1, t);
                Update(i, a, b, s, 2, t);
              }
            } else {
              Update(i, a, b, s, 1, pos[seq[i]]);
              Update(i, a, b, s, 2, pos[seq[i]]);
            }
          }
        }
      }
    }
    
    int a = LEFT, b = RIGHT, s = 0;
    for (int i = 0; i < n; ++i) {
      int f = action[i][a][b][s] / 4;
      int t = action[i][a][b][s] % 4;
      printf("%c", footch[f]);
      s = f;
      if (f == 1) a = t;
      else if (f == 2) b = t;
    }
    printf("\n");
  }
  
  

  return 0;
}