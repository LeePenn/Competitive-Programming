#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>

#define LL long long
using namespace std;
const int N = 200 + 5, INF = 1e9;
struct Edge {
    int u, v, d;
    Edge(int u = 0, int v = 0, int d = 0):u(u), v(v), d(d) {}
};
vector<Edge> edges[N];
int n, root, maxlen, f[N], g[N], have_father[N];

int dfs(int u) {
    int ans = 0;
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i].v;
        if (edges[u][i].d == 1) ans = max(ans, dfs(v) + 1);
    }
    
    return ans;
}
bool read_data() {
    bool have_data = false;
    int a, b;
    n = 0;
    for (int i = 0; i < N; ++i) edges[i].clear();
    memset(have_father, 0, sizeof(have_father));
    
    while (cin >> a && a) {
        string str;
        have_data = true;
        if (a > n) n = a;
        while (cin >> str && str != "0") {
            int len = str.length();
            char dir = str[len - 1];
            if (dir == 'd' || dir == 'u') str = str.substr(0, len - 1);
            stringstream ss(str);
            ss >> b;
            if (b > n) n = b;
            have_father[b] = 1;
            if (dir == 'd') {
                edges[a].push_back(Edge(a, b, 1));
                edges[b].push_back(Edge(b, a, 2));
            } else if (dir == 'u') {
                edges[a].push_back(Edge(a, b, 2));
                edges[b].push_back(Edge(b, a, 1));
            } else {
                edges[a].push_back(Edge(a, b, 0));
            }
        }
    }
    if (have_data) {
        for (int i = 1; i <= n; ++i) {
            if (!have_father[i] && !edges[i].empty()) {
                root = i;
                break;
            }
        }
    }
    return have_data;
}
struct UndirectedSon {
    int w, f, g;
    UndirectedSon(int w = 0, int f = 0, int g = 0):w(w), f(f), g(g) {}
};
bool cmp_f(const UndirectedSon &w1, const UndirectedSon &w2) {
    return w1.f < w2.f;
}
bool cmp_g(const UndirectedSon &w1, const UndirectedSon &w2) {
    return w1.g < w2.g;
}
bool dp(int i, int fa) {
    if (edges[i].empty()) {
        f[i] = g[i] = 0;
        return true;
    }
    vector<UndirectedSon> sons;
    int f0 = 0, g0 = 0;
    for (int k = 0; k < edges[i].size(); ++k) {
        int w = edges[i][k].v;
        if (w == fa) continue;
        dp(w, i);
        int d = edges[i][k].d;
        if (d == 0) sons.push_back(UndirectedSon(w, f[w], g[w]));
        else if (d == 1) g0 = max(g0, g[w] + 1);
        else f0 = max(f0, f[w] + 1);
    }
    if (sons.empty()) {
        f[i] = f0; g[i] = g0;
        if (f[i] + g[i] > maxlen) f[i] = g[i] = INF;
        return f[i] < INF;
    }
    
    f[i] = g[i] = INF;
    int s = sons.size();
    sort(sons.begin(), sons.end(), cmp_f);
    int maxg[N];
    maxg[s - 1] = sons[s - 1].g;
    for (int k = s - 2; k >= 0; --k) {
        maxg[k] = max(sons[k].g, maxg[k + 1]);
    }
    // 前 p 个改为 w -> i
    for (int p = 0; p <= sons.size(); ++p) {
        int ff = f0, gg = g0;
        // p 修改为 w -> i
        if (p > 0) ff = max(ff, sons[p - 1].f + 1);
        if (p < sons.size()) gg = max(gg, maxg[p] + 1);
        if (ff + gg <= maxlen) f[i] = min(f[i], ff);
    }
    
    sort(sons.begin(), sons.end(), cmp_g);
    int maxf[N];
    maxf[s - 1] = sons[s - 1].f;
    for (int k = s - 2; k >= 0; --k) {
        maxf[k] = max(sons[k].f, maxf[k + 1]);
    }
    for (int p = 0; p <= sons.size(); ++p) {
        int ff = f0, gg = g0;
        if (p > 0) gg = max(gg, sons[p - 1].g + 1);
        if (p < sons.size()) ff = max(ff, maxf[p] + 1);
        if (ff + gg <= maxlen) g[i] = min(g[i], gg);
    }
    return f[i] < INF;
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (read_data()) {
    maxlen = 0;
    for (int i = 1; i <= n; ++i) maxlen = max(maxlen, dfs(i));
    if (dp(root, -1)) cout << maxlen + 1 << endl;
    else cout << maxlen + 2 << endl;
  }
  

  return 0;
}