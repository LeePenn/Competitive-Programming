#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
const int N = 200 + 5;
int n;
unordered_map<string, int> mp;
struct Edge {
    int u, v, to;
}e[N << 1];
int ID;
int tot, hd[N];
int dp[N][2], f[N][2];

int getID(const string &s) {
    if (mp.count(s)) return mp[s];
    mp[s] = ++ID;
    return mp[s];
}

void add_edge(int u, int v) {
    e[++tot] = Edge{u, v, hd[u]};
    hd[u] = tot;
}

void DP(int u, int p) {
    f[u][0] = f[u][1] = 1;
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (int i = hd[u]; i; i = e[i].to) {
        int v = e[i].v;
        if (v == p) continue;
        
        DP(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
        if (f[v][0] == 0) f[u][1] = 0;
        if (dp[v][0] == dp[v][1]) f[u][0] = 0;
        if (dp[v][0] > dp[v][1] && f[v][0] == 0) f[u][0] = 0;
        if (dp[v][1] > dp[v][0] && f[v][1] == 0) f[u][0] = 0;
    }
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
    
  string s, s1;
  while (cin >> n && n) {
    ID = 0;
    mp.clear();
    tot = 0;
    memset(dp, 0, sizeof(0));
    memset(hd, 0, sizeof(hd));
    memset(f, -1, sizeof(f));
    cin >> s;
    getID(s);
    
    for (int i = 1; i < n; ++i) {
        cin >> s >> s1;
        int u = getID(s), v = getID(s1);
        add_edge(u, v); add_edge(v, u);
    }
    
    DP(1, -1);
    cout << max(dp[1][0], dp[1][1]);
    bool uniq = 0;
    if (dp[1][0] > dp[1][1] && f[1][0]) {
        uniq = 1;
    } else if (dp[1][0] < dp[1][1] && f[1][1]) {
        uniq = 1;
    } 
    if (uniq) cout << " Yes" << endl;
    else cout << " No" << endl;
  }


  return 0;
}