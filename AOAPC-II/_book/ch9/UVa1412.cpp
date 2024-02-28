#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;
const double INF = 1e30;
const int N = 8, M = 100 + 4, MAXSTATE = 15000;

int m, n, s[N], k[N], kk;
double c, price[N][M];
char name[N][10];

double dp[M][MAXSTATE];
int opt[M][MAXSTATE], pre[M][MAXSTATE];

int buy_next[MAXSTATE][N], sell_next[MAXSTATE][N];
vector<vector<int> > states;
map<vector<int>, int> ID;
// create id map
void dfs(int stock, vector<int> &lots, int totlot) {
    if (stock == n) {
        ID[lots] = states.size();
        states.push_back(lots);
        return;
    }
    
    for (int i = 0; i <= k[stock] && totlot + i <= kk; ++i) {
        lots[stock] = i;
        dfs(stock + 1, lots, totlot + i);
    }
}
// create DAG
void Init() {
  vector<int> lots(n);
  states.clear();
  ID.clear();
  dfs(0, lots, 0);
  for (int s = 0; s < states.size(); ++s) {
    int totlot = 0;
    for (int i = 0; i < n; ++i) totlot += states[s][i];
    for (int i = 0; i < n; ++i) {
        buy_next[s][i] = sell_next[s][i] = -1;
        if (states[s][i] < k[i] && totlot < kk) {
            vector<int> newstate = states[s];
            newstate[i]++;
            buy_next[s][i] = ID[newstate];
        }
        if (states[s][i] > 0) {
            vector<int> newstate = states[s];
            newstate[i]--;
            sell_next[s][i] = ID[newstate];
        }
    }
  }
}
void Update(int day, int s, int s2, double v, int o) {
    if (v > dp[day + 1][s2]) {
        dp[day + 1][s2] = v;
        opt[day + 1][s2] = o;
        pre[day + 1][s2] = s;
    }
}
double DP() {
    for (int day = 0; day <= m; ++day) {
        for (int s = 0; s < states.size(); ++s) {
            dp[day][s] = -INF;
        }
    }
    
    dp[0][0] = c;
    for (int day = 0; day < m; ++day) {
        for (int s = 0; s < states.size(); ++s) {
            double v = dp[day][s];
            if (v < -1) continue;
            
            Update(day, s, s, v, 0);
            for (int i = 0; i < n; ++i) {
                if (buy_next[s][i] >= 0) {
                    Update(day, s, buy_next[s][i], v - price[i][day], i + 1);
                }
                if (sell_next[s][i] >= 0) {
                    Update(day, s, sell_next[s][i], v + price[i][day], -i - 1);
                }
            }
        }
    }
    return dp[m][0];
}
void Print_ans(int day, int s) {
    if (day == 0) return;
    
    Print_ans(day - 1, pre[day][s]);
    if (opt[day][s] == 0) {
        printf("HOLD\n");
    } else if (opt[day][s] > 0) printf("BUY %s\n", name[opt[day][s] - 1]);
    else printf("SELL %s\n", name[-opt[day][s] - 1]);
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
      
  int kase = 0;
  while (scanf("%lf%d%d%d", &c, &m, &n, &kk) == 4) {
    if (kase++ > 0) printf("\n");
    
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d", name[i], &s[i], &k[i]);
        for (int j = 0; j < m; ++j) {
            scanf("%lf", &price[i][j]);
            price[i][j] *= s[i];
        }
    }
    
    Init();
    double ans = DP();
    printf("%.2lf\n", ans);
    Print_ans(m, 0);
  }
  

  return 0;
}