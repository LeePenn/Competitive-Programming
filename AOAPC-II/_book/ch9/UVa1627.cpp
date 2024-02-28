#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;
const int N = 100 + 4;

int n, g[N][N];
int cc;
vector<int> team[N][2];
int color[N];

bool dfs(int u, int c) {
    color[u] = c;
    team[cc][c].push_back(u);
    for (int v = 0; v < n; ++v) {
        if (u == v) continue;
        
        if (!(g[u][v] && g[v][u])) {
            if (color[v] == -1 && !dfs(v, 1 - c)) return false;
            if (color[v] != -1 && color[v] == c) return false;
        }
    }
    
    return true;
}

int diff[N];
bool build_graph() {
    cc = 0;
    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            team[cc][0].clear();
            team[cc][1].clear();
            if (!dfs(i, 0)) return false;
            diff[cc] = team[cc][0].size() - team[cc][1].size();
            cc++;
        } 
    }
    return true;
}
int dp[N][N << 1];
void print_ans(int ans) {
    vector<int> team1, team2;
    int t = 0;
    
    for (int i = cc - 1; i >= 0; --i) {
        if (dp[i][ans - diff[i] + n]) {
            t = 0;
            ans -= diff[i];
        } else {
            t = 1;
            ans += diff[i];
        }
        
        for (size_t j = 0; j < team[i][t].size(); ++j) {
            team1.push_back(team[i][t][j]);
        }
        for (size_t j = 0; j < team[i][t ^ 1].size(); ++j) {
            team2.push_back(team[i][t ^ 1][j]);
        }
    }
    
    printf("%d", team1.size());
    for (size_t i = 0; i < team1.size(); ++i) {
        printf(" %d", team1[i] + 1);
    }
    printf("\n");
    
    printf("%d", team2.size());
    for (size_t i = 0; i < team2.size(); ++i) {
        printf(" %d", team2[i] + 1);
    }
    printf("\n");
}
void DP() {
    memset(dp, 0, sizeof(dp));
    dp[0][n] = 1;
    
    for (int i = 0; i < cc; ++i) {
        for (int j = -n; j <= n; ++j) {
            if (!dp[i][j + n]) continue;
            
            dp[i + 1][j + diff[i] + n] = 1;
            dp[i + 1][j - diff[i] + n] = 1;
        }
    }
    
    for (int ans = 0; ans <= n; ++ans) {
        if (dp[cc][ans + n]) {
            print_ans(ans);
            return;
        } 
        if (dp[cc][-ans + n]) {
            print_ans(-ans);
            return;
        }
    }
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
      
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d", &n);
    int v;
    memset(g, 0, sizeof(g));
    for (int i = 0; i < n; ++i) {
        while (scanf("%d", &v) == 1 && v) {
            g[i][v - 1] = 1;
        }
    }
    
    if (n == 1 || !build_graph()) printf("No solution\n");
    else {
        DP();
    }
    if (kase) printf("\n");
    
  }
  
  
  
  

  return 0;
}