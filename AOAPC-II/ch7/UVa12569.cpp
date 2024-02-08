// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 16;
vector<int> G[N];
int T, n, m, s, t;
int dist[1 << (N + 4)];
int preState[1 << (N + 4)];
unordered_set<int> vis;
vector<int> stoneLoc[1 << N];

bool bfs(int startState, int& lastState, int& ans) {
  memset(dist, -1, sizeof(dist));
  dist[startState] = 0;
  memset(preState, -1, sizeof(preState));
  preState[startState] = 0;
  vis.clear();
  vis.insert(startState);
  queue<int> q;
  q.push(startState);
  //cout << "t = " << t << endl;
  while (q.size()) {
    int curState = q.front(); q.pop();
    int robot = curState & 0xf, stones = curState >> 4;
    //cout << robot << ' ' << stones << endl;
    int curDist = dist[curState];
    if (robot == t) { lastState = curState; ans = curDist; return true; }
    // robot move
    for (const auto& v : G[robot]) {
      //cout << "robot: " << v << endl;
      if (stones & (1 << v)) continue; // block
      int nxtState = v | (stones << 4);
      if (vis.count(nxtState)) continue;
      //cout << nxtState << endl;
      vis.insert(nxtState);
      preState[nxtState] = curState;
      dist[nxtState] = curDist + 1;
      q.push(nxtState);
    }
    
    // stone move
    for (const auto& st : stoneLoc[stones]) {
      //cout << "stone: " << st << endl;
      for (const auto& v : G[st]) {
        if (robot == v) continue; // blocked by robot
        if (stones & (1 << v)) continue; // blocked by stone
        int nxtState = (curState ^ (1 << (st + 4))) | (1 << (v + 4));
        if (vis.count(nxtState)) continue;
        //cout << v << ' ' << nxtState << endl;
        vis.insert(nxtState);
        preState[nxtState] = curState;
        dist[nxtState] = curDist + 1;
        q.push(nxtState);
      }
    }
  }
  return false;
} 

void printPath(int lastState) {
  if (preState[lastState] == 0) return;
  int nxtState = preState[lastState];
  printPath(nxtState);
  int robot1 = nxtState & 0xf, robot2 = lastState & 0xf;
  // robot move
  if (robot1 != robot2) {
    printf("%d %d\n", robot1 + 1, robot2 + 1);
  } else {
    int stone1 = nxtState >> 4, stone2 = lastState >> 4;
    int loc1, loc2;
    for (int i = 0; i < N; i++) {
      int t1 = stone1 >> i & 1, t2 = stone2 >> i & 1;
      if (t1 != t2 && t1 == 1) loc1 = i;
      else if (t1 != t2 && t2 == 1) loc2 = i;
    }
    printf("%d %d\n", loc1 + 1, loc2 + 1);
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int bin = 0; bin < (1 << N); bin++) {
    for (int loc = 0; loc < N; loc++) {
      if (bin >> loc & 1) stoneLoc[bin].push_back(loc);
    }
  }
  //cout << stoneLoc[2][0] << endl;
  
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 0; i < n; i++) G[i].clear();
    s--, t--;
    int state = s;
    for (int i = 1; i <= m; i++) {
      int x; scanf("%d", &x); x--;
      state |= (1 << (x + 4));
    }
    //cout << state << endl;
    for (int i = 1; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y); x--, y--;
      G[x].push_back(y); G[y].push_back(x);
    }
    
    
    int lastState = -1, minDist;
    if (kase > 1) puts("");
    if (!bfs(state, lastState, minDist)) printf("Case %d: -1\n", kase);
    else {
      printf("Case %d: %d\n", kase, minDist);
      printPath(lastState);
    }
    
  }
  
  
  return 0;
}