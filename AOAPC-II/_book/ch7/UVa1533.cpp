// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 15, D = 6;
const int DIRS[N + 1][D] = {
  {0,0,0,0,0,0 },
  {0,0,0,0,2,3 }, // 1 
  {0,1,0,3,4,5 }, // 2
  {1,0,2,0,5,6 }, // 3
  {0,2,0,5,7,8 }, // 4
  {2,3,4,6,8,9 }, // 5
  {3,0,5,0,9,10 }, // 6
  {0,4,0,8,11,12 }, // 7
  {4,5,7,9,12,13 }, // 8
  {5,6,8,10,13,14 }, // 9
  {6,0,9,0,14,15 }, // 10
  {0,7,0,12,0,0 }, // 11
  {7,8,11,13,0,0 }, // 12
  {8,9,12,14,0,0 }, // 13
  {9,10,13,15,0,0 }, // 14
  {10,0,14,0,0,0 } // 15
};
int T, n;
int vis[1 << N], dist[1 << N], preState[1 << N], movement[1 << N]; // low 4 bits move to high 4bits
vector<int> pegsLoc[1 << N];

bool check(int state) {
  
  if ((state >> (n - 1) & 1) == 0) return false;
  int cnt = 0;
  while (state) {
    state -= state & -state;
    cnt++;
    if (cnt > 1) return false;
  }
  return true;
}

bool tryMove(int num, int dir, int& slot, int& state) {
  vector<int> remove_pegs;
  remove_pegs.push_back(num);
  int cnt = 1;
  slot = -1;
  while (DIRS[num][dir]) {
    num = DIRS[num][dir];
    if (state >> (num - 1) & 1) {
      remove_pegs.push_back(num);
      cnt++; 
    } else { slot = num; break; }
  }
  if (cnt > 1 && slot != -1) {
    state ^= (1 << (slot - 1));
    for (const auto& v : remove_pegs) {
      state ^= (1 << (v - 1));
    }
    return true;
  } else return false;
}

bool bfs(int& lastState, int& ans) {
  
  memset(vis, 0, sizeof(vis));
  memset(dist, -1, sizeof(dist));
  memset(preState, 0, sizeof(preState));
  memset(movement, 0, sizeof(movement));
  int st = ((1 << N) - 1) ^ (1 << (n - 1));
  vis[st] = 1;
  dist[st] = 0;
  queue<int> q;
  q.push(st); 
  
  while (q.size()) {
    int curState = q.front(); q.pop();
    int curDist = dist[curState];
    if (check(curState)) {
      lastState = curState;
      ans = curDist;
      return true;
    }
    
    for (const auto& num : pegsLoc[curState]) {
      for (int dir = 0; dir < 6; dir++) {
        int nxt = curState, slot;
        
        if (tryMove(num, dir, slot, nxt)) {
          if (vis[nxt]) continue;
          vis[nxt] = 1;
          dist[nxt] = curDist + 1;
          preState[nxt] = curState;
          movement[nxt] = num | (slot << 4);
          q.push(nxt);
        }
      }
    }
    
  }
  
  return false;
}

void save_move(int state, vector<int>& mv) {
  if (preState[state] == 0) return;
  
  save_move(preState[state], mv);
  mv.push_back(movement[state]);
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int bin = 1; bin < (1 << N); bin++) {
    for (int i = 0; i < N; i++) {
      if (bin >> i & 1) pegsLoc[bin].push_back(i + 1);
    }
  }
  
  
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int lastState, ans;
    if (bfs(lastState, ans)) {
      printf("%d\n", ans);
      vector<int> mv;
      save_move(lastState, mv);
      for (int i = 0; i < mv.size(); i++) {
        int m1 = mv[i] & 0xf, m2 = (mv[i] >> 4) & 0xf;
        if (!i) printf("%d %d", m1, m2);
        else printf(" %d %d", m1, m2);
      }
      printf("\n");
    }
  }
  
  
  return 0;
}