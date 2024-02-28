// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 20 + 1, UNITS = 5, T = 10;
int n, S[UNITS][T * N];
int Task[N];
int Ans[T + 1];
vector<int> Dist;

void put(int clock) {
  for (int i = 0; i < n; i++) 
    S[Task[i]][clock + i] = 1;
}

void Remove(int clock) {
  for (int i = 0; i < n; i++) 
    S[Task[i]][clock + i] = 0;
}

bool canPut(int clock) {
  for (int i = 0; i < n; i++) {
    if (S[Task[i]][clock + i]) return false;
  }
  return true;
}

void dfs(int t, int T, int clock, int& ans) {
  if (t == T) {
    ans = min(ans, clock + n);
    return;
  }
  
  for (const auto& d : Dist) {
    int c = d + clock;
    if (c + Ans[T - t] >= ans) return;
    if (!canPut(c)) continue;
    put(c);
    dfs(t + 1, T, c, ans);
    Remove(c);
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  char line[64];
  while (scanf("%d", &n) == 1 && n) {
    memset(S, 0, sizeof(S));
    memset(Task, 0, sizeof(Task));
    memset(Ans, 0, sizeof(Ans));
    Dist.clear();
    for (int i = 0; i < UNITS; i++) {
      scanf("%s", line);
      for (int j = 0; j < n; j++) {
        if (line[j] == 'X') Task[j] = i;
      }
    }
    
    put(0);
    // 距离第一个放的位置后，多少距离放不会冲突
    for (int i = 1; i <= n; i++) if (canPut(i)) Dist.push_back(i);
    
    Ans[1] = n;
    for (int i = 1; i <= T; i++) {
      Ans[i] = i * n;
      dfs(1, i, 0, Ans[i]);
    }
    
    printf("%d\n", Ans[T]);
  }
  
  
  
  return 0;
}